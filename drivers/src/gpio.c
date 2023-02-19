#include "headfile.h"


void GPIO_MODE_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_MODEx) //GPIO 模式
{
	uint32_t temp = GPIOx->MODER;
	uint32_t Bitmask = 0x00000003;

	temp &= ~(Bitmask<<(PINx*2));
	temp |= GPIO_MODEx<<(PINx*2);

	GPIOx->MODER = temp;
}

void GPIO_OutType_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_OTYPEx) //GPIO 输出模式
{
	uint32_t temp = GPIOx->OTYPER;
	uint32_t Bitmask = 0x00010001;

	temp &= ~(Bitmask<<PINx);
	temp |= GPIO_OTYPEx<<PINx;

	GPIOx->OTYPER = temp;
}

void GPIO_InType_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_ITYPEx) //GPIO 输入模式
{
	uint32_t temp = GPIOx->ITYPER;
	uint32_t Bitmask = 0x00000001;

	temp &= ~(Bitmask<<PINx);
	temp |= GPIO_ITYPEx<<PINx;

	GPIOx->ITYPER = temp;
}

void GPIO_PULL_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_PULLx) //GPIO 上拉
{
	uint32_t temp = GPIOx->PUPDR;
	uint32_t Bitmask = 0x00000003;

	temp &= ~(Bitmask<<(PINx*2));
	temp |= GPIO_PULLx<<(PINx*2);

	GPIOx->PUPDR = temp;
}

void GPIO_OutSpeed_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_SPEEDx) //GPIO 压摆率
{
	uint32_t temp = GPIOx->SDR;
	uint32_t Bitmask = 0x00010001;

	temp &= ~(Bitmask<<PINx);
	temp |= GPIO_SPEEDx<<PINx;

	GPIOx->SDR = temp;
}

void GPIO_AF_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_AFx) //GPIO 复用模式
{
	if(PINx < 8)
	{
		uint32_t temp1 = GPIOx->AFRL;
		uint32_t Bitmask1 = 0x0000000F;

		temp1 &= ~(Bitmask1<<(PINx*4));
		temp1 |= GPIO_AFx<<(PINx*4);

		GPIOx->AFRL = temp1;
	}
	else
	{
		uint32_t temp2 = GPIOx->AFRH;
		uint32_t Bitmask2 = 0x0000000F;
		temp2 &= ~(Bitmask2<<((PINx-8)*4));
		temp2 |= GPIO_AFx<<((PINx-8)*4);

		GPIOx->AFRH = temp2;
	}
}


void GPIO_EXIT_MODE_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_EXIT_MODEx) //GPIO 中断模式
{
	uint32_t temp = GPIOx->LPMR;
	uint32_t Bitmask = 0x00000003;

	temp &= ~(Bitmask<<(PINx*2));
	temp |= GPIO_EXIT_MODEx<<(PINx*2);

	EXTI->ISR |= 0x1<<PINx;

	GPIOx->LPMR = temp;
}

void GPIO_INTER_enable(GPIO_TypeDef *GPIOx,uint8_t PINx) //GPIO 中断使能
{
	GPIOx->INTER |= 0x00000001<<PINx;
}

void GPIO_INTER_disable(GPIO_TypeDef *GPIOx,uint8_t PINx) //GPIO 中断关闭
{
	GPIOx->INTER &= ~(0x00000001<<PINx);
}

void GPIO_Write(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_PinState) //GPIO 写输出
{
	GPIOx->BSR = GPIO_PinState<<PINx;
}

