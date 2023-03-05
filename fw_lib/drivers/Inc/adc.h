#ifndef ADC_H_
#define ADC_H_

//中断处理函数
void CLIC_ADC_IRQHandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));

//应用案例
void ADC_Init_case1(void);//内部基准，测量PA4输入电压
void ADC_Init_case2(void);//外部基准，测量PA4输入电压
void ADC_Init_case3(void);//内部基准，测量NTC输入电压

//功能函数
uint32_t ADC_Conversion(void);//适用于非中断模式
void ADC_Soft_Start(void);//软件触发ADC，适用于中断模式



#endif

