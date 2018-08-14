

//#define STM32F103XB
//#include "stm32f1xx.h"
//#include <SSTM_GPIO.hpp>
#include <SSTM.hpp>

#ifdef __cplusplus
extern "C" {
#endif
void delay(uint32_t ms);

int main() {
  SSTM_GPIO gpio;
  gpio.init();
  SSTM_Init();
  
  
  while ( 1 ) {
    gpio.toggle();    
    SSTM_SysTick_Delay(200);
    gpio.toggle();    
    SSTM_SysTick_Delay(800);
  }
}






#ifdef __cplusplus
}
#endif
