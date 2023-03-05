#include "headfile.h"





void Data_Always_Test1(void)//DATA_ALWAYS，PD2模式的数据保存
{
    //DATA_ALWAYS 数据共8字节，按字访问，共两个字长
/**/
    //定义访问指针
    uint32_t *pdata_always32 = (uint32_t *)DATA_ALWAYS_BASE;

    //读取data_always
    //ee_printf("\ndata_always:");

    //ee_printf(" %x",pdata_always32[0]);
    //ee_printf(" %x",pdata_always32[1]);

    pdata_always32[0]+=0x11111111;
    pdata_always32[1]+=0x22222222;

    //配置唤醒中断，这里使用PA2，检测下降沿
    GPIO_EXTI_Init_case4(GPIOA, PIN2);//检测下降沿


    //进入powerdown2模式，唤醒后程序从头开始执行
    Delay32M_ms(1000);
    System_DeepPwd();//掉电模式 powerdown2

}


















