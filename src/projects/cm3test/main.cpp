
#include "main.h"
#include <SSTM.hpp>
#include <stdlib.h>


int main() {
  SSTM_Init();
  
  SSTM_GPIO gpio('C');
  gpio.setClock(true);
  uint16_t led_pin = 0xffff;
  gpio.setOutputPP(led_pin);
  
  
  while ( 1 ) {
    gpio.togglePins(led_pin);
    SSTM_SysTick_Delay(200);
  }
}

