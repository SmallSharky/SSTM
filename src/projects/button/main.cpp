
#include "main.h"
#include <SSTM.hpp>
#include <stdlib.h>


int main() {
  SSTM_Init(); // Init SSTM library

  char LED_PORT = 'C'; // LED GPIO PORT (GPIOC)
  uint16_t LED_PIN = 1 << 13; // LED GPIO PIN (pin 13)
  uint8_t BTN_PIN_NUMBER = 14; // Button pin number (14)
  uint16_t BTN_PIN = 1 << BTN_PIN_NUMBER; // Button pin (pin 14)
  SSTM_GPIO gpio ( LED_PORT ); // USE LED's GPIO PORT
  gpio.setClock ( true ); // Enable LED's GPIO clock
  gpio.setOutputPP ( LED_PIN ); // Set LED pin as PushPull output
  gpio.setInput ( BTN_PIN ); // Set button pin as input


  while ( 1 ) {
    if ( gpio.readPin ( BTN_PIN_NUMBER ) ) {
      gpio.writePins ( LED_PIN, true ); // Enable led if button pressed
    }
    else {
      gpio.writePins ( LED_PIN, false ); // Disable led if button isn't pressed
    }
  }
}

