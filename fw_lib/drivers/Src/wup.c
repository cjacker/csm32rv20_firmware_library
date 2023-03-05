#include "headfile.h"


void WUP_Init_case1(uint32_t data)//设置中断周期,使能WUP中断
{
    WUP->DATA = data;
    WUP->IRQ = 0;
    WUP->IRQ_EN = 1;
}

void WUP_IRQhandler(void)
{
    if(WUP->IRQ&0x01)
    {
        WUP->IRQ = 0;
	    //GPIO_Toggle(GPIOA,PIN14);
    }
}





