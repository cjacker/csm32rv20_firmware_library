#For MCUonly version


	.section .init

.weak     CLIC_soft_IRQHandler
.weak     CLIC_RTC_IRQhandler
.weak     CLIC_SPI1_IRQhandler
.weak     CLIC_SPI2_IRQhandler
.weak     CLIC_LV_IRQhandler
.weak     CLIC_UART1_IRQhandler
.weak     CLIC_I2C_ready_IRQhandler
.weak     CLIC_I2C_error_IRQhandler
.weak     CLIC_Timer1_Break_IRQhandler
.weak     CLIC_Timer1_Update_IRQhandler
.weak     CLIC_Timer1_Capture_Compare_IRQhandler
.weak     CLIC_Timer1_Trigger_Commutation_IRQhandler
.weak     CLIC_Timer2_Break_IRQhandler
.weak     CLIC_Timer2_Update_IRQhandler
.weak     CLIC_Timer2_Capture_Compare_IRQhandler
.weak     CLIC_Timer2_Trigger_Commutation_IRQhandler
.weak     CLIC_ADC_IRQHandler
.weak     CLIC_WUP_IRQhandler
.weak     CLIC_UART2_IRQhandler
.weak     CLIC_UART3_IRQhandler
.weak     CLIC_UART4_IRQhandler
.weak     CLIC_COMP1_IRQhandler
.weak     CLIC_COMP2_IRQhandler
.weak     CLIC_COMP3_IRQhandler
.weak     CLIC_EXTI0_IRQHandler
.weak     CLIC_EXTI1_IRQHandler
.weak     CLIC_EXTI2_IRQHandler
.weak     CLIC_EXTI3_IRQHandler
.weak     CLIC_EXTI4_IRQHandler
.weak     CLIC_EXTI9_5_IRQHandler
.weak     CLIC_EXTI15_10_IRQHandler
.weak     CLIC_CAW_IRQhandler

.globl vector_base
    vector_base:
    //j vector_base
    j _start
    .align    2
    .word     0
    .word     0
    .word     0
    .word     0
    .word     0
    .word     0
    .word     CLIC_RTC_IRQhandler
    .word     0
    .word     0
    .word     0
    .word     0
    .word     0
    .word     0
    .word     0
    .word     0
    .word     CLIC_SPI1_IRQhandler
    .word     CLIC_SPI2_IRQhandler
    .word     CLIC_LV_IRQhandler
    .word     CLIC_UART1_IRQhandler
    .word     CLIC_I2C_ready_IRQhandler
    .word     CLIC_I2C_error_IRQhandler
    .word     CLIC_Timer1_Break_IRQhandler
    .word     CLIC_Timer1_Update_IRQhandler
    .word     CLIC_Timer1_Capture_Compare_IRQhandler
    .word     CLIC_Timer1_Trigger_Commutation_IRQhandler
    .word     CLIC_Timer2_Break_IRQhandler
    .word     CLIC_Timer2_Update_IRQhandler
    .word     CLIC_Timer2_Capture_Compare_IRQhandler
    .word     CLIC_Timer2_Trigger_Commutation_IRQhandler
    .word     CLIC_ADC_IRQHandler
    .word     0
    .word     CLIC_WUP_IRQhandler
    .word     CLIC_UART2_IRQhandler
    .word     CLIC_UART3_IRQhandler
    .word     CLIC_UART4_IRQhandler
    .word     CLIC_COMP1_IRQhandler
    .word     CLIC_COMP2_IRQhandler
    .word     CLIC_COMP3_IRQhandler
    .word     0
    .word     CLIC_EXTI0_IRQHandler
    .word     CLIC_EXTI1_IRQHandler
    .word     CLIC_EXTI2_IRQHandler
    .word     CLIC_EXTI3_IRQHandler
    .word     CLIC_EXTI4_IRQHandler
    .word     CLIC_EXTI9_5_IRQHandler
    .word     CLIC_EXTI15_10_IRQHandler
    .word     CLIC_CAW_IRQhandler


	.globl _start
	.type _start,@function
_start:
	.cfi_startproc

#set vector_base
    la t0, vector_base
    csrw 0x307, t0

#close boot wdg
    li t0, 0x30000a00 #exp_reg address
    sw zero, 0(t0)    #set 0 to close the boot wdg

#Set stack
    .option push
    .option norelax
        la  gp,__global_pointer$
    .option pop

#copy .data
copy_data:
    la t0, _data_start
    la t1, _data_end
    la a5, _data_load_start
    beq t0,t1,cls_bss
copy_data_loop:
    lw a4,0(a5)
    sw a4,0(t0)
    addi a5,a5,4
    addi t0,t0,4
    blt t0,t1,copy_data_loop

#clear bss
cls_bss:
    la t0, _bss_start
    la t1, _bss_end
    beq t0,t1,load_sp
    li t2, 0x00000000
cls_bss_loop:
    sw t2,(t0)
    addi t0,t0,4
    blt t0,t1,cls_bss_loop
load_sp:
	la	sp, _sp			#Set top address of stack
	call main			#goto main
	.cfi_endproc





