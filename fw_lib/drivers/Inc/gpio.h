#ifndef GPIO_H_
#define GPIO_H_


#define PIN0       ((uint8_t)0x00)
#define PIN1       ((uint8_t)0x01)
#define PIN2       ((uint8_t)0x02)
#define PIN3       ((uint8_t)0x03)
#define PIN4       ((uint8_t)0x04)
#define PIN5       ((uint8_t)0x05)
#define PIN6       ((uint8_t)0x06)
#define PIN7       ((uint8_t)0x07)
#define PIN8       ((uint8_t)0x08)
#define PIN9       ((uint8_t)0x09)
#define PIN10      ((uint8_t)0x0a)
#define PIN11      ((uint8_t)0x0b)
#define PIN12      ((uint8_t)0x0c)
#define PIN13      ((uint8_t)0x0d)
#define PIN14      ((uint8_t)0x0e)
#define PIN15      ((uint8_t)0x0f)
#define PINALL     ((uint8_t)0x10)

#define GPIO_MODE_INPUT       0x00000000UL
#define GPIO_MODE_OUTPUT      0x00000001UL
#define GPIO_MODE_AF          0x00000002UL
#define GPIO_MODE_ANALOG      0x00000003UL

#define GPIO_OTYPE_ODOS_OFF   0x00000000UL
#define GPIO_OTYPE_OD_ON      0x00000001UL
#define GPIO_OTYPE_OS_ON      0x00010000UL
#define GPIO_OTYPE_ODOS_ON    0x00010001UL

#define GPIO_ITYPE_SCHMIDT    0x00010000UL
#define GPIO_ITYPE_CMOSE      0x00000001UL

#define GPIO_NOPULL           0x00000000UL
#define GPIO_PULLUP           0x00000001UL
#define GPIO_PULLDOWN         0x00000002UL

#define GPIO_SPEED_0          0x00000000UL
#define GPIO_SPEED_1          0x00000001UL
#define GPIO_SPEED_2          0x00010000UL
#define GPIO_SPEED_3          0x00010001UL

#define GPIO_SET              0x00000001UL
#define GPIO_RESET            0x00010000UL

#define GPIO_AF0              0x00000000UL
#define GPIO_AF1              0x00000001UL
#define GPIO_AF2              0x00000002UL
#define GPIO_AF3              0x00000003UL

#define GPIO_EXTI_HIGNLEVEL   0x00000000UL  //检测高电平
#define GPIO_EXTI_FALLING     0x00000001UL  //检测下降沿
#define GPIO_EXTI_RISING      0x00000002UL  //检测上升沿
#define GPIO_EXTI_LOWLEVEL    0x00000003UL  //检测低电平


void GPIO_MODE_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_MODEx); //GPIO 模式
void GPIO_OutType_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_OTYPEx); //GPIO 输出模式
void GPIO_InType_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_ITYPEx); //GPIO 输入模式
void GPIO_PULL_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_PULLx); //GPIO 上拉
void GPIO_OutSpeed_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_SPEEDx); //GPIO 压摆率
void GPIO_AF_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_AFx); //GPIO 复用模式
void GPIO_EXTI_MODE_Init(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_EXTI_MODEx); //GPIO 中断模式
void GPIO_INTER_enable(GPIO_TypeDef *GPIOx,uint8_t PINx); //GPIO 中断使能
void GPIO_INTER_disable(GPIO_TypeDef *GPIOx,uint8_t PINx); //GPIO 中断关闭

void GPIO_Write(GPIO_TypeDef *GPIOx,uint8_t PINx,uint32_t GPIO_PinState); //GPIO 输出
uint8_t GPIO_Read(GPIO_TypeDef *GPIOx,uint8_t PINx); //GPIO 读输入
void GPIO_Toggle(GPIO_TypeDef *GPIOx,uint8_t PINx);  //GPIO 翻转

void GPIO_EXTI_Init_case1(GPIO_TypeDef *GPIOx, uint8_t PINx); //检测高电平
void GPIO_EXTI_Init_case2(GPIO_TypeDef *GPIOx, uint8_t PINx); //检测低电平
void GPIO_EXTI_Init_case3(GPIO_TypeDef *GPIOx, uint8_t PINx); //检测上升沿
void GPIO_EXTI_Init_case4(GPIO_TypeDef *GPIOx, uint8_t PINx); //检测下降沿


void CLIC_EXTI0_IRQHandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_EXTI1_IRQHandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_EXTI2_IRQHandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_EXTI3_IRQHandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_EXTI4_IRQHandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_EXTI9_5_IRQHandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_EXTI15_10_IRQHandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));

void CLIC_CAW_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));//载波检测中断函数
void CAW_Init(void);//载波检测配置



#endif
