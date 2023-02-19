#include "headfile.h"

void System_Clock_Init(void)//系统时钟初始化
{
    //时钟源开关
    CMU->SRC_EN  = 1<<1   //RCOSC    bit[1]:0-off, 1-on
                  |1<<0;  //crystal  bit[0]:0-off, 1-on

    //外设和内核时钟来源选择
	CMU->CLK_SEL = 1<<2   //peripheral  bit[3:2]:0-RCOSC, 1-crystal, 2-LSI(3K), 3-reserved
                  |1<<0;  //cpu         bit[1:0]:0-RCOSC, 1-crystal, 2-LSI(3K), 3-reserved

    //设置时钟分频系数
    CMU->CLK_DIV = 0<<10  //RTC         bit[14:10]:0-2, 1-2, 2-2, 3-2, 4-4, 5-4, 6-6, 7-6 ......
                  |0<<5   //peripheral  bit[9:5]:0-1, 1-1, 2-2, 3-3, 4-4, 5-5,......31-31
                  |0<<0;  //CPU         bit[9:5]:0-1, 1-1, 2-2, 3-3, 4-4, 5-5,......31-31

    //外设时钟使能
    CMU->PER_EN  = 1;    //bit[0]:0-off, 1-on

    //RC频率选择
    CMU_RC_DEFAULT->RC_DEFAULT = 0; //bit[0]:0-16MHz, 1-32MHz

}

void Delay16M_ms(uint16_t Delay)//16M主频下的ms延时函数
{
    uint32_t cyclestart = read_csr(mcycle);
    uint32_t wait = 16000*Delay;

    while(read_csr(mcycle)-cyclestart < wait)
    {

    }
}

void Delay16M_us(uint16_t Delay)//16M主频下的us延时函数
{
    uint32_t cyclestart = read_csr(mcycle);
    uint32_t wait = 16*Delay;

    while(read_csr(mcycle)-cyclestart < wait)
    {
    }
}


void Delay32M_ms(uint16_t Delay)//32M主频下的ms延时函数
{
    uint32_t cyclestart = read_csr(mcycle);
    uint32_t wait = 32000*Delay;

    while(read_csr(mcycle)-cyclestart < wait)
    {
    }
}

void Delay32M_us(uint16_t Delay)//32M主频下的us延时函数
{
    uint32_t cyclestart = read_csr(mcycle);
    uint32_t wait = 32*Delay;

    while(read_csr(mcycle)-cyclestart < wait)
    {
    }
}







