#include "headfile.h"



void COMP1_Init(void)//COPM1
{
    GPIO_MODE_Init(GPIOB, PIN6, GPIO_MODE_ANALOG);
    GPIO_MODE_Init(GPIOB, PIN7, GPIO_MODE_ANALOG);

    COMP1->irq = 1; //清除中断标志
    COMP1->control =  0<<4 //control[6:4]-refsel-比较基准选择：0-PAD, 1-0.3V, 2-0.6V, 3-0.9V, 4-1.2V
                    | 1<<3 //control[3]-retio-工作速率选择：0-低速， 1-高速
                    | 1<<2 //control[2]-irqen-中断使能：1-使能， 0-关闭
                    | 3<<0;//control[1:0]-modesel-中断边沿选择：0-高电平检测，1-下降沿检测， 2-上升沿检测，3-低电平检测
}

void COMP2_Init(void)//COPM2
{
    GPIO_MODE_Init(GPIOB, PIN8, GPIO_MODE_ANALOG);
    GPIO_MODE_Init(GPIOB, PIN9, GPIO_MODE_ANALOG);

    COMP2->irq = 1; //清除中断标志
    COMP2->control =  0<<4 //control[6:4]-refsel-比较基准选择：0-PAD, 1-0.3V, 2-0.6V, 3-0.9V, 4-1.2V
                    | 1<<3 //control[3]-retio-工作速率选择：0-低速， 1-高速
                    | 1<<2 //control[2]-irqen-中断使能：1-使能， 0-关闭
                    | 0<<0;//control[1:0]-modesel-中断边沿选择：0-高电平检测，1-下降沿检测， 2-上升沿检测，3-低电平检测
}

void COMP3_Init(void)//COPM3
{
    GPIO_MODE_Init(GPIOB, PIN10, GPIO_MODE_ANALOG);
    GPIO_MODE_Init(GPIOB, PIN11, GPIO_MODE_ANALOG);

    COMP3->irq = 1; //清除中断标志
    COMP3->control =  0<<4 //control[6:4]-refsel-比较基准选择：0-PAD, 1-0.3V, 2-0.6V, 3-0.9V, 4-1.2V
                    | 1<<3 //control[3]-retio-工作速率选择：0-低速， 1-高速
                    | 1<<2 //control[2]-irqen-中断使能：1-使能， 0-关闭
                    | 0<<0;//control[1:0]-modesel-中断边沿选择：0-高电平检测，1-下降沿检测， 2-上升沿检测，3-低电平检测
}

void COMP1_IRQhandler(void)//COPM1中断函数
{
    if(COMP1->irq&0x1)
    {
        COMP1->irq = 1;
        //GPIO_Write(GPIOB,PIN1,GPIO_SET);
        //GPIO_Write(GPIOB,PIN1,GPIO_RESET);
    }
}

void COMP2_IRQhandler(void)//COPM2中断函数
{
    if(COMP2->irq&0x1)
    {
        COMP2->irq = 1;
        //GPIO_Write(GPIOB,PIN2,GPIO_SET);
        //GPIO_Write(GPIOB,PIN2,GPIO_RESET);
    }
}

void COMP3_IRQhandler(void)//COPM1中断函数
{
    if(COMP3->irq&0x1)
    {
        COMP3->irq = 1;
        //GPIO_Write(GPIOB,PIN3,GPIO_SET);
        //GPIO_Write(GPIOB,PIN3,GPIO_RESET);
    }
}

void COMP_test_GPIO_Init(void)
{
    GPIO_MODE_Init(GPIOB,PIN1,GPIO_MODE_OUTPUT);
    GPIO_MODE_Init(GPIOB,PIN2,GPIO_MODE_OUTPUT);
    GPIO_MODE_Init(GPIOB,PIN3,GPIO_MODE_OUTPUT);
}


