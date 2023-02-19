#For MCUonly version


	.section .init



.weak     soft_IRQHandler

.weak     RTC_IRQhandler

.weak     SPI1_IRQhandler

.weak     SPI2_IRQhandler

.weak     LV_IRQhandler

.weak     UART1_IRQhandler

.weak     I2C_ready_IRQhandler

.weak     I2C_error_IRQhandler

.weak     Timer1_Break_IRQhandler

.weak     Timer1_Update_IRQhandler

.weak     Timer1_Capture_Compare_IRQhandler

.weak     Timer1_Trigger_Commutation_IRQhandler

.weak     Timer2_Break_IRQhandler

.weak     Timer2_Update_IRQhandler

.weak     Timer2_Capture_Compare_IRQhandler

.weak     Timer2_Trigger_Commutation_IRQhandler

.weak     ADC_IRQHandler

.weak     WUP_IRQhandler

.weak     UART2_IRQhandler

.weak     UART3_IRQhandler

.weak     UART4_IRQhandler

.weak     COMP1_IRQhandler

.weak     COMP2_IRQhandler

.weak     COMP3_IRQhandler

.weak     EXIT0_IRQHandler

.weak     EXIT1_IRQHandler

.weak     EXIT2_IRQHandler

.weak     EXIT3_IRQHandler

.weak     EXIT4_IRQHandler

.weak     EXIT9_5_IRQHandler

.weak     EXIT15_10_IRQHandler

.weak     CAW_IRQhandler



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

    .word     RTC_IRQhandler

    .word     0

    .word     0

    .word     0

    .word     0

    .word     0

    .word     0

    .word     0

    .word     0

    .word     SPI1_IRQhandler

    .word     SPI2_IRQhandler

    .word     LV_IRQhandler

    .word     UART1_IRQhandler

    .word     I2C_ready_IRQhandler

    .word     I2C_error_IRQhandler

    .word     Timer1_Break_IRQhandler

    .word     Timer1_Update_IRQhandler

    .word     Timer1_Capture_Compare_IRQhandler

    .word     Timer1_Trigger_Commutation_IRQhandler

    .word     Timer2_Break_IRQhandler

    .word     Timer2_Update_IRQhandler

    .word     Timer2_Capture_Compare_IRQhandler

    .word     Timer2_Trigger_Commutation_IRQhandler

    .word     ADC_IRQHandler

    .word     0

    .word     WUP_IRQhandler

    .word     UART2_IRQhandler

    .word     UART3_IRQhandler

    .word     UART4_IRQhandler

    .word     COMP1_IRQhandler

    .word     COMP2_IRQhandler

    .word     COMP3_IRQhandler

    .word     0

    .word     EXIT0_IRQHandler

    .word     EXIT1_IRQHandler

    .word     EXIT2_IRQHandler

    .word     EXIT3_IRQHandler

    .word     EXIT4_IRQHandler

    .word     EXIT9_5_IRQHandler

    .word     EXIT15_10_IRQHandler

    .word     CAW_IRQhandler




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







