#pragma once

#include <stm32f103xb.h>

class SSTM_GPIO{
private:
  uint8_t _port_idx;
  GPIO_TypeDef * _port;
  
  
public:
  
  /*!
   * Specify GPIO port
   * @param port - character, 'a' or 'A' means GPIOA
   */
  SSTM_GPIO(char port);
  
  /*!
   * Set clock for GPIO port enabled/disabled
   * @param state - true means enabled
   */
  void setClock(bool state);
  
  /*!
   * Set pins as push-pull output
   * @param pins - pins in 1<<n format (each bit means one pin)
   */
  void setOutputPP(uint16_t pins);
  
  
  /*!
   * Set pins as open drain output
   * @param pins - pins in 1<<n format (each bit means one pin)
   */
  void setOutputOD(uint16_t pins);
  
  /*!
   * Set pins as input
   * @param pins - pins in 1<<n format (each bit means one pin)
   */
  void setInput(uint16_t pins);
  
  /*!
   * Change pins state
   * 
   * If pin state was enabled then it will be disabled
   * @param pins - pins in 1<<n format (each bit means one pin)
   */
  void togglePins(uint16_t pins);
  
  /*!
   * Change pin state
   * 
   * If pin state was enabled then it will be disabled
   * @param pin - it's for pin number (for example value 4 will affect to pin 4)
   */
  void togglePin ( uint8_t pin );
  
  /*!
   * Change pins state to specified.
   * @param pins - pins in 1<<n format (each bit means one pin)
   * @param state - true means enabled
   */ 
  void writePins(uint16_t pins, bool state);
  
  /*!
   * Change pins state to specified.
   * @param pin - it's for pin number (for example value 4 will affect to pin 4)
   * @param state - true means enabled
   */ 
  void writePin(uint8_t pin, bool state);  
  
  /*!
   * Read pins state.
   * @return pins in 1<<n format (each bit means one pin)
   */
  uint16_t readPins();
  
  /*!
   * Change pins state to specified.
   * @param pin - it's for pin number (for example value 4 will affect to pin 4)
   * @return true is for enabled
   */ 
  bool readPin(uint8_t pin);
  
  
};
