#include "unity.h"
#include "HBridge_ceedling.h"
#include "timer.h"


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

    TEST_ASSERT_EQUAL(125,i);
}


void test_getdtgMultiplier_deadtime_is_3000ns_expect_return_0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 3000;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0,result);

}

void test_getdtgMultiplier_deadtime_is_15875ns_expect_return_0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 15875;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0,result);

}

void test_getdtgMultiplier_deadtime_is_15876ns_expect_return_0x0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 15999;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x0,result);

}

void test_getdtgMultiplier_deadtime_is_16000ns_expect_return_0x80(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 16000;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x80,result);

}

void test_getdtgMultiplier_deadtime_is_18452ns_expect_return_0x80(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 18452;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x80,result);

}


void test_getdtgMultiplier_deadtime_is_31825ns_expect_return_0x80(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 31999;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x80,result);

}

void test_getdtgMultiplier_deadtime_is_32000ns_expect_return_0xC0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 32000;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0xC0,result);

}

void test_getdtgMultiplier_deadtime_is_58000ns_expect_return_0xC0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 58000;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0xC0,result);

}

void test_getdtgMultiplier_deadtime_is_63999ns_expect_return_0xC0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 63999;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0xC0,result);

}

void test_getdtgMultiplier_deadtime_is_64000ns_expect_return_0xE0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 64000;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0xE0,result);

}

void test_getdtgMultiplier_deadtime_is_100000ns_expect_return_0xE0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 100000;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0xE0,result);

}

void test_getdtgMultiplier_deadtime_is_126999ns_expect_return_0xE0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 126999;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0xE0,result);

}

void test_getdtgMultiplier_deadtime_is_127000ns_expect_return_0xE0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 127000;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0xE0,result);

}

void test_getdtgMultiplier_deadtime_is_300000ns_expect_return_0xE0(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 300000;
	uint8_t result = getdtgMultiplier(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0xE0,result);

}

void test_getdtgBitsVal_deadtime_is_14386ns_range1_expect_return_0x73(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 14386;
	uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x73,result);

}

void test_getdtgBitsVal_deadtime_is_15900ns_range1_expect_return_0x7F(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 15900;
	uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x7F,result);

}

void test_getdtgBitsVal_deadtime_is_18020ns_range2_expect_return_0x8(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 18020;
	uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x8,result);

}

void test_getdtgBitsVal_deadtime_is_31800ns_range2_expect_return_0x3F(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 31800;
	uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x3F,result);

}

void test_getdtgBitsVal_deadtime_is_50786ns_range3_expect_return_0x12(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 50786;
	uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x12,result);

}

void test_getdtgBitsVal_deadtime_is_63346ns_range3_expect_return_0x1F(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 63346;
	uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x1F,result);

}

void test_getdtgBitsVal_deadtime_is_103546ns_range4_expect_return_0x13(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 103546;
	uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x13,result);

}

void test_getdtgBitsVal_deadtime_is_126800ns_range4_expect_return_0x1F(void){
	int clk_period = clk_int_peiord();
	int deadtime_ns = 126800;
	uint8_t result = getdtgBitsVal(deadtime_ns,clk_period);

	TEST_ASSERT_EQUAL(0x1F,result);

}

void test_setDeadTime_deadtime_is_3000ns_range1_expect_return_0x18(void){

	int deadtime_ns = 3000;
	uint8_t result = setDeadTime(deadtime_ns);

	TEST_ASSERT_EQUAL(0x18,result);

}

/**
 * Test for setting suty cycle
 * setDutyCycle(dutyCycle_percent)
 *        __________
 * ______|          |______
 *              __________
 * ____________|          |______
 *       | 50% |
 *
 * by default set the 2nd channel offset to 50% of channel 1 pulse width
 */

void test_getCRRVal_ARR_is_1000_and_dutyCycle_percent_is_30_return_300(void){

  int CRR1 = calculateRangeVal(25);
  int CRR2 = calculateRangeVal(50);
  int CRR3 = calculateRangeVal(60);
  int CRR4 = calculateRangeVal(75);

  TEST_ASSERT_EQUAL(250,CRR1);
  TEST_ASSERT_EQUAL(500,CRR2);
  TEST_ASSERT_EQUAL(600,CRR3);
  TEST_ASSERT_EQUAL(750,CRR4);
}

void test_getNewCCRVAl_ARR_is_1000_input_dutyCycleRange_300_prev_CCRVal_100_expect_new_CCRVal_is_400(void){
  int CCR1 = 100;//previous CRR value
  int newDutyCycle = calculateRangeVal(30);
  int result = getNewCCRVAl(CCR1,newDutyCycle);

  TEST_ASSERT_EQUAL(400,result);
}
