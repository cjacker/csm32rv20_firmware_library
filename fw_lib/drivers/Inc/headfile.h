#ifndef HEADFILE_H_
#define HEADFILE_H_


#define GPIO_MODULAR
#define CMU_MODULAR
#define UART_MODULAR
#define SPI_MODULAR
#define TIMER_MODULAR
#define RANDOM_MODULAR
#define LOWPOWER_MODULAR
#define IWDG_MODULAR
#define RTC_MODULAR
#define I2C_MODULAR
#define ADC_MODULAR
#define WUP_MODULAR
#define LV_MODULAR
#define FLASH_MODULAR
#define CLIC_MODULAR
#define COMP_MODULAR


#include "CSM32RV20.h"
#include "stdio.h"

#ifdef GPIO_MODULAR
    #include "gpio.h"
#endif

#ifdef CMU_MODULAR
    #include "cmu.h"
#endif

#ifdef UART_MODULAR
    #include "uart.h"
#endif

#ifdef SPI_MODULAR
    #include "spi.h"
#endif

#ifdef TIMER_MODULAR
    #include "timer.h"
#endif

#ifdef RANDOM_MODULAR
    #include "random.h"
#endif

#ifdef LOWPOWER_MODULAR
    #include "lowpower.h"
#endif

#ifdef IWDG_MODULAR
    #include "iwdg.h"
#endif

#ifdef RTC_MODULAR
    #include "rtc.h"
#endif

#ifdef I2C_MODULAR
    #include "i2c.h"
#endif

#ifdef ADC_MODULAR
    #include "adc.h"
#endif

#ifdef WUP_MODULAR
    #include "wup.h"
#endif

#ifdef LV_MODULAR
    #include "lv.h"
#endif

#ifdef FLASH_MODULAR
    #include "flash.h"
#endif

#ifdef CLIC_MODULAR
    #include "clic.h"
#endif

#ifdef COMP_MODULAR
    #include "comp.h"
#endif


#define  soft_IRQHandler                          CLIC_soft_IRQHandler
#define  RTC_IRQhandler                           CLIC_RTC_IRQhandler
#define  SPI1_IRQhandler                          CLIC_SPI1_IRQhandler
#define  SPI2_IRQhandler                          CLIC_SPI2_IRQhandler
#define  LV_IRQhandler                            CLIC_LV_IRQhandler
#define  UART1_IRQhandler                         CLIC_UART1_IRQhandler
#define  I2C_ready_IRQhandler                     CLIC_I2C_ready_IRQhandler
#define  I2C_error_IRQhandler                     CLIC_I2C_error_IRQhandler
#define  Timer1_Break_IRQhandler                  CLIC_Timer1_Break_IRQhandler
#define  Timer1_Update_IRQhandler                 CLIC_Timer1_Update_IRQhandler
#define  Timer1_Capture_Compare_IRQhandler        CLIC_Timer1_Capture_Compare_IRQhandler
#define  Timer1_Trigger_Commutation_IRQhandler    CLIC_Timer1_Trigger_Commutation_IRQhandler
#define  Timer2_Break_IRQhandler                  CLIC_Timer2_Break_IRQhandler
#define  Timer2_Update_IRQhandler                 CLIC_Timer2_Update_IRQhandler
#define  Timer2_Capture_Compare_IRQhandler        CLIC_Timer2_Capture_Compare_IRQhandler
#define  Timer2_Trigger_Commutation_IRQhandler    CLIC_Timer2_Trigger_Commutation_IRQhandler
#define  ADC_IRQHandler                           CLIC_ADC_IRQHandler
#define  WUP_IRQhandler                           CLIC_WUP_IRQhandler
#define  UART2_IRQhandler                         CLIC_UART2_IRQhandler
#define  UART3_IRQhandler                         CLIC_UART3_IRQhandler
#define  UART4_IRQhandler                         CLIC_UART4_IRQhandler
#define  COMP1_IRQhandler                         CLIC_COMP1_IRQhandler
#define  COMP2_IRQhandler                         CLIC_COMP2_IRQhandler
#define  COMP3_IRQhandler                         CLIC_COMP3_IRQhandler
#define  EXTI0_IRQHandler                         CLIC_EXTI0_IRQHandler
#define  EXTI1_IRQHandler                         CLIC_EXTI1_IRQHandler
#define  EXTI2_IRQHandler                         CLIC_EXTI2_IRQHandler
#define  EXTI3_IRQHandler                         CLIC_EXTI3_IRQHandler
#define  EXTI4_IRQHandler                         CLIC_EXTI4_IRQHandler
#define  EXTI9_5_IRQHandler                       CLIC_EXTI9_5_IRQHandler
#define  EXTI15_10_IRQHandler                     CLIC_EXTI15_10_IRQHandler
#define  CAW_IRQhandler                           CLIC_CAW_IRQhandler




#endif
