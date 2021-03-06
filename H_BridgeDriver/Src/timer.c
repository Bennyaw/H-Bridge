#include "timer.h"
#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include <math.h>
#include "RCCstm32f1.h"
#include "dma.h"

extern TIM_HandleTypeDef htim1;
extern uint16_t bufferCCR1[2];
extern uint16_t bufferCCR2[2];
extern uint16_t bufferCCR3[2];
double offset;
int edgeIntervalChn1;
int edgeIntervalChn3;

/*Read rising edge and falling edge value*/
#define getChn1RiseEdge()	bufferCCR1[1]
#define getChn1FallEdge()	bufferCCR1[0]

#define getChn2RiseEdge()	bufferCCR2[1]
#define getChn2FallEdge()	bufferCCR2[0]

#define getChn3RiseEdge()	bufferCCR3[1]
#define getChn3FallEdge()	bufferCCR3[0]

/*Set rising edge and falling edge value*/
#define setChn1RiseEdge(val)	bufferCCR1[1]=val
#define setChn1FallEdge(val)	bufferCCR1[0]=val

#define setChn2RiseEdge(val)	bufferCCR2[1]=val
#define setChn2FallEdge(val)	bufferCCR2[0]=val

#define setChn3RiseEdge(val)	bufferCCR3[1]=val
#define setChn3FallEdge(val)	bufferCCR3[0]=val

void timer_Init(void){

	htim1.Instance->CR1 |= arr_preload_en;
	clearTimerUIF(htim1);
	setARRValue(0);
	setPrescalerValue(1);


	htim1.Instance->CCMR1 |= TOGGLE<<4;
	htim1.Instance->CCMR2 |= TOGGLE<<4;
}

void setTimerCCRVal(TIM_HandleTypeDef *timer,uint32_t channel,uint32_t outputCompareVal){

	if(channel == 1)
		timer->Instance->CCR1 = outputCompareVal;
	else if(channel == 2)
		timer->Instance->CCR2 = outputCompareVal;
	else if(channel == 3)
		timer->Instance->CCR3 = outputCompareVal;
	else if(channel == 4)
		timer->Instance->CCR4 = outputCompareVal;

}

int getApb2_divider(void){
	int divider;
	uint8_t divValue = (Rcc->Cfgr & apb2dividerMask)>>11;
	switch(divValue){
		case 0:
		case 1:
		case 2:
		case 3: divider = 1;
		break;
		case 4: divider = 2;
		break;
		case 5: divider = 4;
		break;
		case 6:divider = 8;
		break;
		case 7:divider = 16;
		break;
		default: divider = 0;
	};

	return divider;
}

float apb2_clk_int_period(void){
	float period;
	int apb2divider = getApb2_divider();
	if(apb2divider==1)//apb2 freq is not divided
		period = ((float)1/(float)HAL_RCC_GetPCLK2Freq())*(float)(pow(10,9));
	else
		period = ((float)1/(float)(HAL_RCC_GetPCLK2Freq()*2))*(float)(pow(10,9));
	return period;
}

int getdtgMultiplier(uint32_t deadTime_ns , float period_clk_base){

	uint8_t dtg7to5;

	uint16_t range1_period=period_clk_base*periodMultiplier_1;
	uint16_t range2_period=period_clk_base*periodMultiplier_2;
	uint16_t range3_period=period_clk_base*periodMultiplier_8;
	uint16_t range4_period=period_clk_base*periodMultiplier_16;

	if((deadTime_ns >0) && (deadTime_ns<= 127*range1_period + range1_period-1))
		dtg7to5 = 0<<7;
	else if((deadTime_ns >=64*range2_period) && (deadTime_ns <=127* range2_period + range2_period-1))
		dtg7to5 = 2<<6;
	else if((deadTime_ns >=32*range3_period) && (deadTime_ns <=63* range3_period+range3_period-1))
		dtg7to5 = 6<<5;
	else if((deadTime_ns >=32*range4_period) && (deadTime_ns <=63* range4_period+range4_period-1))
		dtg7to5 = 7<<5;
	else
		dtg7to5 = 7<<5;

	return dtg7to5;
}

