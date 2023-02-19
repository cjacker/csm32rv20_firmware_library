#include "headfile.h"


void I2C_Init_case1(void)//非中断模式
{
    GPIO_MODE_Init(GPIOA, PIN7,  GPIO_MODE_AF);
	GPIO_MODE_Init(GPIOA, PIN8,  GPIO_MODE_AF);

	GPIO_AF_Init(GPIOA,  PIN7,  GPIO_AF0); //SCL
	GPIO_AF_Init(GPIOA,  PIN8,  GPIO_AF0); //SDA

	GPIO_PULL_Init(GPIOA, PIN7,GPIO_PULLUP);
	GPIO_PULL_Init(GPIOA, PIN8,GPIO_PULLUP);

	I2C->STATUS1 &= ~0x11; //清除中断标志
    I2C->CTRL =  0<<12    //时钟分频：0-不分频，1-2分频
                |0<<9     //error中断：0-关闭，1-开启
                |0<<8     //ready中断：0-关闭，1-开启
                |0<<7     //时钟频率：0-100K，1-400K
                |0x28;    //从机地址

}

void I2C_Init_case2(void)//开启ready中断
{
    GPIO_MODE_Init(GPIOA, PIN7,  GPIO_MODE_AF);
	GPIO_MODE_Init(GPIOA, PIN8,  GPIO_MODE_AF);

	GPIO_AF_Init(GPIOA,  PIN7,  GPIO_AF0);
	GPIO_AF_Init(GPIOA,  PIN8,  GPIO_AF0);

	GPIO_PULL_Init(GPIOA, PIN7,GPIO_PULLUP);
	GPIO_PULL_Init(GPIOA, PIN8,GPIO_PULLUP);

	I2C->STATUS1 &= ~0x11; //清除中断标志
    I2C->CTRL =  0<<12    //时钟分频：0-不分频，1-2分频
                |0<<9     //error中断：0-关闭，1-开启
                |1<<8     //ready中断：0关闭，1-开启
                |0<<7     //时钟频率;0-100K，1-400K
                |0x28;    //从机地址
}

void I2C_Init_case3(void)//开启error中断模式
{
    GPIO_MODE_Init(GPIOA, PIN7,  GPIO_MODE_AF);
	GPIO_MODE_Init(GPIOA, PIN8,  GPIO_MODE_AF);

	GPIO_AF_Init(GPIOA,  PIN7,  GPIO_AF0); //SCL
	GPIO_AF_Init(GPIOA,  PIN8,  GPIO_AF0); //SDA

	GPIO_PULL_Init(GPIOA, PIN7,GPIO_PULLUP);
	GPIO_PULL_Init(GPIOA, PIN8,GPIO_PULLUP);

	I2C->STATUS1 &= ~0x11; //清除中断标志
    I2C->CTRL =  0<<12    //时钟分频：0-不分频，1-2分频
                |1<<9     //error中断：0-关闭，1-开启
                |0<<8     //ready中断：0-关闭，1-开启
                |0<<7     //时钟频率：0-100K，1-400K
                |0x28;    //从机地址
}

void I2C_Init_case4(void)//开启 ready & error中断模式
{
    GPIO_MODE_Init(GPIOA, PIN7,  GPIO_MODE_AF);
	GPIO_MODE_Init(GPIOA, PIN8,  GPIO_MODE_AF);

	GPIO_AF_Init(GPIOA,  PIN7,  GPIO_AF0); //SCL
	GPIO_AF_Init(GPIOA,  PIN8,  GPIO_AF0); //SDA

	GPIO_PULL_Init(GPIOA, PIN7,GPIO_PULLUP);
	GPIO_PULL_Init(GPIOA, PIN8,GPIO_PULLUP);

	I2C->STATUS1 &= ~0x11; //清除中断标志
    I2C->CTRL =  0<<12    //时钟分频：0-不分频，1-2分频
                |1<<9     //error中断：0-关闭，1-开启
                |1<<8     //ready中断：0-关闭，1-开启
                |0<<7     //时钟频率：0-100K，1-400K
                |0x28;    //从机地址
}

void I2C_Write(uint8_t addr,uint8_t data)//适用于非中断模式
{
	uint32_t i2c_rw_en = 0x0<<16; //i2c操作：0-写操作，1-读操作
	uint32_t i2c_addr = addr<<8;  //存储单元地址
	uint32_t i2c_rwdata = data;   //数据

	I2C->STATUS1 = 0; //清除状态标志
	I2C->DATA = i2c_rw_en|i2c_addr|i2c_rwdata;//写数据

    while(!(I2C->STATUS1&0x01));

	I2C->STATUS1 = 0;
}

uint8_t I2C_Read(uint8_t addr)//适用于非中断模式
{
	uint32_t i2c_r_wn = 0x1;   //i2c操作：0-写操作，1-读操作
	uint32_t i2c_addr = addr;  //存储单元地址
    uint8_t i2c_rwdata;

	I2C->STATUS1 = 0;
	I2C->DATA = (i2c_r_wn<<16)|(i2c_addr<<8);

	while(!(I2C->STATUS1&0x01));

	i2c_rwdata = I2C->DATA;

	I2C->STATUS1 = 0;
	return i2c_rwdata;
}

void I2C_Write_IT(uint8_t addr,uint8_t data)//适用于中断模式
{
	uint32_t i2c_rw_en = 0x0<<16; //i2c操作：0-写操作，1-读操作
	uint32_t i2c_addr = addr<<8; //地址
	uint32_t i2c_rwdata = data;  //数据

	I2C->DATA = i2c_rw_en|i2c_addr|i2c_rwdata;

}

void I2C_Read_IT(uint8_t addr,uint8_t data)//适用于中断模式
{
	uint32_t i2c_rw_en = 0x0<<16; //i2c操作：0-写操作，1-读操作
	uint32_t i2c_addr = addr<<8; //地址
	uint32_t i2c_rwdata = data;  //数据

	I2C->DATA = i2c_rw_en|i2c_addr|i2c_rwdata;

}

void I2C_ready_IRQhandler(void)
{
	if(I2C->STATUS1&0x01) //查询中断标志
	{
	    I2C->STATUS1 &= ~0x01; //清除中断标志
         //IRQ Hander......
         //GPIO_Write(GPIOA,PIN14,GPIO_SET);
         //GPIO_Write(GPIOA,PIN14,GPIO_RESET);

	}
}

void I2C_error_IRQhandler(void)
{
	if(I2C->STATUS1&0x10) //查询中断标志
	{
        I2C->STATUS1 &= ~0x10; //清除中断标志
        //IRQ Hander......
        //GPIO_Write(GPIOA,PIN14,GPIO_SET);
        //GPIO_Write(GPIOA,PIN14,GPIO_RESET);
	}

}


