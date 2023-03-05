#ifndef TIMER_H_
#define TIMER_H_



void Timer1_UpCounting_Mode_Init(void);//鍚戜笂璁℃暟
void Timer1_6StepPWM_Mode_Init(void);//6stepPWM杈撳嚭

void Timer2_UpCounting_Mode_Init(void);//鍚戜笂璁℃暟
void Timer2_DownCounting_Mode_Init(void);//鍚戜笅璁℃暟
void Timer2_ExternalClock_Mode_Init(void);//澶栭儴鏃堕挓
void Timer2_InputCapture_Mode_Init(void);//杈撳叆鎹曡幏
void Timer2_PWM_InputCapture_Mode_Init(void);//PWM杈撳叆鎹曡幏
void Timer2_Input_XOR_Mode_Init(void);//杈撳叆寮傛垨
void Timer2_PWM_Mode_Init(void);//PWM杈撳嚭
void Timer2_6StepPWM_Mode_Init(void);//6stepPWM杈撳嚭

void CLIC_Timer1_Break_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_Timer1_Update_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_Timer1_Capture_Compare_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_Timer1_Trigger_Commutation_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));

void CLIC_Timer2_Break_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_Timer2_Update_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_Timer2_Capture_Compare_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));
void CLIC_Timer2_Trigger_Commutation_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));





#endif
