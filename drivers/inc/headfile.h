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
















#endif
