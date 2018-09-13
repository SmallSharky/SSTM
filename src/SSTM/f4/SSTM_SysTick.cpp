

#include "SSTM_SysTick.hpp"


#include "stm32f4xx.h"



void SSTM_SysTick_Init() {
  SystemCoreClockUpdate();
  SysTick_Config ( SystemCoreClock / 1000 );
}

uint32_t systick = 0;


#ifdef __cplusplus
extern "C" {
#endif


void SysTick_Handler() {
  systick++;
}



#ifdef __cplusplus
}
#endif


void SSTM_SysTick_Delay ( uint32_t ms ) {
  uint32_t tick_start = systick;

  while ( ( systick - tick_start ) < ms ) ;
}
