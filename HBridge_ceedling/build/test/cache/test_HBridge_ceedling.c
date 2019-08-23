#include "build/temp/_test_HBridge_ceedling.c"
#include "timer.h"
#include "HBridge_ceedling.h"
#include "unity.h"




uint16_t CCR1 = 0;

uint16_t CCR2 = 0;

uint16_t CCR3 = 0;

uint16_t CCR4 = 0;



void setUp(void)

{

  uint16_t CCR1 = 0;

  uint16_t CCR2 = 0;

  uint16_t CCR3 = 0;

  uint16_t CCR4 = 0;

}



void tearDown(void)

{

}



void test_timer_clk_int_Freq_freq_8MHz_expect_125_ns(void)

{

    int i = clk_int_peiord();



    UnityAssertEqualNumber((UNITY_INT)((125)), (UNITY_INT)((i)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);

}





void test_getdtgMultiplier_deadtime_is_3000ns_expect_return_0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 3000;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_15875ns_expect_return_0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 15875;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_15876ns_expect_return_0x0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 15999;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_16000ns_expect_return_0x80(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 16000;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x80)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(63), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_18452ns_expect_return_0x80(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 18452;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x80)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_INT);



}





void test_getdtgMultiplier_deadtime_is_31825ns_expect_return_0x80(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 31999;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x80)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_32000ns_expect_return_0xC0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 32000;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0xC0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(91), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_58000ns_expect_return_0xC0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 58000;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0xC0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_63999ns_expect_return_0xC0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 63999;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0xC0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_64000ns_expect_return_0xE0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 64000;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0xE0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(118), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_100000ns_expect_return_0xE0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 100000;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0xE0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(127), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_126999ns_expect_return_0xE0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 126999;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0xE0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(136), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_127000ns_expect_return_0xE0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 127000;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0xE0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgMultiplier_deadtime_is_300000ns_expect_return_0xE0(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 300000;

 uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0xE0)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(154), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgBitsVal_deadtime_is_14386ns_range1_expect_return_0x73(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 14386;

 uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x73)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(163), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgBitsVal_deadtime_is_15900ns_range1_expect_return_0x7F(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 15900;

 uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x7F)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(172), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgBitsVal_deadtime_is_18020ns_range2_expect_return_0x8(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 18020;

 uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x8)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(181), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgBitsVal_deadtime_is_31800ns_range2_expect_return_0x3F(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 31800;

 uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x3F)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(190), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgBitsVal_deadtime_is_50786ns_range3_expect_return_0x12(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 50786;

 uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x12)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(199), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgBitsVal_deadtime_is_63346ns_range3_expect_return_0x1F(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 63346;

 uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x1F)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(208), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgBitsVal_deadtime_is_103546ns_range4_expect_return_0x13(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 103546;

 uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x13)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(217), UNITY_DISPLAY_STYLE_INT);



}



void test_getdtgBitsVal_deadtime_is_126800ns_range4_expect_return_0x1F(void){

 int clk_period = clk_int_peiord();

 int deadtime_ns = 126800;

 uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);



 UnityAssertEqualNumber((UNITY_INT)((0x1F)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(226), UNITY_DISPLAY_STYLE_INT);



}



void test_setDeadTime_deadtime_is_3000ns_range1_expect_return_0x18(void){



 int deadtime_ns = 3000;

 uint8_t result = setDeadTime(deadtime_ns);



 UnityAssertEqualNumber((UNITY_INT)((0x18)), (UNITY_INT)((result)), (

((void *)0)

), (UNITY_UINT)(235), UNITY_DISPLAY_STYLE_INT);



}

void test_getCRRVal_ARR_is_1000_and_dutyCycle_percent_is_30_return_300(void){



  int CRR1 = calculateRangeVal(25);

  int CRR2 = calculateRangeVal(50);

  int CRR3 = calculateRangeVal(60);

  int CRR4 = calculateRangeVal(75);



  UnityAssertEqualNumber((UNITY_INT)((250)), (UNITY_INT)((CRR1)), (

 ((void *)0)

 ), (UNITY_UINT)(258), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((500)), (UNITY_INT)((CRR2)), (

 ((void *)0)

 ), (UNITY_UINT)(259), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((600)), (UNITY_INT)((CRR3)), (

 ((void *)0)

 ), (UNITY_UINT)(260), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((750)), (UNITY_INT)((CRR4)), (

 ((void *)0)

 ), (UNITY_UINT)(261), UNITY_DISPLAY_STYLE_INT);

}



void test_getNewCCRVAl_ARR_is_1000_input_dutyCycleRange_300_prev_CCRVal_100_expect_new_CCRVal_is_400(void){

  int CCR1 = 100;

  int newDutyCycle = calculateRangeVal(30);

  int result = getNewCCRVAl(CCR1,newDutyCycle);



  UnityAssertEqualNumber((UNITY_INT)((400)), (UNITY_INT)((result)), (

 ((void *)0)

 ), (UNITY_UINT)(269), UNITY_DISPLAY_STYLE_INT);

}
