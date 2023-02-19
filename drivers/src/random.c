#include "headfile.h"




uint32_t RAND_Get(void)//生成随机数
{
	uint32_t rand = 0;
	uint32_t temp;

	RAND->RDGCR = 0x1; //0-OFF,1-ON
	delay16M_ms(1);

	while(!(RAND->RDGCR&0x02));
	rand = RAND->RDGDR;//get random number
    RAND->RDGCR = 0x0; //0-OFF,1-ON

	return rand;
}


