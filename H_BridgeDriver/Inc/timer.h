#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx_hal.h"

void setTimerOutputPulsePeriod(TIM_HandleTypeDef *timer,uint32_t channel,uint16_t prescaler,uint32_t arrVal,uint32_t outputCompareVal);
void setTimer1DeadTime(TIM_TypeDef *timer1,uint32_t clockPeriod_ns,uint32_t deadTimeMultiplier,uint32_t deadTime_ns);
uint8_t calculateDTGbits(uint32_t clockPeriod_ns,uint8_t deadTimeMultiplier,uint32_t deadTime_ns);

#endif /* __TIMER_H__ */
