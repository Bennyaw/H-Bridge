#include "timer.h"
#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx_hal.h"


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



/*
 * DTG[7:5]=0xx => DT=DTG[6:0]x tdtg with tdtg=tDTS.
 * DTG[7:5]=10x => DT=(64+DTG[5:0])xtdtg with Tdtg=2xtDTS.
 * DTG[7:5]=110 => DT=(32+DTG[4:0])xtdtg with Tdtg=8xtDTS.
 * DTG[7:5]=111 => DT=(32+DTG[4:0])xtdtg with Tdtg=16xtDTS.
 * Example if TDTS=125ns (8MHz), dead-time possible values are:
 * 0 to 15875 ns by 125 ns steps,
 * 16 us to 31750 ns by 250 ns steps,
 * 32 us to 63us by 1 us steps,
 * 64 us to 126 us by 2 us steps
 */


void setTimer1DeadTime(TIM_TypeDef *timer1,uint32_t clockPeriod_ns,uint32_t deadTimeMultiplier,uint32_t deadTime_ns){

	timer1->BDTR &= ~0xff; //reset dead time value

}

uint8_t calculateDTGbits(uint32_t clockPeriod_ns,uint8_t deadTimeMultiplier,uint32_t deadTime_ns){

	uint8_t getDTGVal1,getDTGVal2,getDTGVal3,getDTGVal4;//DTG = dead time generator
/*
	getDTGVal1 = deadTime_ns/clockPeriod_ns & 0x7f;
	getDTGVal2 = ((deadTime_ns/2*clockPeriod_ns)-64) & 0x3f;
	getDTGVal3 = ((deadTime_ns/8*clockPeriod_ns)-32) & 0x1f;
	getDTGVal4 = ((deadTime_ns/16*clockPeriod_ns)-32) & 0x1f;
*/
	if(deadTimeMultiplier == 1)
		return getDTGVal1 = deadTime_ns/clockPeriod_ns & 0x7f;
	else if(deadTimeMultiplier == 2)
		return getDTGVal2 = ((deadTime_ns/2*clockPeriod_ns)-64) & 0x3f;
	else if(deadTimeMultiplier == 8)
		return getDTGVal3 = ((deadTime_ns/8*clockPeriod_ns)-32) & 0x1f;
	else if(deadTimeMultiplier == 16)
		return getDTGVal4 = ((deadTime_ns/16*clockPeriod_ns)-32) & 0x1f;

}
/*
 * configurations[31:16] is to configure CCER
 * configurations[15:0]  is to configure BDTR
 */
/*
void configureTimer1_OC_OCN(TIM_TypeDef *timer1,uint32_t configurations){

	uint16_t ccer_reg,bdtr_reg;

	ccer_reg = ((configurations & 0xffff0000) >> 16);
	bdtr_reg = configurations & 0x0000ffff;

	timer1->BDTR |= bdtr_reg;
	timer1->CCER |= ccer_reg;
}
*/

/**
 * This function initialize the duty cycle to 50%, which ccr = arr/2
 * */
void dutyCycleInit(TIM_TypeDef *timer,uint32_t channel,uint16_t arr_val){
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
