#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include <math.h>
#include "dma.h"
#include "timer.h"

extern DMA_HandleTypeDef hdma_tim1_ch1;
extern DMA_HandleTypeDef hdma_tim1_ch3;
extern uint16_t bufferCCR1[2];
extern uint16_t bufferCCR3[2];

void dma_Init(void){

	  hdma_tim1_ch1.Instance->CPAR = timer1CCR1Address;//ccr value defined in timer.h
	  hdma_tim1_ch1.Instance->CMAR = (uint32_t)&(bufferCCR1);
	  hdma_tim1_ch3.Instance->CPAR = timer1CCR3Address;//ccr value defined in timer.h
	  hdma_tim1_ch3.Instance->CMAR = (uint32_t)&(bufferCCR3);

	  hdma_tim1_ch1.Instance->CNDTR = 2;
	  hdma_tim1_ch3.Instance->CNDTR = 2;
}

void set_
