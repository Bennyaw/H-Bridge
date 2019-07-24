#include "timer.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>


int clk_int_peiord(void){
	float period = ((float)1/(float)HAL_RCC_GetHCLKFreq)*pow(10,9);
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
	int period_clk_base = clk_int_peiord();

	uint8_t dtgMultiplier = (uint8_t)getdtgMultiplier(deadTime_ns,period_clk_base);
	uint8_t dtgVal = (uint8_t)getdtgBitsVal(deadTime_ns , period_clk_base);

	return  dtgMultiplier|dtgVal;
}
