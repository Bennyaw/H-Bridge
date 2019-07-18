#ifndef _TIMER_H
#define _TIMER_H

#include <stdint.h>
#include <stdio.h>

#define HAL_RCC_GetHCLKFreq 8000000

enum deadTimeMultiplier{
	periodMultiplier_1 = 1,
	periodMultiplier_2 = 2,
	periodMultiplier_8 = 8,
	periodMultiplier_16 = 16
};

int clk_int_peiord(void);
int getdtgMultiplier(uint32_t deadTime_ns,int period_clk_base);
int getdtgBitsVal(uint32_t deadTime_ns , int period_clk_base);
int setDeadTime(uint32_t deadTime_ns);
#endif // _TIMER_H
