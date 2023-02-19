#ifndef RTC_H_
#define RTC_H_



void RTC_Init_case1(void);//16分频，计数1000
void RTC_Init_case2(void);//10分频，计数3200
void RTC_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));//RTC中断函数








#endif
