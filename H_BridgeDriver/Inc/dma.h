#ifndef __DMA_H__
#define __DMA_H__

#include "stm32f1xx_hal.h"
#include <stdio.h>
#include <stdint.h>

#define enableDMAchn2()		hdma_tim1_ch1.Instance->CCR |= 1<<0
#define enableDMAchn3()		hdma_tim1_ch2.Instance->CCR |= 1<<0

#define half_transfer_interupt_en	1<<3
#define full_transfer_interupt_en	1<<2

#define channel_enable	1<<0

void dma_Init(void);

#endif /* __DMA_H__ */
