#ifndef IWDG_H_
#define IWDG_H_



void IWDG_Init(uint16_t count); //配置看门狗计数值（时钟频率3K）
void IWDG_Start(void); //启动看门狗
void IWDG_Refresh(void); //喂狗




#endif


