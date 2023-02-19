#ifndef CSM32RV20_H_
#define CSM32RV20_H_

#include "stdint.h"

typedef struct
{
	volatile uint32_t PER_EN;
	volatile uint32_t CLK_SEL;
	volatile uint32_t CLK_DIV;
	volatile uint32_t SRC_EN;
	volatile uint32_t OSC_SR;
}CMU_TypeDef;


typedef struct
{
	volatile uint32_t RC_DEFAULT;
}CMU_RC_DEFAULT_TypeDef;


typedef struct
{
	volatile uint32_t MSIP;
	volatile uint32_t MTIMECMP;
	volatile uint32_t MTIME;
}CLIC_TypeDef;


typedef struct
{
	volatile uint32_t CLICINTIP;
	volatile uint32_t CLICINTIE;
	volatile uint32_t CLICINTCFG;
	volatile uint32_t CLICCFG;
}CLIC2_TypeDef;


typedef struct
{
	volatile uint8_t RESERVED0;
	volatile uint8_t RESERVED1;
	volatile uint8_t RESERVED2;
	volatile uint8_t MSIP;
	volatile uint8_t RESERVED4;
	volatile uint8_t RESERVED5;
	volatile uint8_t RESERVED6;
	volatile uint8_t MTIP;
	volatile uint8_t RESERVED8;
	volatile uint8_t RESERVED9;
	volatile uint8_t RESERVED10;
	volatile uint8_t MEIP;
	volatile uint8_t CSIP;
	volatile uint8_t RESERVED13;
	volatile uint8_t RESERVED14;
	volatile uint8_t RESERVED15;
	volatile uint8_t SPI1;
	volatile uint8_t SPI2;
	volatile uint8_t LV;
	volatile uint8_t UART;
	volatile uint8_t I2C_READY;
	volatile uint8_t I2C_ERROR;
	volatile uint8_t TIMER1_BREAK;
	volatile uint8_t TIMER1_UPDATA;
	volatile uint8_t TIMER1_CAPURE_COMPARE;
	volatile uint8_t TIMER1_TRRIGER_COMMUTATION;
	volatile uint8_t TIMER2_BREAK;
	volatile uint8_t TIMER2_UPDATA;
	volatile uint8_t TIMER2_CAPURE_COMPARE;
	volatile uint8_t TIMER2_TRRIGER_COMMUTATION;
	volatile uint8_t ADC;
	volatile uint8_t R1;
	volatile uint8_t WUP;
	volatile uint8_t RESERVED33;
	volatile uint8_t RESERVED34;
	volatile uint8_t RESERVED35;
	volatile uint8_t RESERVED36;
	volatile uint8_t RESERVED37;
	volatile uint8_t RESERVED38;
	volatile uint8_t RESERVED39;
	volatile uint8_t EXTI0;
	volatile uint8_t EXTI1;
	volatile uint8_t EXTI2;
	volatile uint8_t EXTI3;
	volatile uint8_t EXTI4;
	volatile uint8_t EXTI5_9;
	volatile uint8_t EXTI10_15;
	volatile uint8_t EXTI16;
}CLIC_INTIE_TypeDef;


typedef struct
{
	volatile uint32_t STATUS1;
	volatile uint32_t CTRL;
	volatile uint32_t DATA;
}I2C_TypeDef;


typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t DATA;
}UART_TypeDef;


typedef struct
{
	volatile uint32_t CR1;
	volatile uint32_t ICF;
	volatile uint32_t IER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t RCR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t BDTR;
}TIMERx_TypeDef;


typedef struct
{
	volatile uint32_t CLKEN;
}TIMER_CLKEN_TypeDef;


typedef struct
{
	volatile uint32_t CLKEN;
}TIMER_TypeDef;

typedef struct
{
	volatile uint32_t CTRL;
	volatile uint32_t DATA;
	volatile uint32_t STATUS1;

}SPI_TypeDef;

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t ITYPER;
	volatile uint32_t PUPDR;
	volatile uint32_t SDR;
	volatile uint32_t LPMR;
	volatile uint32_t INTER;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSR;
	volatile uint32_t AFRH;
	volatile uint32_t AFRL;
}GPIO_TypeDef;

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t ITYPER;
	volatile uint32_t PUPDR;
	volatile uint32_t SDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSR;
	volatile uint32_t AFRH;
	volatile uint32_t AFRL;
}GPIOB_TypeDef;


