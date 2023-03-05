#include "headfile.h"


void SPI_Init_case1(SPI_TypeDef *SPIx)//非中断模式
{
    if(SPIx==SPI1)
    {
        //用户自选CSN，软件操作片选信号


        //配置SCK
        GPIO_MODE_Init(GPIOA, PIN2, GPIO_MODE_AF);  //PA2复用模式
        GPIO_AF_Init(GPIOA,  PIN2,  GPIO_AF0);  //PA2复用到SPI1_SCK

        //配置MISO
        GPIO_MODE_Init(GPIOA, PIN3, GPIO_MODE_AF);  //PA3复用模式
        GPIO_AF_Init(GPIOA,  PIN3,  GPIO_AF0);  //PA3复用到SPI1_MISO

        //配置MOSI
        GPIO_MODE_Init(GPIOA, PIN4, GPIO_MODE_AF);  //PA4复用模式
        GPIO_AF_Init(GPIOA,  PIN4,  GPIO_AF0);  //PA4复用到SPI1_MOSI
    }

    if(SPIx==SPI2)
    {
        //用户自选CSN，软件操作片选信号


        //配置SCK
        GPIO_MODE_Init(GPIOB, PIN2, GPIO_MODE_AF);  //PB2复用模式
        GPIO_AF_Init(GPIOB,  PIN2,  GPIO_AF0);  //PB2复用到SPI1_SCK

        //配置MISO
        GPIO_MODE_Init(GPIOB, PIN3, GPIO_MODE_AF);  //PB3复用模式
        GPIO_AF_Init(GPIOB,  PIN3,  GPIO_AF0);  //PB3复用到SPI1_MOSI

        //配置MOSI
        GPIO_MODE_Init(GPIOB, PIN4, GPIO_MODE_AF);  //PB4复用模式
        GPIO_AF_Init(GPIOB,  PIN4,  GPIO_AF0);  //PB4复用到SPI1_MISO
    }

    SPIx->STATUS1 = 0;
    SPIx->CTRL = 0x0<<8     //中断使能：0-关闭，1-开启
                |0x0<<7     //时钟极性：0-低电平，1-高电平
                |0x0<<6     //时钟相位：0-前沿采样，后沿输出，1-前沿输出，后沿采样，
                |0x1<<4     //SPI使能：0-关闭，1-使能
                |0x3;       //时钟分频：0-2分频，1-2分频，2-2分频，3-8分频，4-16分频，5-32分频，6-64分频，其他：64分频

}

void SPI_Init_case2(SPI_TypeDef *SPIx)//中断模式
{
    if(SPIx==SPI1)
    {
        //用户自选CSN，软件操作片选信号


        //配置SCK
        GPIO_MODE_Init(GPIOA, PIN2, GPIO_MODE_AF);  //PA2复用模式
        GPIO_AF_Init(GPIOA,  PIN2,  GPIO_AF0);  //PA2复用到SPI1_SCK

        //配置MISO
        GPIO_MODE_Init(GPIOA, PIN3, GPIO_MODE_AF);  //PA3复用模式
        GPIO_AF_Init(GPIOA,  PIN3,  GPIO_AF0);  //PA3复用到SPI1_MISO

        //配置MOSI
        GPIO_MODE_Init(GPIOA, PIN4, GPIO_MODE_AF);  //PA4复用模式
        GPIO_AF_Init(GPIOA,  PIN4,  GPIO_AF0);  //PA4复用到SPI1_MOSI
    }

    if(SPIx==SPI2)
    {
        //用户自选CSN，软件操作片选信号


        //配置SCK
        GPIO_MODE_Init(GPIOB, PIN2, GPIO_MODE_AF);  //PB2复用模式
        GPIO_AF_Init(GPIOB,  PIN2,  GPIO_AF0);  //PB2复用到SPI1_SCK

        //配置MISO
        GPIO_MODE_Init(GPIOB, PIN3, GPIO_MODE_AF);  //PB3复用模式
        GPIO_AF_Init(GPIOB,  PIN3,  GPIO_AF0);  //PB3复用到SPI1_MOSI

        //配置MOSI
        GPIO_MODE_Init(GPIOB, PIN4, GPIO_MODE_AF);  //PB4复用模式
        GPIO_AF_Init(GPIOB,  PIN4,  GPIO_AF0);  //PB4复用到SPI1_MISO
    }

    SPIx->STATUS1 = 0;
    SPIx->CTRL = 0x1<<8     //中断使能：0-关闭，1-开启
                |0x0<<7     //时钟极性：0-低电平，1-高电平
                |0x0<<6     //时钟相位：0-前沿采样，后沿输出，1-前沿输出，后沿采样，
                |0x1<<4     //SPI使能：0-关闭，1-使能
                |0x3;       //时钟分频：0-2分频，1-2分频，2-2分频，3-8分频，4-16分频，5-32分频，6-64分频，其他：64分频

}

