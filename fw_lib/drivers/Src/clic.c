#include "headfile.h"


void CLIC_Init(void)//中断模式配置
{
	write_csr(mtvec,(unsigned long)&trap_entry|MTVEC_CLIC_VECTORED); //模式选择3：CLIC Vectored
	_REG32(CLIC2_BASE,0xc00) = 0x04;//2 bits levels
}


void Interrupt_Enable(uint8_t interrupt_ID)//CLIC使能单个中断
{
    uint8_t *p_clicintie = (uint8_t *)CLIC_INTIE_BASE;
    p_clicintie += interrupt_ID;
    *p_clicintie = 1;
}

void Interrupt_Disable(uint8_t interrupt_ID)//CLIC关闭单个中断
{
    uint8_t *p_clicintie = (uint8_t *)CLIC_INTIE_BASE;
    p_clicintie += interrupt_ID;
    *p_clicintie = 0;
}

void Interrupt_Level(uint8_t interrupt_ID,uint8_t interrupt_level)//CLIC设置中断抢占级别
{
    uint8_t *p_clicintcfg = (uint8_t *)CLIC_INTCFG_BASE;
    p_clicintcfg += interrupt_ID;
    *p_clicintcfg = interrupt_level;
}




void SYS_Interrupt_Enable(void)//CLIC开总中断
{
	write_csr(mie,0x880);     //机器模式外部中断 和 mtime
	write_csr(mstatus,0x08);  //总中断
}

void SYS_Interrupt_Disable(void)//CLIC关总中断
{
	write_csr(mie,0x0);     //机器模式外部中断 和 mtime
	write_csr(mstatus,0x00);  //总中断
}

void trap_entry(void)//系统异常函数
{
	while(1)
	{
	    _REG32(0x30000360,0) = 0x01;//softreset

        //GPIO_Toggle(GPIOA,PIN15);
		//Delay32M_ms(50);
		//printf("trap:%x %x %x\r\n",read_csr(mstatus),read_csr(mcause),read_csr(mepc));
	}
}


void soft_IRQHandler(void)
{

}






