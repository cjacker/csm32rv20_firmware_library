#ifndef WUP_H_
#define WUP_H_



void WUP_Init_case1(uint32_t data);//璁剧疆涓柇鍛ㄦ湡,浣胯兘WUP涓柇

void WUP_IRQhandler(void) __attribute__((interrupt("SiFive-CLIC-preemptible")));






#endif
