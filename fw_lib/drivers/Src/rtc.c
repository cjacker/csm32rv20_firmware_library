#include "headfile.h"


void RTC_Init_case1(void)//16分频，计数1000
{
    uint32_t mask=0x1f<<10;

    uint32_t temp = CMU->CLK_DIV;
    temp &= ~mask;
    temp |= 16<<10;//设置RTC分频系数
    CMU->CLK_DIV = temp;

	RTC_MTIME->mtime = 0;
	RTC_MTIMECMP->mtimecmp = 1000;
}

void RTC_Init_case2(void)//10分频，计数3200
{
    uint32_t mask=0x1f<<10;

    uint32_t temp = CMU->CLK_DIV;
    temp &= ~mask;
    temp |= 10<<10;//设置RTC分频系数
    CMU->CLK_DIV = temp;

	RTC_MTIME->mtime = 0;
	RTC_MTIMECMP->mtimecmp = 3200;
}

void RTC_IRQhandler(void)//RTC中断函数
{
    RTC_MTIMECMP->mtimecmp += 1000;
    //RTC_MTIMECMP->mtimecmp += 3200;

	//GPIO_Toggle(GPIOA,PIN14);
	//GPIO_Toggle(GPIOA,PIN8);
	//GPIO_Write(GPIOA,PIN8,GPIO_RESET);
	//Delay32M_ms(50);
	//GPIO_Write(GPIOA,PIN8,GPIO_SET);
}











