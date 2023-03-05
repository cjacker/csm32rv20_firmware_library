#include "headfile.h"


void LV_Init_case1(uint32_t lv_trim)//设置低压报警阈值
{
    uint32_t temp = ANA->CFG1;

    LV->IRQ = 0;
    temp &= ~(0xf<<25);
    temp |= (lv_trim&0xf)<<25;
    ANA->CFG1 = temp;

    Delay32M_us(100);//延时100us等待电源稳定

}

void LV_Interrupt_Enable(void)//使能低压报警中断
{
    LV->IRQ_EN = 0x1;
}

void LV_Interrupt_Disable(void)//关闭低压报警中断
{
    LV->IRQ_EN = 0x0;
}


void LV_IRQhandler(void)//低压报警中断函数
{
	if(LV->IRQ&0x1)
	{
		//GPIO_Toggle(GPIOA,PIN15);
		//Delay32M_ms(200);
		//printf("lv_irq:\r\n");

		LV->IRQ = 0;
	}

}