void SPI_Transceive(SPI_TypeDef *SPIx,uint8_t *Txpack,uint8_t *Rxpack,uint16_t lenth)//非中断模式
{
    while(SPIx->STATUS1&0x01);
    SPIx->STATUS1 = 0;

    for(uint16_t i=0;i<lenth;i++)
	{
		SPIx->DATA = Txpack[i];
		while(SPIx->STATUS1&0x01);
		Rxpack[i] = SPIx->DATA;

		SPIx->STATUS1 = 0;//clear interrupt flag
	}
}

void SPI1_CSN_Init_case1(void)//CFG: CE-GPIO7,CSN-GPIO8
{
    GPIO_MODE_Init(GPIOA,PIN8,GPIO_MODE_OUTPUT);//CSN
    GPIO_Write(GPIOA,PIN8,GPIO_SET);//CSN=1

    GPIO_MODE_Init(GPIOA,PIN7,GPIO_MODE_OUTPUT);//CE
    GPIO_Write(GPIOA,PIN7,GPIO_RESET);//CE=0
}

uint8_t SPI1_RW_reg(uint8_t Addr,uint8_t Data)//读写Si24R1寄存器
{
    uint8_t sTxpack[2];
    uint8_t sRxpack[2];
    sTxpack[0] = Addr;
    sTxpack[1] = Data;
    GPIO_Write(GPIOA,PIN8,GPIO_SET);//CSN=1
    GPIO_Write(GPIOA,PIN8,GPIO_RESET);//CSN=0
    SPI_Transceive(SPI1,sTxpack,sRxpack,2);//非中断模式
    GPIO_Write(GPIOA,PIN8,GPIO_SET);//CSN=1

    return sRxpack[1];
}

void SPI2_CSN_Init_case1(void)//CFG: CE-GPIO7,CSN-GPIO8
{
    GPIO_MODE_Init(GPIOB,PIN0,GPIO_MODE_OUTPUT);//CE
    GPIO_Write(GPIOB,PIN0,GPIO_RESET);//CE=0

    GPIO_MODE_Init(GPIOB,PIN1,GPIO_MODE_OUTPUT);//CSN
    GPIO_Write(GPIOB,PIN1,GPIO_SET);//CSN=1

}

uint8_t SPI2_RW_reg(uint8_t Addr,uint8_t Data)//读写Si24R1寄存器
{
    uint8_t sTxpack[2];
    uint8_t sRxpack[2];
    sTxpack[0] = Addr;
    sTxpack[1] = Data;
    GPIO_Write(GPIOB,PIN1,GPIO_SET);//CSN=1
    GPIO_Write(GPIOB,PIN1,GPIO_RESET);//CSN=0
    SPI_Transceive(SPI1,sTxpack,sRxpack,2);//非中断模式
    GPIO_Write(GPIOB,PIN1,GPIO_SET);//CSN=1

    return sRxpack[1];
}

void SPI1_IRQhandler(void)//SPI1 中断函数
{
	if(SPI1->STATUS1&0x10)
	{
	    SPI1->STATUS1 = 0;
	    //IRQ Hander......

	}
}

void SPI2_IRQhandler(void)//SPI2 中断函数
{
	if(SPI2->STATUS1&0x10)
	{
	    SPI2->STATUS1 = 0;
        //IRQ Hander......

	}
}





