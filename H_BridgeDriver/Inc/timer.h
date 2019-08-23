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

#define timer1CCR1Address 0x40012C34
#define timer1CCR2Address 0x40012C38
#define timer1CCR3Address 0x40012C3C

#define channel_1		1
#define channel_2		2
#define channel_3		3
#define channel_4		4
#define TOGGLE			3
#define PWM_MODE1		6
#define PWM_MODE2		7
#define OC1_COMPLEMENT_EN 1<<2
#define OC2_COMPLEMENT_EN 1<<6
#define OC3_COMPLEMENT_EN 1<<10
#define OC1_EN 1<<0
#define OC2_EN 1<<4
#define OC3_EN 1<<8
#define OC1_IDLE_HIGH	1<<8
#define OC1N_IDLE_HIGH	1<<9
#define OFF_STATE_RUN	1<<11
#define OFF_STATE_IDLE	1<<10
#define CNT_EN			1<<0
#define MOE_EN			1<<15

#define CC11P_AC_LOW	1<<1
#define CC12P_AC_LOW	1<<5
#define CC13P_AC_LOW	1<<9

#define CC11PN_AC_LOW	1<<3
#define CC12PN_AC_LOW	1<<7
#define CC13PN_AC_LOW	1<<11

#define dtgMultiply_1 	1
#define dtgMultiply_2	2
#define dtgMultiply_8	8
#define dtgMultiply_16	16

#define deadTimeMultiply_1 0<<7
#define deadTimeMultiply_2	2<<6
#define deadTimeMultiply_8	6<<5
#define deadTimeMultiply_16	7<<5

#define arr_preload_en 1<<7
#define center_align_3 3<<5;

#define dma_ccr1_request_en	1<<9
#define dma_ccr2_request_en	1<<10
#define dma_ccr3_request_en	1<<11
#define dma_ccr1_interrupt_en 1<<1
#define dma_ccr2_interrupt_en 1<<2
#define dma_ccr3_interrupt_en 1<<3


#define clearTimerUIF(htim1)				htim1.Instance->SR &= 0<<0

void dutyCycleInit(TIM_HandleTypeDef *timer,uint32_t channel,uint16_t arr_val);
void setTimerCCRVal(TIM_HandleTypeDef *timer,uint32_t channel,uint32_t outputCompareVal);
float apb2_clk_int_period(void);
int getdtgMultiplier(uint32_t deadTime_ns,int period_clk_base);
int getdtgBitsVal(uint32_t deadTime_ns , int period_clk_base);
int setDeadTime(uint32_t deadTime_ns);

#endif /* __TIMER_H__ */
