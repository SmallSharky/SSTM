#include <cctype>

#include "stm32f1xx.h"

#include "SSTM_GPIO.hpp"

uint8_t _ports_cnt = 4;
GPIO_TypeDef * _gpio_ports[] = {
  GPIOA,
  GPIOB,
  GPIOC,
  GPIOD
};

SSTM_GPIO::SSTM_GPIO(char port){
  _port_idx = tolower(port) - 'a';
    if(_port_idx>=_ports_cnt){
    _port = nullptr;
    return;
  }
    _port = _gpio_ports[_port_idx];
  //_port_idx = 0;
  
}
void SSTM_GPIO::setClock(bool state){
  if(_port==nullptr){
    return;
  }
  if(state){
    RCC->APB2ENR |= RCC_APB2ENR_IOPAEN<<_port_idx;
  }
  else{
    RCC->APB2ENR &= ~(RCC_APB2ENR_IOPAEN<<_port_idx);
  }
  
}
void SSTM_GPIO::setOutputPP(uint16_t pins){
  if(_port==nullptr){
    return;
  }
    //GPIOC->CRH |= GPIO_CRH_MODE13_0 | GPIO_CRH_MODE13_1;
  uint8_t i = 0;
  while(i<16){
    if(!(pins&(1U<<i))){
      i++;
      continue;
    }
    // control register
    volatile uint32_t * cr = (i<8)?(&_port->CRL):(&_port->CRH);
    uint8_t grp = (i<8)?i:i-8;
    uint32_t mode_0 = 0x1U<<(grp*4);
    uint32_t mode_1 = 0x2U<<(grp*4);
    uint32_t cnf_0 = 0x1U<<(grp*4 + 2);
    uint32_t cnf_1 = 0x2U<<(grp*4 + 2);
    cr[0] |= mode_0 | mode_1;
    cr[0] &= ~(cnf_0 | cnf_1);
    i++;
    
  }
  //   GPIOC->CRH |= GPIO_CRH_MODE13_1;
  //   GPIOC->CRH &= ~ ( ( GPIO_CRH_CNF13_0 ) | ( GPIO_CRH_CNF13_1 ) );
  //   GPIOC->ODR = GPIO_ODR_ODR13;
}
void SSTM_GPIO::togglePins(uint16_t pins){
  if(_port==nullptr){
    return;
  }
  _port->ODR ^= pins;
}
void SSTM_GPIO::writePins(uint16_t pins, bool state){
  if(_port==nullptr){
    return;
  }
  if(state){
    _port->ODR |= pins;
  }
  else{
    _port->ODR &= ~(pins);
  }
}

// void SSTM_GPIO::init(){
//   
//   RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
//   GPIOC->CRH |= GPIO_CRH_MODE13_0 | GPIO_CRH_MODE13_1;
//   GPIOC->CRH |= GPIO_CRH_MODE13_1;
//   GPIOC->CRH &= ~ ( ( GPIO_CRH_CNF13_0 ) | ( GPIO_CRH_CNF13_1 ) );
//   GPIOC->ODR = GPIO_ODR_ODR13;
// }
// 
// void SSTM_GPIO::toggle()
// {
//   GPIOC->ODR ^= GPIO_ODR_ODR13;
// }
