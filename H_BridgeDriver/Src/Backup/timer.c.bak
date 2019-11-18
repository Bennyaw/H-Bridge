#include "timer.h"
#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include <math.h>



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

float apb2_clk_int_period(void){
	float period;
	if(IS_RCC_PCLK(RCC_CFGR_PPRE2_DIV1))//apb2 freq is not divided
		period = ((float)1/(float)HAL_RCC_GetPCLK2Freq())*(float)(pow(10,9));
	else
		period = ((float)1/(float)(HAL_RCC_GetPCLK2Freq()*2))*(float)(pow(10,9));
	return period;
}

int getdtgMultiplier(uint32_t deadTime_ns , int period_clk_base){

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

int getdtgBitsVal(uint32_t deadTime_ns , int period_clk_base){

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


int setDeadTime(uint32_t deadTime_ns){
	float period_clk_base = apb2_clk_int_period();

	uint8_t dtgMultiplier = (uint8_t)getdtgMultiplier(deadTime_ns,period_clk_base);
	uint8_t dtgVal = (uint8_t)getdtgBitsVal(deadTime_ns , period_clk_base);

	return  dtgMultiplier|dtgVal;
}
/**
 * This function initialize the duty cycle to 50%, which ccr = arr/2
 * */
void dutyCycleInit(TIM_HandleTypeDef *timer,uint32_t channel,uint16_t arr_val){
	setTimerCCRVal(timer,channel,arr_val/2);
};


void setCHN1DutyCycle(TIM_TypeDef *timer,dutyCycle dutyCycle,uint8_t dutyCycle_percent){

	uint16_t arr_val = timer->ARR;
	uint32_t outPeriod = arr_val*2;
	uint16_t crr_Val = timer->CCR1;
	int newCcrVal = (float)(outPeriod)*(float)(dutyCycle_percent)/100;
	int shiftVal=0;
	/*
	switch(dutyCycle.mode){
	case shiftRisingEdge:
		if(dutyCycle_percent < 50){
			//shiftVal =
						}

	}
*/



}
