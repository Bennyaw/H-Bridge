#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx_hal.h"

typedef enum edgeShift edgeShift;
enum edgeShift{
	shiftRisingEdge,
	shiftFallingEdge,
	shiftBothEdges
};

typedef struct dutyCycle dutyCycle;
struct dutyCycle{
	int mode;
	uint32_t rise_edge;
	uint32_t fall_edge;
};

enum deadTimeMultiplier{
	periodMultiplier_1 = 1,
	periodMultiplier_2 = 2,
	periodMultiplier_8 = 8,
	periodMultiplier_16 = 16
};



#define clearTimerUIF(htim1)				htim1.Instance->SR &= 0<<0

void dutyCycleInit(TIM_TypeDef *timer,uint32_t channel,uint16_t arr_val);
void setTimerCCRVal(TIM_HandleTypeDef *timer,uint32_t channel,uint32_t outputCompareVal);
int apb2_clk_int_peiord(void);
int getdtgMultiplier(uint32_t deadTime_ns,int period_clk_base);
int getdtgBitsVal(uint32_t deadTime_ns , int period_clk_base);
int setDeadTime(uint32_t deadTime_ns);

#endif /* __TIMER_H__ */
