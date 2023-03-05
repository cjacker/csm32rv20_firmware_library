#ifndef CLIC_H_
#define CLIC_H_

#define mstatus        0x300
#define mtvec          0x305
#define mie            0x304
#define mepc           0x341
#define mcause         0x342

#define mtvt           0x307
#define mnxti          0x345
#define mintstatus     0x346

#define mcycle          0xb00

#define read_csr(reg) ({ unsigned long __tmp; \
  asm volatile ("csrr %0, " #reg : "=r"(__tmp)); \
  __tmp; })

#define write_csr(reg, val) ({ \
  if (__builtin_constant_p(val) && (unsigned long)(val) < 32) \
    asm volatile ("csrw " #reg ", %0" :: "i"(val)); \
  else \
    asm volatile ("csrw " #reg ", %0" :: "r"(val)); })

#define swap_csr(reg, val) ({ unsigned long __tmp; \
  if (__builtin_constant_p(val) && (unsigned long)(val) < 32) \
    asm volatile ("csrrw %0, " #reg ", %1" : "=r"(__tmp) : "i"(val)); \
  else \
    asm volatile ("csrrw %0, " #reg ", %1" : "=r"(__tmp) : "r"(val)); \
  __tmp; })

#define set_csr(reg, bit) ({ unsigned long __tmp; \
  if (__builtin_constant_p(bit) && (unsigned long)(bit) < 32) \
    asm volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "i"(bit)); \
  else \
    asm volatile ("csrrs %0, " #reg ", %1" : "=r"(__tmp) : "r"(bit)); \
  __tmp; })

#define clear_csr(reg, bit) ({ unsigned long __tmp; \
  if (__builtin_constant_p(bit) && (unsigned long)(bit) < 32) \
    asm volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "i"(bit)); \
  else \
    asm volatile ("csrrc %0, " #reg ", %1" : "=r"(__tmp) : "r"(bit)); \
  __tmp; })


#define MTIMER_int_ID                  7

#define SPI1_int_ID                    16
#define SPI2_int_ID                    17
#define LV_int_ID                      18
#define UART1_int_ID                   19
#define I2C_ready_int_ID               20
#define I2C_error_int_ID               21
#define TIMER1_break_int_ID            22
#define TIMER1_updata_int_ID           23
#define TIMER1_capture_int_ID          24
#define TIMER1_trigger_comm_int_ID     25
#define TIMER2_break_int_ID            26
#define TIMER2_updata_int_ID           27
#define TIMER2_capture_compare_int_ID  28
#define TIMER2_trigger_comm_int_ID     29
#define ADC_int_ID                     30
#define RF_int_ID                      31
#define WUP_int_ID                     32
#define UART2_int_ID                   33
#define UART3_int_ID                   34
#define UART4_int_ID                   35
#define COMP1_int_ID                   36
#define COMP2_int_ID                   37
#define COMP3_int_ID                   38
#define EXTI0_int_ID                   40
#define EXTI1_int_ID                   41
#define EXTI2_int_ID                   42
#define EXTI3_int_ID                   43
#define EXTI4_int_ID                   44
#define EXTI9_5_int_ID                 45
#define EXTI15_10_int_ID               46
#define CAW_int_ID                     47



#define MTVEC_DIRECT          0x0
#define MTVEC_VECTORED        0x1
#define MTVEC_CLIC_DIRECT     0x2
#define MTVEC_CLIC_VECTORED   0x3

#define INT_LEVEL0          0x00
#define INT_LEVEL1          0x40
#define INT_LEVEL2          0x80
#define INT_LEVEL3          0xc0


void trap_entry(void) __attribute__((aligned(64))) __attribute__((interrupt));

void CLIC_soft_IRQHandler(void) __attribute__((interrupt));

void CLIC_Init(void);//系统中断配置

void Interrupt_Enable(uint8_t interrupt_ID);//CLIC使能单个中断
void Interrupt_Disable(uint8_t interrupt_ID);//CLIC关闭单个中断
void Interrupt_Level(uint8_t interrupt_ID,uint8_t interrupt_level);//CLIC设置中断抢占级别

void SYS_Interrupt_Enable(void);//CLIC开总中断
void SYS_Interrupt_Disable(void);//CLIC关总中断



#endif
