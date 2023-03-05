#ifndef COMP_H_
#define COMP_H_

void COMP1_Init(void);//COPM1
void COMP2_Init(void);//COPM2
void COMP3_Init(void);//COPM3

void CLIC_COMP1_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));//COPM1中断函数
void CLIC_COMP2_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));//COPM2中断函数
void CLIC_COMP3_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));//COPM3中断函数




#endif

