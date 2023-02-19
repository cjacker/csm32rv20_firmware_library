#ifndef SPI_H_
#define SPI_H_

void SPI1_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));//SPI1 中断函数
void SPI2_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));//SPI2 中断函数

void SPI_Init_case1(SPI_TypeDef *SPIx);//非中断模式
void SPI_Init_case2(SPI_TypeDef *SPIx);//中断模式

void SPI_Transceive(SPI_TypeDef *SPIx,uint8_t *Txpack,uint8_t *Rxpack,uint16_t lenth);//非中断模式

void SPI1_CSN_Init_case1(void);//CFG: CE-GPIO7,CSN-GPIO8
uint8_t SPI1_RW_reg(uint8_t Addr,uint8_t Data);//读写Si24R1寄存器

void SPI2_CSN_Init_case1(void);//CFG: CE-GPIO7,CSN-GPIO8
uint8_t SPI2_RW_reg(uint8_t Addr,uint8_t Data);//读写Si24R1寄存器









#endif /* DRIVERS_INC_SPI_H_ */
