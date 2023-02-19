#ifndef I2C_H_
#define I2C_H_

//中断处理函数
void I2C_ready_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void I2C_error_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));

//应用案例
void I2C_Init_case1(void);//非中断模式
void I2C_Init_case2(void);//开启ready中断
void I2C_Init_case3(void);//开启error中断模式
void I2C_Init_case4(void);//开启 ready & error中断模式

//功能函数
void I2C_Write(uint8_t addr,uint8_t data);//适用于非中断模式
uint8_t I2C_Read(uint8_t addr);//适用于非中断模式

void I2C_Write_IT(uint8_t addr,uint8_t data);//适用于中断模式
void I2C_Read_IT(uint8_t addr,uint8_t data);//适用于中断模式







#endif

