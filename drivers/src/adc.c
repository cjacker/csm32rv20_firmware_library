#include "headfile.h"



void ADC_Init_case1(void)//内部基准，测量PA4输入电压
{
    ADC->ISR = 0x04;//清除ADC中断
    ADC->CCR =   0<<20 //CCR[21:20]----------测试控制：00-关闭，01-VREFP输出，10-VREFN输出，11-Vt温度传感器输出
                 |1<<19 //CCR[19]---------内部通道增益：0-1，1-1/4
                 |0<<16 //CCR[21:20]-----------PGA增益：000-1，001-2，010-4......111-128
                 |1<<13 //CCR[15:13]------内部基准选择：0-(1.7~0.498V)，1-(1.214~0V)
                 |0<<12 //CCR[12]-------------基准来源：0-内部基准，1-外部基准
                 |0<<8  //CCR[11:8]---------转换前延时：0000-不延时，0001-2^0个ADC时钟，0010-2^1个ADC时钟...1111-2^14个ADC时钟
                 |3<<6  //CCR[7:6]------------时钟分频：00-不分频，01-2分频...11-8分频（时钟<=4M）
                 |0<<5  //CCR[5]1/2VDD电压采集通道使能：0-关闭，1-使能
                 |0<<4  //CCR[4]----------GPIO触发模式：0-上升沿触发，1-下降沿触发
                 |0<<2  //CCR[7:6]----------触发信号源：00-软件触发，01/10-保留，11-GPIO触发
                 |0<<1  //CCR[1]--------------采样模式：0-单次模式，1-连续模式
                 |1<<0; //CCR[0]--------------电源开关：0-OFF，1-ON

    Delay32M_us(20);//ADC电源开启需要时间

    ADC->SEL = 3; //测量通道选择：0-PTAT,1-1/2VDD,2-PAD3,3-PAD4,4-PAD5,5-PAD6,6-PAD7,7-PAD8,8-PAD9,9-PAD10,10-NTC,11-VDD,其它-无

    GPIO_MODE_Init(GPIOA,PIN4,GPIO_MODE_ANALOG);//设置GPIO为ADC输入
}

void ADC_Init_case2(void)//外部基准，测量PA4输入电压
{
    ADC->ISR = 0x04;//清除ADC中断
    ADC->CCR =   0<<20  //CCR[21:20]----------测试控制：00-关闭，01-VREFP输出，10-VREFN输出，11-Vt温度传感器输出
                 |1<<19  //CCR[19]---------内部通道增益：0-1，1-1/4
                 |0<<16  //CCR[21:20]-----------PGA增益：000-1，001-2，010-4......111-128
                 |1<<13  //CCR[15:13]------内部基准选择：0-(1.7~0.498V)，1-(1.214~0V)
                 |1<<12  //CCR[12]-------------基准来源：0-内部基准，1-外部基准
                 |0<<8   //CCR[11:8]---------转换前延时：0000-不延时，0001-2^0个ADC时钟，0010-2^1个ADC时钟...1111-2^14个ADC时钟
                 |3<<6   //CCR[7:6]------------时钟分频：00-不分频，01-2分频...11-8分频（时钟<=4M）
                 |0<<5   //CCR[5]1/2VDD电压采集通道使能：0-关闭，1-使能
                 |0<<4   //CCR[4]----------GPIO触发模式：0-上升沿触发，1-下降沿触发
                 |0<<2   //CCR[7:6]----------触发信号源：00-软件触发，01/10-保留，11-GPIO触发
                 |0<<1   //CCR[1]--------------采样模式：0-单次模式，1-连续模式
                 |1<<0;  //CCR[0]--------------电源开关：0-OFF，1-ON

    Delay32M_us(20);//ADC电源开启需要时间

    ADC->SEL = 3; //测量通道选择：0-PTAT,1-1/2VDD,2-PAD3,3-PAD4,4-PAD5,5-PAD6,6-PAD7,7-PAD8,8-PAD9,9-PAD10,10-NTC,11-VDD,其它-无

    GPIO_MODE_Init(GPIOA,PIN4,GPIO_MODE_ANALOG);//设置GPIO为ADC输入
    GPIO_MODE_Init(GPIOA,PIN9,GPIO_MODE_ANALOG);//设置GPIO为ADC外部基准输入
    GPIO_MODE_Init(GPIOA,PIN10,GPIO_MODE_ANALOG);//设置GPIO为ADC外部基准输入

}

void ADC_Init_case3(void)////内部基准，测量NTC输入电压
{
    ADC->ISR = 0x04;//清除ADC中断
    ADC->CCR =   0<<20 //CCR[21:20]----------测试控制：00-关闭，01-VREFP输出，10-VREFN输出，11-Vt温度传感器输出
                 |1<<19 //CCR[19]---------内部通道增益：0-1，1-1/4
                 |0<<16 //CCR[21:20]-----------PGA增益：000-1，001-2，010-4......111-128
                 |1<<13 //CCR[15:13]------内部基准选择：0-(1.7~0.498V)，1-(1.214~0V)
                 |0<<12 //CCR[12]-------------基准来源：0-内部基准，1-外部基准
                 |0<<8  //CCR[11:8]---------转换前延时：0000-不延时，0001-2^0个ADC时钟，0010-2^1个ADC时钟...1111-2^14个ADC时钟
                 |3<<6  //CCR[7:6]------------时钟分频：00-不分频，01-2分频...11-8分频（时钟<=4M）
                 |0<<5  //CCR[5]1/2VDD电压采集通道使能：0-关闭，1-使能
                 |0<<4  //CCR[4]----------GPIO触发模式：0-上升沿触发，1-下降沿触发
                 |0<<2  //CCR[7:6]----------触发信号源：00-软件触发，01/10-保留，11-GPIO触发
                 |0<<1  //CCR[1]--------------采样模式：0-单次模式，1-连续模式
                 |1<<0; //CCR[0]--------------电源开关：0-OFF，1-ON

    Delay32M_us(20);//ADC电源开启需要时间

    ADC->SEL = 10; //测量通道选择：0-PTAT,1-1/2VDD,2-PAD3,3-PAD4,4-PAD5,5-PAD6,6-PAD7,7-PAD8,8-PAD9,9-PAD10,10-NTC,11-VDD,其它-无

    GPIO_MODE_Init(GPIOA,PIN11,GPIO_MODE_ANALOG);//设置GPIO为NTC功能脚
    GPIO_MODE_Init(GPIOA,PIN12,GPIO_MODE_ANALOG);//设置GPIO为NTC功能脚
    GPIO_MODE_Init(GPIOA,PIN13,GPIO_MODE_ANALOG);//设置GPIO为NTC功能脚

}


uint32_t ADC_Conversion(void)//适用于非中断模式
{
    uint32_t adc_result;

    //控制寄存器
    ADC->CR = 1; //1：开启转换，0：结束转换
    while(!(ADC->ISR&0x04));
    adc_result = ADC->DR;

    return adc_result;
}

void ADC_Soft_Start(void)//软件触发ADC，适用于中断模式
{
    ADC->IER = 0x4; //使能ADC中断
    ADC->CR = 1;    //开始转换
}

//extern uint32_t adc_result;
void ADC_IRQHandler(void)
{
    uint32_t adc_result;

    if(ADC->ISR&0x04)//
    {
        ADC->CR = 0;    //关闭ADC转换
        ADC->ISR = 0x04;//清除ADC中断

        adc_result = ADC->DR; //读取数据

        printf("adc_result:%d\r\n",adc_result);

        //GPIO_Toggle(GPIOA,PIN9);
    }
}






