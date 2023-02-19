#include "headfile.h"



uint32_t JumpAddress;
typedef void(*pFunction)(void);
uint8_t (*my_flash_operation)(uint8_t code,uint16_t addr,uint8_t *p,uint16_t num,uint8_t clk);//flash 虏脵脳梅潞炉脢媒脭颅脨脥



void NVR_RW_Test(void)
{
    /**/
    uint8_t flash_pack[32]={0};
    my_flash_operation = MY_FLASH_OPERATION_Addr;

	//read
	my_flash_operation(code_read_NVR, 0, flash_pack, 20, 0);
    Uart_Send(UART1,flash_pack,20);

	//write 鍦板潃4瀵归綈
	for(uint16_t i=0;i<32;i++)
	{
		flash_pack[i] = i;
	}
	my_flash_operation(code_write_NVR, 4, flash_pack, 10, 0);

	//read
    for(uint16_t i=0;i<32;i++)
	{
		flash_pack[i] = 1;
	}
	my_flash_operation(code_read_NVR, 0, flash_pack, 20, 0);
	Uart_Send(UART1,flash_pack,20);

	//erase
	my_flash_operation(code_erase_NVR, 0, flash_pack, 20, 0);

	//read
	my_flash_operation(code_read_NVR, 0, flash_pack, 20, 0);
	Uart_Send(UART1,flash_pack,20);

}

void Flash_RW_Test(void)
{
    /**/
    uint8_t flash_pack[32]={0};
    my_flash_operation = MY_FLASH_OPERATION_Addr;

	//read
	my_flash_operation(code_read_bytes, APP1_OFFSET, flash_pack, 20, 0);
    Uart_Send(UART1,flash_pack,20);

 	//erase
	my_flash_operation(code_erase_sector, APP1_OFFSET, flash_pack, 20, 0);

	//read
    my_flash_operation(code_read_bytes, APP1_OFFSET, flash_pack, 20, 0);
	Uart_Send(UART1,flash_pack,20);

	//write 鍦板潃4瀵归綈
	for(uint16_t i=0;i<32;i++)
	{
		flash_pack[i] = i;
	}
	my_flash_operation(code_write_bytes, APP1_OFFSET, flash_pack, 10, 0);

	//read
    for(uint16_t i=0;i<32;i++)
	{
		flash_pack[i] = 0;
	}
	my_flash_operation(code_read_bytes, APP1_OFFSET, flash_pack, 20, 0);
	Uart_Send(UART1,flash_pack,20);



}















