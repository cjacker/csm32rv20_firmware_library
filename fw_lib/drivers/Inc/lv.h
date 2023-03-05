#ifndef _LV_H_
#define _LV_H_



void LV_Init_case1(uint32_t lv_trim);//设置低压报警阈值
void LV_Interrupt_Enable(void);//使能低压报警中断
void LV_Interrupt_Disable(void);//关闭低压报警中断

void CLIC_LV_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));//低压报警中断函数








#endif
