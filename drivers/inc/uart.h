#ifndef UART_H_
#define UART_H_

#include "stdio.h"

#define ULEN 32

void UART_Init_case1(UART_TypeDef *UARTx); //非中断模式
void UART_Init_IT_case1(UART_TypeDef *UARTx); //中断模式

void Uart_Send(UART_TypeDef *UARTx,uint8_t *packet,uint16_t lenth);//适用于非中断发送模式
void Uart_Reveive(UART_TypeDef *UARTx,uint8_t *packet,uint16_t lenth);//适用于非中断接收模式

uint8_t UART1_putbuf(uint8_t ubyte);//数据放入缓存，适用于中断模式
uint8_t UART1_getbuf(void);//阻塞取数据缓存
uint8_t UART1_getbuf_noblock(uint8_t *pdata);//非阻塞取数据缓存

void UART1_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void UART2_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void UART3_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void UART4_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));

ssize_t _write(int file,const void *ptr, size_t len);


#endif