uint8_t GPIO_Read(GPIO_TypeDef *GPIOx,uint8_t PINx) //GPIO 读输入
{
	if(GPIOx->IDR&(0x00000001<<PINx))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

void GPIO_Toggle(GPIO_TypeDef *GPIOx,uint8_t PINx)  //GPIO 翻转
{
	if(GPIOx->ODR&(0x00000001<<PINx))
	{
		GPIO_Write(GPIOx,PINx,GPIO_RESET);
	}
	else
	{
		GPIO_Write(GPIOx,PINx,GPIO_SET);
	}
}

void GPIO_EXIT_Init_case1(GPIO_TypeDef *GPIOx, uint8_t PINx)//检测高电平
{
    GPIO_MODE_Init(GPIOx, PINx, GPIO_MODE_INPUT);
    GPIO_EXIT_MODE_Init(GPIOx, PINx, GPIO_EXIT_HIGNLEVEL);
    GPIO_PULL_Init(GPIOx, PINx, GPIO_PULLUP);
    GPIO_INTER_enable(GPIOx, PINx);
}

void GPIO_EXIT_Init_case2(GPIO_TypeDef *GPIOx, uint8_t PINx)//检测低电平
{
    GPIO_MODE_Init(GPIOx, PINx, GPIO_MODE_INPUT);
    GPIO_EXIT_MODE_Init(GPIOx, PINx, GPIO_EXIT_LOWLEVEL);
    GPIO_PULL_Init(GPIOx, PINx, GPIO_PULLUP);
    GPIO_INTER_enable(GPIOx, PINx);
}
void GPIO_EXIT_Init_case3(GPIO_TypeDef *GPIOx, uint8_t PINx)//检测上升沿
{
    GPIO_MODE_Init(GPIOx, PINx, GPIO_MODE_INPUT);
    GPIO_EXIT_MODE_Init(GPIOx, PINx, GPIO_EXIT_RISING);
    GPIO_PULL_Init(GPIOx, PINx, GPIO_PULLUP);
    GPIO_INTER_enable(GPIOx, PINx);
}
void GPIO_EXIT_Init_case4(GPIO_TypeDef *GPIOx, uint8_t PINx)//检测下降沿
{
    GPIO_MODE_Init(GPIOx, PINx, GPIO_MODE_INPUT);
    GPIO_EXIT_MODE_Init(GPIOx, PINx, GPIO_EXIT_FALLING);
    GPIO_PULL_Init(GPIOx, PINx, GPIO_PULLUP);
    GPIO_INTER_enable(GPIOx, PINx);
}

void EXIT0_IRQHandler(void)
{
    if(EXTI->ISR&(0x1<<0))
    {
        EXTI->ISR |= 0x1<<0;
        //IRQ Handler......
    }
}

void EXIT1_IRQHandler(void)
{
    if(EXTI->ISR&(0x1<<1))
    {
        EXTI->ISR |= 0x1<<1;
        //IRQ Handler......
    }
}

void EXIT2_IRQHandler(void)
{
    if(EXTI->ISR&(0x1<<2))
    {
        EXTI->ISR |= 0x1<<2;
        //IRQ Handler......
    }
}

void EXIT3_IRQHandler(void)
{
    if(EXTI->ISR&(0x1<<3))
    {
        EXTI->ISR |= 0x1<<3;
        //IRQ Handler......
    }
}

void EXIT4_IRQHandler(void)
{
    if(EXTI->ISR&(0x1<<4))
    {
        EXTI->ISR |= 0x1<<4;
        //IRQ Handler......
    }
}

void EXIT9_5_IRQHandler(void)
{
    if(EXTI->ISR&(0x1<<5)) //外部中断 PA5
    {
        EXTI->ISR |= 0x1<<5;
        //IRQ Handler......
    }
    if(EXTI->ISR&(0x1<<6))//外部中断 PA6
    {
        EXTI->ISR |= 0x1<<6;
        //IRQ Handler......
    }
    if(EXTI->ISR&(0x1<<7)) //外部中断 PA7
    {
        EXTI->ISR |= 0x1<<7;
        //IRQ Handler......
    }
    if(EXTI->ISR&(0x1<<8)) //外部中断 PA8
    {
        EXTI->ISR |= 0x1<<8;
        //IRQ Handler......
    }
    if(EXTI->ISR&(0x1<<9)) //外部中断 PA9
    {
        EXTI->ISR |= 0x1<<9;
        //IRQ Handler......
    }
}

void EXIT15_10_IRQHandler(void)
{
    if(EXTI->ISR&(0x1<<10)) //外部中断 PA10
    {
        EXTI->ISR |= 0x1<<10;
        //IRQ Handler......
    }
    if(EXTI->ISR&(0x1<<11)) //外部中断 PA11
    {
        EXTI->ISR |= 0x1<<11;
        //IRQ Handler......
    }
    if(EXTI->ISR&(0x1<<12)) //外部中断 PA12
    {
        EXTI->ISR |= 0x1<<12;
        //IRQ Handler......
    }
    if(EXTI->ISR&(0x1<<13)) //外部中断 PA13
    {
        EXTI->ISR |= 0x1<<13;
        //IRQ Handler......
    }
    if(EXTI->ISR&(0x1<<14)) //外部中断 PA14
    {
        EXTI->ISR |= 0x1<<14;
        //IRQ Handler......
    }
    if(EXTI->ISR&(0x1<<15)) //外部中断 PA15
    {
        EXTI->ISR |= 0x1<<15;
        //IRQ Handler......
    }
}

void CAW_IRQhandler(void)//载波检测中断函数
{
	if(EXTI->ISR&(0x1<<16))
	{
		EXTI->ISR = 0x1<<16;
        //IRQ Handler......
	}
}

void CAW_Init(void)//载波检测配置
{
	GPIO_MODE_Init(GPIOA, PIN15,  GPIO_MODE_ANALOG);
	EXTI->IEN |= 0x10000;
}



