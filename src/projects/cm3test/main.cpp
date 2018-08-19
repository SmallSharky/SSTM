
#include "main.h"
#include <SSTM.hpp>
#include <stdlib.h>


int main() {
  SSTM_Init(); // Init SSTM library
  
  char LED_PORT = 'C'; // LED GPIO PORT (GPIOC)
  uint16_t LED_PIN = 1<<13; // LED GPIO PIN (pin 13)
  SSTM_GPIO gpio(LED_PORT); // USE LED's GPIO PORT
  gpio.setClock(true); // Enable LED's GPIO clock
  gpio.setOutputPP(LED_PIN); // Set LED's pin as PushPull output
  
  
  while ( 1 ) {
    gpio.togglePins(LED_PIN); // Change state of LED pin
    SSTM_SysTick_Delay(200); // Wait for 200 milliseconds
  }
}

