#include "headfile.h"

void IWDG_Init(uint16_t count)//配置看门狗计数值（时钟频率3K）
{
	IWDG->KR = 0x5555;

	NOP;//键值0x5555后要延时1个时钟，才能写RLR

	IWDG->RLR = count;
}

void IWDG_Start(void) //启动看门狗
{
	IWDG->KR = 0xcccc;
}

void IWDG_Refresh(void) //喂狗
{
	IWDG->KR = 0xaaaa;
}








