#ifndef _HBRIDGE_CEEDLING_H
#define _HBRIDGE_CEEDLING_H

#include <stdint.h>

#define ARR 1000
#define channel_1 1
#define channel_2 2
#define channel_3 3
#define channel_4 4


//void dutyCycleInit(TIM_HandleTypeDef *timer,uint32_t channel,uint16_t arr_val);
int calculateRangeVal(int dutyCycle_percent);
int getNewCCRVAl(uint16_t prev_CCRVal,uint16_t dutyCycleRange);

#endif // _HBRIDGE_CEEDLING_H
