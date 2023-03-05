#include "headfile.h"


uint8_t U1_outbuf[ULEN];
volatile uint8_t U1_outstart;
volatile uint8_t U1_outend;
volatile uint8_t U1_outactive;


uint8_t U1_inbuf[ULEN];
volatile uint8_t U1_instart;
volatile uint8_t U1_inend;




void UART_Init_case1(UART_TypeDef *UARTx) //非中断模式
{
    if(UARTx==UART1)
    {
        GPIO_MODE_Init(GPIOA,PIN5,GPIO_MODE_AF);
        GPIO_MODE_Init(GPIOA,PIN6,GPIO_MODE_AF);
        GPIO_AF_Init(GPIOA,PIN5,GPIO_AF0);
        GPIO_AF_Init(GPIOA,PIN6,GPIO_AF0);
    }
    else if(UARTx==UART2)
    {
        GPIO_MODE_Init(GPIOA,PIN3,GPIO_MODE_AF);
        GPIO_MODE_Init(GPIOA,PIN4,GPIO_MODE_AF);
        GPIO_AF_Init(GPIOA,PIN3,GPIO_AF3);
        GPIO_AF_Init(GPIOA,PIN4,GPIO_AF3);
    }
    else if(UARTx==UART3)
    {
        GPIO_MODE_Init(GPIOA,PIN10,GPIO_MODE_AF);
        GPIO_MODE_Init(GPIOA,PIN11,GPIO_MODE_AF);
        GPIO_AF_Init(GPIOA,PIN10,GPIO_AF3);
        GPIO_AF_Init(GPIOA,PIN11,GPIO_AF3);
    }
    else if(UARTx==UART4)
    {
        GPIO_MODE_Init(GPIOA,PIN14,GPIO_MODE_AF);
        GPIO_MODE_Init(GPIOA,PIN15,GPIO_MODE_AF);
        GPIO_AF_Init(GPIOA,PIN14,GPIO_AF3);
        GPIO_AF_Init(GPIOA,PIN15,GPIO_AF3);
    }

    UARTx->CTRL = 0<<25        //发送中断使能: 0-off,1-on
                 |0<<24        //接收中断使能：0-off,1-on
                 |0x0116<<8    //波特率（对应16M时钟）：
                               //0x1a0b-2400,0x0683-9600,0x0341-19200,0x0116-57600,0x008b-115200
                               //0x0045-230400,0x0023-460800,0x0011-921600,0x000d-1128800
                 |1<<6         //模式选择：0-模式0，1-模式1，2/3-模式2
                 |0<<5         //多处理器使能
                 |1<<4         //接收使能
                 |0<<3         //发送数据bit8
                 |0<<2        //接收数据bit8
                 |1<<1         //发送中断标志：1-清除
                 |1<<0;        //接收中断标志：1-清除
}

void UART_Init_IT_case1(UART_TypeDef *UARTx) //中断模式
{
    if(UARTx==UART1)
    {
        GPIO_MODE_Init(GPIOA,PIN5,GPIO_MODE_AF);
        GPIO_MODE_Init(GPIOA,PIN6,GPIO_MODE_AF);
        GPIO_AF_Init(GPIOA,PIN5,GPIO_AF0);
        GPIO_AF_Init(GPIOA,PIN6,GPIO_AF0);

        U1_outstart = 0;
        U1_outend = 0;
        U1_outactive = 0;

        U1_instart = 0;
        U1_inend = 0;

    }
    else if(UARTx==UART2)
    {
        GPIO_MODE_Init(GPIOA,PIN3,GPIO_MODE_AF);
        GPIO_MODE_Init(GPIOA,PIN4,GPIO_MODE_AF);
        GPIO_AF_Init(GPIOA,PIN3,GPIO_AF3);
        GPIO_AF_Init(GPIOA,PIN4,GPIO_AF3);
    }
    else if(UARTx==UART3)
    {
        GPIO_MODE_Init(GPIOA,PIN10,GPIO_MODE_AF);
        GPIO_MODE_Init(GPIOA,PIN11,GPIO_MODE_AF);
        GPIO_AF_Init(GPIOA,PIN10,GPIO_AF3);
        GPIO_AF_Init(GPIOA,PIN11,GPIO_AF3);
    }
    else if(UARTx==UART4)
    {
        GPIO_MODE_Init(GPIOA,PIN14,GPIO_MODE_AF);
        GPIO_MODE_Init(GPIOA,PIN15,GPIO_MODE_AF);
        GPIO_AF_Init(GPIOA,PIN14,GPIO_AF3);
        GPIO_AF_Init(GPIOA,PIN15,GPIO_AF3);
    }

    UARTx->CTRL = 1<<25        //发送中断使能: 0-off,1-on
                 |1<<24        //接收中断使能：0-off,1-on
                 |0x0116<<8    //波特率（对应16M时钟）：
                               //0x1a0b-2400,0x0683-9600,0x0341-19200,0x0116-57600,0x008b-115200
                               //0x0045-230400,0x0023-460800,0x0011-921600,0x000d-1128800
                 |1<<6         //模式选择：0-模式0，1-模式1，2/3-模式2
                 |0<<5         //多处理器使能
                 |1<<4         //接收使能
                 |0<<3         //发送数据bit8
                 |0<<2         //接收数据bit8
                 |1<<1         //发送中断标志：1-清除
                 |1<<0;        //接收中断标志：1-清除

}

