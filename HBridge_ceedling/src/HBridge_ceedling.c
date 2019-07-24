#include "HBridge_ceedling.h"
#include <stdint.h>
#include <stdio.h>

extern uint16_t CCR1;
extern uint16_t CCR2;
extern uint16_t CCR3;
extern uint16_t CCR4;


void offsetPulse(){
}

int getNewCCRVAl(uint16_t prev_CCRVal,uint16_t dutyCycleRange){
  int newCCR=0;
  int temp=0;

  newCCR = prev_CCRVal + dutyCycleRange;
  
  return newCCR;
}


int calculateRangeVal(int dutyCycle_percent){
  float dutyCycleRange = ARR*((float)dutyCycle_percent/(float)100);
  return dutyCycleRange;
}
