#ifndef _LOWPOWER_H_
#define _LOWPOWER_H_


#define wfi() __asm__ __volatile__("wfi" );
#define NOP  __asm__ __volatile__("nop" );

//不同低功耗模式配置
void System_Halt(void);//待机模式 halt1
void System_Sleep(void);//睡眠模式 halt2
void System_Powerdown(void);//掉电模式 powerdown1
void System_DeepPwd(void);//掉电模式 powerdown2


void LowPower_Config_case1(void);//所有IO设置为输入，下拉
void LowPower_Config_case2(void);//所有IO设置为输入，上拉

#endif
