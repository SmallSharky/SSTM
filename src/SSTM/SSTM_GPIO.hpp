#pragma once

#include <stm32f103xb.h>

class SSTM_GPIO{
private:
  uint8_t _port_idx;
  GPIO_TypeDef * _port;
public:
  SSTM_GPIO(char port);
  void setClock(bool state);
  void setOutputPP(uint16_t pins);
  void togglePins(uint16_t pins);
  void writePins(uint16_t pins, bool state);
  
};