void Uart_Send(UART_TypeDef *UARTx,uint8_t *packet,uint16_t lenth)//适用于非中断发送模式
{
	for(uint16_t i=0;i< lenth;i++)
	{
		while(UARTx->CTRL&0x00800000);
		UARTx->DATA = packet[i];
	}
	if(UARTx->CTRL&0x00000002)
		UARTx->CTRL |= 0x00000002U;
}

void Uart_Reveive(UART_TypeDef *UARTx,uint8_t *packet,uint16_t lenth)//适用于非中断接收模式
{
	for(uint16_t i=0;i< lenth;i++)
	{
	    while(!(UARTx->CTRL&0x00000001));
        packet[i] = UARTx->DATA;
		UARTx->CTRL |= 0x00000001U;
	}
}

extern uint8_t upack[500];
extern uint16_t unum;

uint8_t UART1_putbuf(uint8_t ubyte)//数据放入缓存，适用于中断模式
{
    uint8_t result = 0xff;
    Interrupt_Disable(UART1_int_ID);//CLIC关闭单个中断
    //_REG8(CLIC_INTIE_BASE,UART1_int_ID) = 0;//关闭串口中断

    if(U1_outstart + ULEN != U1_outend )
    {
        U1_outbuf[U1_outend++&(ULEN-1)] = ubyte;
        //upack[unum++] = ubyte;
        result = 0;
    }


    if((U1_outactive==0)&&((UART1->CTRL&0x00800000) == 0))
    {
        UART1->DATA = U1_outbuf[U1_outstart++&(ULEN-1)];
        U1_outactive = 1;
    }

    Interrupt_Enable(UART1_int_ID);//CLIC使能单个中断
    //_REG8(CLIC_INTIE_BASE,UART1_int_ID) = 1;//开启串口中断
    return result;
}

uint8_t UART1_getbuf(void)//阻塞取数据缓存
{
    while(U1_inend == U1_instart) NOP;
    return (U1_inbuf[U1_instart++&(ULEN-1)]);
}

uint8_t UART1_getbuf_noblock(uint8_t *pdata)//非阻塞取数据缓存
{
    if(U1_inend == U1_instart)
        return 0xff;
    *pdata = U1_inbuf[U1_instart++&(ULEN-1)];
    return 0;
}

void UART1_IRQhandler(void)
{
	if(UART1->CTRL&0x1)  //接收中断标志
	{
	    UART1->CTRL = (UART1->CTRL&0xfffffffd)|0x1;//清除接收中断
	    //IRQ Hander......


        if( U1_instart + ULEN != U1_inend)
        {
            U1_inbuf[U1_inend++&(ULEN-1)] = UART1->DATA;
        }

        //UART1_putbuf(UART1->DATA);

        //if(U1_inend != U1_instart)
        //{
            //UART1_putbuf(UART1_getbuf());
        //}

	}

	if(UART1->CTRL&0x2)  //发送中断标志
	{
	    UART1->CTRL = (UART1->CTRL&0xfffffffe)|0x2;//清除发送中断
	    //IRQ Hander......

	    if(U1_outstart != U1_outend)
        {
            UART1->DATA = U1_outbuf[U1_outstart++&(ULEN-1)];
        }
        else
        {
            U1_outactive = 0;
        }
	}

}

void UART2_IRQhandler(void)
{
	if(UART2->CTRL&0x1)  //接收中断标志
	{
	    UART2->CTRL = (UART2->CTRL&0xfffffffd)|0x1;//清除接收中断
        //IRQ Hander......
	}

	if(UART2->CTRL&0x2)  //发送中断标志
	{
	    UART2->CTRL = (UART2->CTRL&0xfffffffe)|0x2;//清除发送中断
        //IRQ Hander......
	}
}

void UART3_IRQhandler(void)
{
	if(UART3->CTRL&0x1)  //接收中断标志
	{
	    UART3->CTRL = (UART3->CTRL&0xfffffffd)|0x1;//清除接收中断
        //IRQ Hander......
	}

	if(UART3->CTRL&0x2)  //发送中断标志
	{
	    UART3->CTRL = (UART3->CTRL&0xfffffffe)|0x2;//清除发送中断
        //IRQ Hander......
	}
}

void UART4_IRQhandler(void)
{
    //GPIO_Toggle(GPIOA,PIN8); //GPIO 翻转
	if(UART4->CTRL&0x1)  //接收中断标志
	{
	    UART4->CTRL = (UART4->CTRL&0xfffffffd)|0x1;//清除接收中断

        //IRQ Hander......
	}

	if(UART4->CTRL&0x2)  //发送中断标志
	{

	    UART4->CTRL = (UART4->CTRL&0xfffffffe)|0x2;//清除发送中断
        //IRQ Hander......
	}
}
