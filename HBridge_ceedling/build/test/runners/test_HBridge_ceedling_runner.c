/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Test Runner Used To Run Each Test Below=====*/
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
      setUp(); \
      TestFunc(); \
  } \
  if (TEST_PROTECT()) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

/*=======Automagically Detected Files To Include=====*/
#ifdef __WIN32__
#define UNITY_INCLUDE_SETUP_STUBS
#endif
#include "unity.h"
#ifndef UNITY_EXCLUDE_SETJMP_H
#include <setjmp.h>
#endif
#include <stdio.h>

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_timer_clk_int_Freq_freq_8MHz_expect_125_ns(void);
extern void test_getdtgMultiplier_deadtime_is_3000ns_expect_return_0(void);
extern void test_getdtgMultiplier_deadtime_is_15875ns_expect_return_0(void);
extern void test_getdtgMultiplier_deadtime_is_15876ns_expect_return_0x0(void);
extern void test_getdtgMultiplier_deadtime_is_16000ns_expect_return_0x80(void);
extern void test_getdtgMultiplier_deadtime_is_18452ns_expect_return_0x80(void);
extern void test_getdtgMultiplier_deadtime_is_31825ns_expect_return_0x80(void);
extern void test_getdtgMultiplier_deadtime_is_32000ns_expect_return_0xC0(void);
extern void test_getdtgMultiplier_deadtime_is_58000ns_expect_return_0xC0(void);
extern void test_getdtgMultiplier_deadtime_is_63999ns_expect_return_0xC0(void);
extern void test_getdtgMultiplier_deadtime_is_64000ns_expect_return_0xE0(void);
extern void test_getdtgMultiplier_deadtime_is_100000ns_expect_return_0xE0(void);
extern void test_getdtgMultiplier_deadtime_is_126999ns_expect_return_0xE0(void);
extern void test_getdtgMultiplier_deadtime_is_127000ns_expect_return_0xE0(void);
extern void test_getdtgMultiplier_deadtime_is_300000ns_expect_return_0xE0(void);
extern void test_getdtgBitsVal_deadtime_is_14386ns_range1_expect_return_0x73(void);
extern void test_getdtgBitsVal_deadtime_is_15900ns_range1_expect_return_0x7F(void);
extern void test_getdtgBitsVal_deadtime_is_18020ns_range2_expect_return_0x8(void);
extern void test_getdtgBitsVal_deadtime_is_31800ns_range2_expect_return_0x3F(void);
extern void test_getdtgBitsVal_deadtime_is_50786ns_range3_expect_return_0x12(void);
extern void test_getdtgBitsVal_deadtime_is_63346ns_range3_expect_return_0x1F(void);
extern void test_getdtgBitsVal_deadtime_is_103546ns_range4_expect_return_0x13(void);
extern void test_getdtgBitsVal_deadtime_is_126800ns_range4_expect_return_0x1F(void);
extern void test_setDeadTime_deadtime_is_3000ns_range1_expect_return_0x18(void);
extern void test_getCRRVal_ARR_is_1000_and_dutyCycle_percent_is_30_return_300(void);
extern void test_getNewCCRVAl_ARR_is_1000_input_dutyCycleRange_300_prev_CCRVal_0_expect_new_CCRVal_is_300(void);


/*=======Suite Setup=====*/
static void suite_setup(void)
{
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  suiteSetUp();
#endif
}

/*=======Suite Teardown=====*/
static int suite_teardown(int num_failures)
{
#if defined(UNITY_WEAK_ATTRIBUTE) || defined(UNITY_WEAK_PRAGMA)
  return suiteTearDown(num_failures);
#else
  return num_failures;
#endif
}

/*=======Test Reset Option=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  setUp();
}


/*=======MAIN=====*/
int main(void)
{
  suite_setup();
  UnityBegin("test_HBridge_ceedling.c");
  RUN_TEST(test_timer_clk_int_Freq_freq_8MHz_expect_125_ns, 23);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_3000ns_expect_return_0, 31);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_15875ns_expect_return_0, 40);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_15876ns_expect_return_0x0, 49);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_16000ns_expect_return_0x80, 58);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_18452ns_expect_return_0x80, 67);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_31825ns_expect_return_0x80, 77);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_32000ns_expect_return_0xC0, 86);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_58000ns_expect_return_0xC0, 95);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_63999ns_expect_return_0xC0, 104);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_64000ns_expect_return_0xE0, 113);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_100000ns_expect_return_0xE0, 122);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_126999ns_expect_return_0xE0, 131);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_127000ns_expect_return_0xE0, 140);
  RUN_TEST(test_getdtgMultiplier_deadtime_is_300000ns_expect_return_0xE0, 149);
  RUN_TEST(test_getdtgBitsVal_deadtime_is_14386ns_range1_expect_return_0x73, 158);
  RUN_TEST(test_getdtgBitsVal_deadtime_is_15900ns_range1_expect_return_0x7F, 167);
  RUN_TEST(test_getdtgBitsVal_deadtime_is_18020ns_range2_expect_return_0x8, 176);
  RUN_TEST(test_getdtgBitsVal_deadtime_is_31800ns_range2_expect_return_0x3F, 185);
  RUN_TEST(test_getdtgBitsVal_deadtime_is_50786ns_range3_expect_return_0x12, 194);
  RUN_TEST(test_getdtgBitsVal_deadtime_is_63346ns_range3_expect_return_0x1F, 203);
  RUN_TEST(test_getdtgBitsVal_deadtime_is_103546ns_range4_expect_return_0x13, 212);
  RUN_TEST(test_getdtgBitsVal_deadtime_is_126800ns_range4_expect_return_0x1F, 221);
  RUN_TEST(test_setDeadTime_deadtime_is_3000ns_range1_expect_return_0x18, 230);
  RUN_TEST(test_getCRRVal_ARR_is_1000_and_dutyCycle_percent_is_30_return_300, 251);
  RUN_TEST(test_getNewCCRVAl_ARR_is_1000_input_dutyCycleRange_300_prev_CCRVal_0_expect_new_CCRVal_is_300, 264);

  return suite_teardown(UnityEnd());
}