int getdtgBitsVal(uint32_t deadTime_ns , float period_clk_base){

	uint8_t dtgVal;

	uint16_t range1_period=period_clk_base*periodMultiplier_1;
	uint16_t range2_period=period_clk_base*periodMultiplier_2;
	uint16_t range3_period=period_clk_base*periodMultiplier_8;
	uint16_t range4_period=period_clk_base*periodMultiplier_16;

	if((deadTime_ns >0) && (deadTime_ns<= 127*range1_period + range1_period-1))
		dtgVal = (deadTime_ns/range1_period) ;
	else if((deadTime_ns >=64*range2_period) && (deadTime_ns <=127* range2_period + range2_period-1))
		dtgVal = ((deadTime_ns/range2_period)-64) ;
	else if((deadTime_ns >=32*range3_period) && (deadTime_ns <=63* range3_period+range3_period-1))
		dtgVal = ((deadTime_ns/range3_period)-32) ;
	else if((deadTime_ns >=32*range4_period) && (deadTime_ns <=63* range4_period+range4_period-1))
		dtgVal = ((deadTime_ns/range4_period)-32) ;
	else
		dtgVal = 0x1F;

	return dtgVal;
}


void setDeadTime_ns(uint32_t deadTime_ns){
	float period_clk_base = apb2_clk_int_period();

	uint8_t dtgMultiplier = (uint8_t)getdtgMultiplier(deadTime_ns,period_clk_base);
	uint8_t dtgVal = (uint8_t)getdtgBitsVal(deadTime_ns , period_clk_base);

	htim1.Instance->BDTR |= dtgMultiplier|dtgVal;

}
/**
 * This function initialize the duty cycle to 50%, which ccr = arr/2
 * */
void dutyCycleInit(TIM_HandleTypeDef *timer,uint32_t channel,uint16_t arr_val){
	setTimerCCRVal(timer,channel,arr_val/2);
};


void setTimerOutputFrequency_Hz(float out_freq_Hz){
	uint16_t arrVal=0;
	uint16_t prescaler=getPrescalerValue();
	do{
		float prescaled_pclk2_period = apb2_clk_int_period()*prescaler;
		float outFreq_period = (float)1/out_freq_Hz;
		float pclk2_period_ns = prescaled_pclk2_period*((float)1/(float)(pow(10,9)));
		arrVal = outFreq_period/pclk2_period_ns;
		if(arrVal<=0 || arrVal<200 )
			setPrescalerValue(prescaler--);
	}while(arrVal<=0 || arrVal<200);

	setARRValue(arrVal);
}

void setBufferValChn1(int riseEdge,int fallEdge){
	setChn1RiseEdge(riseEdge);
	setChn1FallEdge(fallEdge);
}

void setBufferValChn2(int riseEdge,int fallEdge){
	setChn2RiseEdge(riseEdge);
	setChn2FallEdge(fallEdge);
}

void setBufferValChn3(int riseEdge,int fallEdge){
	setChn3RiseEdge(riseEdge);
	setChn3FallEdge(fallEdge);
}

void setTimer1Chn1_OutputDutyCycle(volatile double dutyCycle_percent){
	int riseEdge,fallEdge;
	volatile int arrVal = getARRValue();
	edgeIntervalChn1= (dutyCycle_percent/100)*arrVal;//minimum 5% duty cycle
	riseEdge = (arrVal*0.05);
	fallEdge = riseEdge+edgeIntervalChn1;
	setBufferValChn1(riseEdge,fallEdge);
}

void setTimer1Chn2_OutputDutyCycle(volatile double dutyCycle_percent){
	int riseEdge,fallEdge;
	volatile int arrVal = getARRValue();
	edgeIntervalChn1= (dutyCycle_percent/100)*arrVal;
	riseEdge = (arrVal*0.05);//minimum 5% duty cycle
	fallEdge = riseEdge+edgeIntervalChn1;
	setBufferValChn2(riseEdge,fallEdge);
}

void setTimer1Chn3_OutputDutyCycle(volatile double dutyCycle_percent){
	int riseEdge,fallEdge;
	volatile int arrVal = getARRValue();
	edgeIntervalChn3= (dutyCycle_percent/100)*arrVal;
	riseEdge = (arrVal*0.05);//minimum 5% duty cycle
	fallEdge = riseEdge+edgeIntervalChn3;
	setBufferValChn3(riseEdge,fallEdge);
}

void setOffSet_Chn3(volatile double offset_percent){
	uint32_t offsetVal = (offset_percent/100)*edgeIntervalChn1;
	uint16_t riseVal = getChn3RiseEdge();
	uint16_t fallVal = getChn3FallEdge();
	setBufferValChn3((riseVal+offsetVal),(fallVal+offsetVal));
}

void setOffSet_Chn2(volatile double offset_percent){
	uint32_t offsetVal = (offset_percent/100)*edgeIntervalChn1;
	uint16_t riseVal = getChn3RiseEdge();
	uint16_t fallVal = getChn3FallEdge();
	setBufferValChn2((riseVal+offsetVal),(fallVal+offsetVal));
}
