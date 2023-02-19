#include "headfile.h"



int main(void)
{

    ///----System Init ---------------------------------------------------------------------------------------------
    CLIC_Init();//系统中断配置
    System_Clock_Init();//系统时钟初始化

    ///----Chapter 3 LowPower Test Init ---------------------------------------------------------------------------------
    //低功耗测功耗需要IO不能悬空
    //Delay32M_ms(5000);
    //LowPower_Config_case1();//所有IO设置为输入，下拉
    //LowPower_Config_case2();//所有IO设置为输入，上拉

    //使用外部中断唤醒
    //GPIO_EXIT_Init_case1(GPIOA, PIN2);//检测高电平
    //Interrupt_Level(EXIT2_int_ID, INT_LEVEL0);//CLIC设置中断抢占级别
    //Interrupt_Enable(EXIT2_int_ID);//CLIC使能EXIT中断
    //SYS_Interrupt_Enable();//CLIC开总中断

    //配置不同低功耗模式
    //System_Halt();//待机模式 halt1
    //System_Sleep();//睡眠模式 halt2
    //System_Powerdown();//掉电模式 powerdown1
    //System_DeepPwd();//掉电模式 powerdown2

    ///----Chapter 5 GPIO Test Init ---------------------------------------------------------------------------------
    GPIO_MODE_Init(GPIOA,PIN8,GPIO_MODE_OUTPUT); //GPIO 模式
    //GPIO_MODE_Init(GPIOA,PIN10,GPIO_MODE_OUTPUT); //GPIO 模式
    //GPIO_MODE_Init(GPIOA,PIN12,GPIO_MODE_OUTPUT); //GPIO 模式
    //GPIO_MODE_Init(GPIOA,PIN14,GPIO_MODE_OUTPUT); //GPIO 模式
    //GPIO_MODE_Init(GPIOA,PIN15,GPIO_MODE_OUTPUT); //GPIO 模式

    //GPIO_Write(GPIOA,PIN8,GPIO_SET); //GPIO 输出
    //GPIO_Write(GPIOA,PIN10,GPIO_SET); //GPIO 输出
    //GPIO_Write(GPIOA,PIN12,GPIO_SET); //GPIO 输出
    //GPIO_Write(GPIOA,PIN14,GPIO_RESET); //GPIO 输出
    //GPIO_Write(GPIOA,PIN15,GPIO_RESET); //GPIO 输出

    //GPIO_Toggle(GPIOA,PIN15); //GPIO 翻转
    //GPIO_MODE_Init(GPIOA,PIN15,GPIO_MODE_INTPUT); //GPIO 模式
    for(uint8_t i=0;i<10;i++)
    {
        GPIO_Toggle(GPIOA,PIN8); //GPIO 翻转
        Delay32M_ms(100);
    }

    ///---- Chapter 6 EXIT Test Init -------------------------------------------------------------------------------------
    //GPIO_EXIT_Init_case1(GPIOA, PIN2);//检测高电平
    //GPIO_EXIT_Init_case2(GPIOA, PIN2);//检测低电平
    //GPIO_EXIT_Init_case3(GPIOA, PIN2);//检测上升沿
    //GPIO_EXIT_Init_case4(GPIOA, PIN2);//检测下降沿

    //Interrupt_Level(EXIT2_int_ID, INT_LEVEL0);//CLIC设置中断抢占级别
    //Interrupt_Enable(EXIT2_int_ID);//CLIC使能EXIT中断

    //载波检测中断
    //CAW_Init();//载波检测
    //Interrupt_Enable(CAW_int_ID);//CLIC使能中断

    //SYS_Interrupt_Enable();//CLIC开总中断

    ///---- Chapter 7 RTC Test Init --------------------------------------------------------------------------------------
    //RTC_Init_case1();
    //RTC_Init_case2();

    //Interrupt_Level(MTIMER_int_ID, INT_LEVEL2 );//CLIC设置中断抢占级别
    //Interrupt_Enable(MTIMER_int_ID);//CLIC使能中断
    //SYS_Interrupt_Enable();//CLIC开总中断

    ///---- Chapter 8 IWDG Test Init -------------------------------------------------------------------------------------
    //IWDG_Init(9000); //配置看门狗计数值（时钟频率3K）
    //Delay32M_ms(1000);
    //IWDG_Start(); //启动看门狗
    //IWDG_Refresh(); //喂狗

    ///---- Chapter 9 Timer Test Init ------------------------------------------------------------------------------------
    //GPIO_MODE_Init(GPIOB,PIN11,GPIO_MODE_OUTPUT); //GPIO 模式
    //GPIO_MODE_Init(GPIOA,PIN9,GPIO_MODE_OUTPUT);
    //GPIO_MODE_Init(GPIOA,PIN11,GPIO_MODE_OUTPUT);
    //GPIO_MODE_Init(GPIOA,PIN13,GPIO_MODE_OUTPUT);

    //外设配置
    //Timer1_UpCounting_Mode_Init();//向上计数
	//Timer1_6StepPWM_Mode_Init();//6stepPWM输出
    //Timer2_UpCounting_Mode_Init();//向上计数
    //Timer2_DownCounting_Mode_Init();//向下计数
    //Timer2_ExternalClock_Mode_Init();//外部时钟
    //Timer2_InputCapture_Mode_Init();//输入捕获
    //Timer2_PWM_InputCapture_Mode_Init();//PWM输入捕获
    //Timer2_Input_XOR_Mode_Init();//输入异或
    //Timer2_PWM_Mode_Init();//PWM输出
    //Timer2_6StepPWM_Mode_Init();//6stepPWM输出

    //设置中断优先级
    //Interrupt_Level(TIMER1_updata_int_ID, INT_LEVEL1);//CLIC设置中断抢占级别

    //使能外设中断
    //Interrupt_Enable(TIMER1_break_int_ID);//CLIC使能中断
    //Interrupt_Enable(TIMER1_updata_int_ID);//CLIC使能中断
    //Interrupt_Enable(TIMER1_capture_compare_int_ID);//CLIC使能中断
    //Interrupt_Enable(TIMER1_trigger_comm_int_ID);//CLIC使能中断

    //Interrupt_Enable(TIMER2_break_int_ID);//CLIC使能中断
    //Interrupt_Enable(TIMER2_updata_int_ID);//CLIC使能中断
    //Interrupt_Enable(TIMER2_capture_compare_int_ID);//CLIC使能中断
    //Interrupt_Enable(TIMER2_trigger_comm_int_ID);//CLIC使能中断

    //使能系统总中断
    //SYS_Interrupt_Enable();//CLIC开总中断

    ///---- Chapter 10 WUP Test Init -------------------------------------------------------------------------------------
    //GPIO_MODE_Init(GPIOA,PIN2,GPIO_MODE_OUTPUT);
    //GPIO_MODE_Init(GPIOA,PIN3,GPIO_MODE_OUTPUT);

    //WUP_Init_case1(9000);//设置中断周期,使能WUP中断
    //Interrupt_Enable(WUP_int_ID);//CLIC使能中断
    //SYS_Interrupt_Enable();//CLIC开总中断

    //配置不同低功耗模式
    //System_Halt();//待机模式 halt1
    //System_Sleep();//睡眠模式 halt2
    //System_Powerdown();//掉电模式 powerdown1
    //System_DeepPwd();//掉电模式 powerdown2

    ///---- Chapter 11 ADC Test Init -------------------------------------------------------------------------------------
    /*
    uint32_t adc_result;
    uint32_t adc_pack[16];
    uint32_t adc_sum;
    uint32_t adc_count;
    uint32_t adc_avr;
    uint32_t voltage_avr;
    */
    //ADC_Init_case1();//内部基准，测PA4
    //ADC_Init_case2();//外部基准，测PA4
    //Interrupt_Enable(ADC_int_ID);//CLIC使能单个中断
    //SYS_Interrupt_Enable();//CLIC开总中断

    ///---- Chapter 12 I2C Test Init -------------------------------------------------------------------------------------
    //uint8_t i2c_data;
    //I2C_Init_case1();//非中断模式
    //I2C_Init_case2();//ready中断模式
    //I2C_Init_case3();//error中断模式
    //I2C_Init_case4();//ready & error中断模式

    //Interrupt_Enable(I2C_ready_int_ID);//CLIC使能i2c_ready中断
    //Interrupt_Enable(I2C_error_int_ID);//CLIC使能i2c_error中断
    //SYS_Interrupt_Enable();//CLIC开总中断

    ///---- Chapter 13 SPI1 Test Init ------------------------------------------------------------------------------------
    //uint8_t sTxpack[10] = {0,1,2,3,4,5,6,7,8,9};
    //uint8_t sRxpack[10] = {0,1,2,3,4,5,6,7,8,9};
    //uint8_t REG_Data;

    //SPI1 Init Test
    //SPI_Init_case1(SPI1);//非中断模式
    //SPI1_CSN_Init_case1();//CFG: CE-GPIO7,CSN-GPIO8
    //SPI_Init_case2(SPI1);//中断模式
    //Interrupt_Enable(SPI1_int_ID);//CLIC使能单个中断

    //SPI2 Init Test
    //SPI_Init_case1(SPI2);//非中断模式
    //SPI2_CSN_Init_case1();//CFG: CE-GPIO7,CSN-GPIO8
    //SPI_Init_case2(SPI2);//中断模式
    //Interrupt_Enable(SPI2_int_ID);//CLIC使能单个中断


    ///---- Chapter 15 UART Test Init -------------------------------------------------------------------------------
    //uint8_t upack1[20] = {0,1,2,3,4,5,6,7,8,9};
    //uint8_t upack2[20] = {0,1,2,3,4,5,6,7,8,9};
    //uint8_t upack3[20] = {0,1,2,3,4,5,6,7,8,9};
    //uint8_t upack4[20] = {10,1,2,3,4,5,6,7,8,9};

    UART_Init_case1(UART1);//非中断模式
    //UART_Init_case1(UART2);//非中断模式
    //UART_Init_case1(UART3);//非中断模式
    //UART_Init_case1(UART4);//非中断模式

    //UART_Init_IT_case1(UART1);//中断模式
    //UART_Init_IT_case1(UART4);//中断模式
    //Interrupt_Enable(UART1_int_ID);//CLIC使能单个中断
    //Interrupt_Enable(UART4_int_ID);//CLIC使能单个中断

    //SYS_Interrupt_Enable();//CLIC开总中断
    //printf("uart init:\r\n");

    ///---- Chapter 16 LV Test Init --------------------------------------------------------------------------------------
    //LV_Init_case1(12);//设置低压报警阈值
    //LV_Interrupt_Enable();//使能低压报警中断
    //Interrupt_Enable(LV_int_ID);//CLIC使能单个中断
    //SYS_Interrupt_Enable();//CLIC开总中断

    ///---- Chapter 17 RANDGEN Test Init ---------------------------------------------------------------------------------
    //uint32_t rand_data;

    ///---- Chapter 18 compare Test Init ---------------------------------------------------------------------------------
    //COPM1_Init();//COPM1
    //Interrupt_Enable(COMP1_int_ID);//CLIC使能单个中断
    //COPM2_Init();//COPM2
    //Interrupt_Enable(COMP2_int_ID);//CLIC使能单个中断
    //COPM3_Init();//COPM3
    //Interrupt_Enable(COMP3_int_ID);//CLIC使能单个中断
    //SYS_Interrupt_Enable();//CLIC开总中断

    ///---- Chapter 22 flash Test Init ----------------------------------------------------------------------------------
    //NVR_RW_Test();//NVR read and write test
    //Flash_RW_Test();

    ///---- data_always test---------------------------------------------------------------------------------------------
    //Data_Always_Test1();//DATA_ALWAYS，PD2模式的数据保存


    ///---- 系统总中断控制 -------------------------------------------------------------------------------------------------
    //SYS_Interrupt_Enable();//CLIC开总中断
    //SYS_Interrupt_Disable();//CLIC关总中断

    //ee_printf("\nHello CSM32RV20:");
    //printf("Hello CSM32RV20:\r\n");

	while(1)
	{
        Delay32M_ms(500);
        //Delay16M_ms(500);
        //Delay16M_us(500000);
        //GPIO_Toggle(GPIOA,PIN15);
        GPIO_Toggle(GPIOA,PIN8);
        //printf("main:\r\n");

        ///---- Chapter 6 EXIT test ---------------------------------------------------------------------------------
        //delay16M_ms(500);
        //GPIO_Toggle(GPIOA,PIN15);


        ///---- Chapter 8 IWDG test ---------------------------------------------------------------------------------
        //IWDG_Refresh();
        //delay16M_ms(500);
        //GPIO_Toggle(GPIOA,PIN15);

        ///---- Chapter 9 Timer test --------------------------------------------------------------------------------
        //---- soft break --------------------------------------------------------------------------------------
        //delay16M_ms(100);
        //TIMER2->BDTR |= 1 <<15;//BDTR[15]-MOE-主输出使能:0-关闭，1-使能
        //delay16M_ms(100);
        //TIMER2->EGR |= 1 <<7;//EGR[7]-BG-产生刹车事件
        //---- soft COM ----------------------------------------------------------------------------------------
        //delay16M_ms(100);
        //TIMER2->EGR = 1 <<5;//EGR[5]-COMG-捕获/比较事件，产生控制更新
        //---- generate oxr ------------------------------------------------------------------------------------
        /*
        Delay16M_ms(10);//1
        GPIO_Write(GPIOA,PIN9,GPIO_SET);
        GPIO_Write(GPIOA,PIN11,GPIO_RESET);
        GPIO_Write(GPIOA,PIN13,GPIO_SET);
        Delay16M_ms(10);//2
        GPIO_Write(GPIOA,PIN9,GPIO_SET);
        GPIO_Write(GPIOA,PIN11,GPIO_RESET);
        GPIO_Write(GPIOA,PIN13,GPIO_RESET);
        Delay16M_ms(10);//3
        GPIO_Write(GPIOA,PIN9,GPIO_SET);
        GPIO_Write(GPIOA,PIN11,GPIO_SET);
        GPIO_Write(GPIOA,PIN13,GPIO_RESET);
        Delay16M_ms(10);//4
        GPIO_Write(GPIOA,PIN9,GPIO_RESET);
        GPIO_Write(GPIOA,PIN11,GPIO_SET);
        GPIO_Write(GPIOA,PIN13,GPIO_RESET);
        Delay16M_ms(10);//5
        GPIO_Write(GPIOA,PIN9,GPIO_RESET);
        GPIO_Write(GPIOA,PIN11,GPIO_SET);
        GPIO_Write(GPIOA,PIN13,GPIO_SET);
        Delay16M_ms(10);//6
        GPIO_Write(GPIOA,PIN9,GPIO_RESET);
        GPIO_Write(GPIOA,PIN11,GPIO_RESET);
        GPIO_Write(GPIOA,PIN13,GPIO_SET);
        */

        ///---- Chapter 11 ADC test ---------------------------------------------------------------------------------
        /*
        adc_result = ADC_Conversion();//适用于非中断模式
	    //printf("adc_val:%d\r\n",adc_result);
	    adc_pack[(adc_count++)&0xf] = adc_result;
	    adc_sum=0;
        for(uint8_t i=0;i<16;i++)
        {
            adc_sum += adc_pack[i];
        }
        adc_avr = adc_sum/16;
        printf("val:%d  avr:%d %d.%dmV   %d.%dmV\r\n",adc_result,adc_avr,(adc_result*4*12000/32768)/10,(adc_result*4*12000/32768)%10,(adc_avr*4*12000/32768)/10,(adc_avr*4*12000/32768)%10);
	    */
	    //ADC_Soft_Start();//软件触发ADC，适用于中断模式


        ///---- Chapter 12 I2C test ---------------------------------------------------------------------------------
        //I2C_Write(0x2d,0x55);//适用于非中断模式
        //i2c_data = I2C_Read(0x2d);//适用于非中断模式
        //printf("data:%x\r\n",i2c_data);
        //I2C_Write(0x2d,0xaa);//适用于非中断模式
        //i2c_data = I2C_Read(0x2d);//适用于非中断模式
        //printf("data:%x\r\n",i2c_data);
        //I2C_Write_IT(0x2d,0x55);//适用于中断模式

        ///---- Chapter 13 SPI test --------------------------------------------------------------------------------
        //SPI1 Test
        //SPI_Transceive(SPI1,sTxpack,sRxpack,10);//非中断模式
        //SPI1_RW_reg(WRITE_REG+0x05,0x53);//读写Si24R1寄存器
        //REG_Data = SPI1_RW_reg(READ_REG+0x05,0);//读写Si24R1寄存器
        //printf("\r\nREG5:%02x",REG_Data);
        //delay16M_ms(500);

        //SPI2 Test
        //SPI_Transceive(SPI2,sTxpack,sRxpack,10);//非中断模式
        //SPI2_RW_reg(WRITE_REG+0x05,0x53);//读写Si24R1寄存器
        //REG_Data = SPI2_RW_reg(READ_REG+0x05,0);//读写Si24R1寄存器
        //printf("\r\nREG5:%02x",REG_Data);
        //delay16M_ms(500);

        ///---- Chapter 15 UART Test ------------------------------------------------------------------------------------
        //---- 非中断模式数据回环测试 -------------------------------------------------------------------------------------
        //Uart_Reveive(UART1,upack1,10);//适用于非中断发送模式
        //Uart_Send(UART1,upack1,10);//适用于非中断发送模式
        //Uart_Reveive(UART2,upack2,10);//适用于非中断发送模式
        //Uart_Send(UART2,upack2,10);//适用于非中断发送模式
        //Uart_Reveive(UART3,upack3,10);//适用于非中断发送模式
        //Uart_Send(UART3,upack3,10);//适用于非中断发送模式
        //Uart_Reveive(UART4,upack4,10);//适用于非中断发送模式
        //Uart_Send(UART4,upack4,10);//适用于非中断发送模式

        //---- 中断模式数据回环测试 --------------------------------------------------------------------------------------
        //UART1_putbuf(UART1_getbuf());

        //---- printf测试 ----------------------------------------------------------------------------------------
        //printf("Hellow-01234568789abcdefghijklmnopqrstuvwxyz\r\n");


        ///---- Chapter 17 RANDGEN test -----------------------------------------------------------------------------
        //rand_data = RAND_Get();//生成随机数
        //printf("rand:0x%08x,%u\r\n",rand_data,rand_data);
        //delay16M_ms(500);


        ///---- Chapter 18 COMPARE test -----------------------------------------------------------------------------
        //if(COMP1->irq&0x1)
        //{
            //GPIO_Toggle(GPIOA,PIN15);
            //COMP1->irq = 1;
        //}
        //delay16M_ms(10);

	}

  return 0;
}