typedef struct
{
	volatile uint32_t UNLOCK;
	volatile uint32_t MODE;
}DFT_TypeDef;


typedef struct
{
	volatile uint32_t RDGCR;
	volatile uint32_t RDGDR;
}RAND_TypeDef;


typedef struct
{
	volatile uint32_t ISR;
	volatile uint32_t IER;
	volatile uint32_t CR;
	volatile uint32_t SEL;
	volatile uint32_t DR;
	volatile uint32_t CCR;
	volatile uint32_t TESTA;
	volatile uint32_t TESTB;

}ADC_TypeDef;


typedef struct
{
	volatile uint32_t KR;
	volatile uint32_t RLR;
	volatile uint32_t SR;
}IWDG_TypeDef;


typedef struct
{
	volatile uint32_t ISR;
	volatile uint32_t IEN;
}EXTI_TypeDef;


typedef struct
{
	volatile uint32_t CE;
	volatile uint32_t VSS;
	volatile uint32_t CSN;
	volatile uint32_t IRQ_EN;
	volatile uint32_t IRQ;
	volatile uint32_t IOSEL;
}R1_TypeDef;


typedef struct
{
	volatile uint32_t IRQ_EN;
	volatile uint32_t IRQ;
}LV_TypeDef;


typedef struct
{
	volatile uint32_t EN;
}SFT_TypeDef;

typedef struct
{
	volatile uint32_t CLK_CFG;
	volatile uint32_t CLK_RESULT;
}TRIM_TypeDef;

typedef struct
{
    volatile uint32_t CFG1;
	volatile uint32_t CFG2;
	volatile uint32_t TEST;
	volatile uint32_t RESERVE1;
	volatile uint32_t ADCCFG;
	volatile uint32_t ADCEXCFG;
	volatile uint32_t ADCEFF;
}ANA_TypeDef;


typedef struct
{
	volatile uint32_t FCTRL_REG;
	volatile uint32_t FWDATA_REG;
	volatile uint32_t FADDR_REG;
	volatile uint32_t KEY1;
}FLASH_CTRL_TypeDef;


typedef struct
{
	volatile uint32_t MODE;
}LPMODE_TypeDef;

typedef struct
{
	volatile uint32_t DATA;
	volatile uint32_t IRQ_EN;
	volatile uint32_t IRQ;
}WUP_TypeDef;


typedef struct
{
	volatile uint64_t mtime;
}RTC_MTIME_TypeDef;

typedef struct
{
	volatile uint64_t mtimecmp;
}RTC_MTIMECMP_TypeDef;


typedef struct
{
	volatile uint32_t control;
	volatile uint32_t irq;
	volatile uint32_t result;
}COMP_TypeDef;


//绯荤粺瀛樺偍鏄犲皠
#define DEBUG_BASE           0x00000100UL
#define CLIC_BASE            0x02000000UL
#define RTC_MTIME_BASE       0x0200bff8UL
#define RTC_MTIMECMP_BASE    0x02004000UL
#define CLIC2_BASE           0x02800000UL
#define CLIC_INTIP_BASE      0x02800000UL
#define CLIC_INTIE_BASE      0x02800400UL
#define CLIC_INTCFG_BASE     0x02800800UL
#define CLIC_CFG_BASE        0x02800c00UL
#define FLASH_BASE           0x20000000UL
#define NVR_BASE             0x20010000UL
#define SRAM_BASE            0x20020FFFUL
#define DATA_ALWAYS_BASE     0x20028000UL
#define ROM_BASE             0x21000000UL
#define I2C_BASE             0x30000004UL
#define UART1_BASE           0x30000010UL
#define TIMER1_BASE          0x30000018UL
#define TIMER2_BASE          0x30000098UL
#define TIMER_CLKEN_BASE     (TIMER2_BASE+0x00000068UL)
#define SPI1_BASE            0x30000060UL
#define SPI2_BASE            0x30000070UL
#define GPIOA_BASE           0x30000200UL
#define GPIOB_BASE           0x30000240UL
#define	SCAN_BASE            0x30000230UL
#define RAND_BASE            0x30000238UL
#define ADC_BASE             0x30000280UL
#define IWDG_BASE            0x300002A0UL
#define EXTI_BASE            0x300002C0UL
#define CMU_BASE             0x300002E4UL
#define R1_BASE              0x30000300UL
#define LV_BASE              0x30000330UL
#define SFT_BASE             0x30000360UL
#define TRIM_BASE            0x30000380UL
#define ANA_BASE             0x30000400UL
#define FLASH_CTRL_BASE      0x30000500UL
#define LPMODE_BASE          0x30000600UL
#define WUP_BASE             0x30000610UL
#define UART2_BASE           0x30000700UL
#define UART3_BASE           0x30000800UL
#define UART4_BASE           0x30000900UL
#define BOOTWDG_BASE         0x30000A00UL
#define COMP1_BASE           0x30000B00UL
#define COMP2_BASE           0x30000C00UL
#define COMP3_BASE           0x30000D00UL
#define RC_DEFAULT_BASE      0x30000E00UL


