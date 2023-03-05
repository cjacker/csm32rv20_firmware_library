#ifndef FLASH_H_
#define FLASH_H_


#define MY_FLASH_OPERATION_Addr 0x21000fe2  //2021

#define code_erase_sector 1
#define code_erase_NVR    2
#define code_erase_chip   3
#define code_write_bytes  4
#define code_read_bytes   5
#define code_write_NVR    6
#define code_read_NVR     7


#define APP1_OFFSET 0x5000



void NVR_RW_Test(void);//NVR read and write test
void Flash_RW_Test(void);//flash read and write test


#endif
