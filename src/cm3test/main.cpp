
#include "main.h"
#include <SSTM.hpp>


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