#define CLIC             ((CLIC_TypeDef *)CLIC_BASE)
#define CLIC2            ((CLIC2_TypeDef *)CLIC2_BASE)
#define CLIC_INTIP       ((CLIC_INTIP_TypeDef *)CLIC_INTIP_BASE)
#define CLIC_INTIE       ((CLIC_INTIE_TypeDef *)CLIC_INTIE_BASE)
#define CLIC_INTCFG      ((CLIC_INTCFG_TypeDef *)CLIC_INTCFG_BASE)
#define CLIC_CFG         ((CLIC_CFG_TypeDef *)CLIC_CFG_BASE))
#define I2C              ((I2C_TypeDef *)I2C_BASE)
#define UART1            ((UART_TypeDef *)UART1_BASE)
#define UART2            ((UART_TypeDef *)UART2_BASE)
#define UART3            ((UART_TypeDef *)UART3_BASE)
#define UART4            ((UART_TypeDef *)UART4_BASE)
#define TIMER1           ((TIMERx_TypeDef *)TIMER1_BASE)
#define TIMER2           ((TIMERx_TypeDef *)TIMER2_BASE)
#define TIMER_CLKEN      ((TIMER_CLKEN_TypeDef *)TIMER_CLKEN_BASE)
#define SPI1             ((SPI_TypeDef *)SPI1_BASE)
#define SPI2             ((SPI_TypeDef *)SPI2_BASE)
#define GPIOA            ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB            ((GPIO_TypeDef *)GPIOB_BASE)
#define SCAN             ((SCAN_TypeDef *)SCAN_BASE)
#define RAND             ((RAND_TypeDef *)RAND_BASE)
#define ADC              ((ADC_TypeDef *)ADC_BASE)
#define IWDG             ((IWDG_TypeDef *)IWDG_BASE)
#define EXTI             ((EXTI_TypeDef *)EXTI_BASE)
#define CMU              ((CMU_TypeDef *)CMU_BASE)
#define R1               ((R1_TypeDef *)R1_BASE)
#define LV               ((LV_TypeDef *)LV_BASE)
#define SFT              ((SFT_TypeDef *)SFT_BASE)
#define TRIM             ((TRIM_TypeDef *)TRIM_BASE)
#define ANA              ((ANA_TypeDef *)ANA_BASE)
#define FLASH_CTRL       ((FLASH_CTRL_TypeDef *)FLASH_CTRL_BASE)
#define LPMODE           ((LPMODE_TypeDef *)LPMODE_BASE)
#define WUP              ((WUP_TypeDef *)WUP_BASE)
#define RTC_MTIME        ((RTC_MTIME_TypeDef *)RTC_MTIME_BASE)
#define RTC_MTIMECMP     ((RTC_MTIMECMP_TypeDef *)RTC_MTIMECMP_BASE)
#define COMP1            ((COMP_TypeDef *)COMP1_BASE)
#define COMP2            ((COMP_TypeDef *)COMP2_BASE)
#define COMP3            ((COMP_TypeDef *)COMP3_BASE)
#define CMU_RC_DEFAULT   ((CMU_RC_DEFAULT_TypeDef *)RC_DEFAULT_BASE)


#define _REG32(p,i) (*(volatile uint32_t *)((p)+(i)))
#define  _REG8(p,i) (*(volatile uint8_t *)((p)+(i)))


#endif

