#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include "dma.h"

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


#define kHz				1000
#define MHz				1000000

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
#define cap_com_preload_en 1<<0

#define dma_ccr1_request_en	1<<9
#define dma_ccr2_request_en	1<<10
#define dma_ccr3_request_en	1<<11

#define dma_ccr1_interrupt_en 1<<1
#define dma_ccr2_interrupt_en 1<<2
#define dma_ccr3_interrupt_en 1<<3

#define clearTimerUIF(htim1)				htim1.Instance->SR &= 0<<0

#define reset_deadtime_dtg_bits()			htim1.Instance->BDTR &= ~0xff;//reset dtg bits,DTG[7:0]

#define setCounterValue(val)				htim1.Instance->CNT = val

#define setPrescalerValue(val)				htim1.Instance->PSC = val-1
#define getPrescalerValue()					((htim1.Instance->PSC)+1)

#define getARRValue()						htim1.Instance->ARR
#define setARRValue(val)					htim1.Instance->ARR = val

#define enable_tim1Chn1_complementaryOC() 		htim1.Instance->CCER |= OC1_COMPLEMENT_EN	//Enable timer1 chn1 complementary output compare
#define enable_tim1Chn2_complementaryOC() 		htim1.Instance->CCER |= OC2_COMPLEMENT_EN	//Enable timer1 chn2 complementary output compare
#define enable_tim1Chn3_complementaryOC()		htim1.Instance->CCER |= OC3_COMPLEMENT_EN	//Enable timer1 chn3 complementary output compare
#define enable_tim1Chn1_OC()					htim1.Instance->CCER |= OC1_EN				//Enable timer1 chn1 output compare
#define enable_tim1Chn2_OC()					htim1.Instance->CCER |= OC3_EN				//Enable timer1 chn2 output compare
#define enable_tim1Chn3_OC()					htim1.Instance->CCER |= OC3_EN				//Enable timer1 chn3 output compare

#define enable_mainOutput()						htim1.Instance->BDTR |= MOE_EN;//Main output enable
#define enable_counter()						htim1.Instance->CR1 |= CNT_EN;//counter enable
#define enable_dma_cap_com_request(val)			htim1.Instance->DIER |= val;

void dutyCycleInit(TIM_HandleTypeDef *timer,uint32_t channel,uint16_t arr_val);
void setTimerCCRVal(TIM_HandleTypeDef *timer,uint32_t channel,uint32_t outputCompareVal);
float apb2_clk_int_period(void);
int getdtgMultiplier(uint32_t deadTime_ns,float period_clk_base);
int getdtgBitsVal(uint32_t deadTime_ns , float period_clk_base);
void setDeadTime_ns(uint32_t deadTime_ns);
void timer_Init(void);
void setTimerOutputFrequency_Hz(float out_freq_Hz);
void setTimer1Chn1_OutputDutyCycle(volatile double dutyCycle);
void setBufferValChn3(int riseEdge,int fallEdge);
void setBufferValChn1(int riseEdge,int fallEdge);
void setTimer1Chn3_OutputDutyCycle(volatile double dutyCycle);
void setOffSet_Chn3(volatile double offset_percent);
int getApb2_divider(void);
void setBufferValChn2(int riseEdge,int fallEdge);
void setTimer1Chn2_OutputDutyCycle(volatile double dutyCycle_percent);
void setOffSet_Chn2(volatile double offset_percent);
#endif /* __TIMER_H__ */
