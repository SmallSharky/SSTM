#include <cctype>
#include <stm32f407xx.h>
//#include <stm32f407xx.h>



#include "SSTM_GPIO.hpp"

uint8_t _ports_cnt = 4;
GPIO_TypeDef * _gpio_ports[] = {
  GPIOA,
  GPIOB,
  GPIOC,
  GPIOD,
  GPIOE,
  GPIOF,
  GPIOG,
  GPIOH,
  GPIOI
};

SSTM_GPIO::SSTM_GPIO ( char port ) {
  _port_idx = tolower ( port ) - 'a';

  if ( _port_idx >= _ports_cnt ) {
    _port = nullptr;
    return;
  }

  _port = _gpio_ports[_port_idx];
  //_port_idx = 0;

}

void SSTM_GPIO::setClock ( bool state ) {
  if ( _port == nullptr ) {
    return;
  }

  if ( state ) {
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN << _port_idx;
  }
  else {
    RCC->AHB1ENR &= ~ ( RCC_AHB1ENR_GPIOAEN << _port_idx );
  }

}

void SSTM_GPIO::setOutputPP ( uint16_t pins ) {
  if ( _port == nullptr ) {
    return;
  }

  uint8_t i = 0;

  while ( i < 16 ) {
    if ( ! ( pins & ( 1U << i ) ) ) {
      i++;
      continue;
    }

    // Mode register
    volatile uint32_t * moder = &_port->MODER;
    _port->OSPEEDR = GPIO_OSPEEDR
    volatile uint32_t * cr = ( i < 8 ) ? ( &_port->CRL ) : ( &_port->CRH );
    uint8_t grp = ( i < 8 ) ? i : i - 8;
    uint32_t mode_0 = 0x1U << ( grp * 4 );
    uint32_t mode_1 = 0x2U << ( grp * 4 );
    uint32_t cnf_0 = 0x1U << ( grp * 4 + 2 );
    uint32_t cnf_1 = 0x2U << ( grp * 4 + 2 );
    cr[0] |= mode_0 | mode_1;
    cr[0] &= ~ ( cnf_0 | cnf_1 );
    i++;

  }
}

void SSTM_GPIO::togglePins ( uint16_t pins ) {
  if ( _port == nullptr ) {
    return;
  }

  _port->ODR ^= pins;
}

void SSTM_GPIO::togglePin ( uint8_t pin ) {
  if ( _port == nullptr ) {
    return;
  }

  _port->ODR ^= ( 1 << pin );
}

void SSTM_GPIO::writePins ( uint16_t pins, bool state ) {
  if ( _port == nullptr ) {
    return;
  }

  uint32_t bsrr_val = pins;

  if ( !state ) {
    bsrr_val <<= 16;

  }

  _port->BSRR = bsrr_val;
}

/*!
 * Set pins as open drain output
 * @param pins - pins in 1<<n format (each bit means one pin)
 */
void SSTM_GPIO::setOutputOD ( uint16_t pins ) {
  if ( _port == nullptr ) {
    return;
  }

  uint8_t i = 0;

  while ( i < 16 ) {
    if ( ! ( pins & ( 1U << i ) ) ) {
      i++;
      continue;
    }

    // control register
    volatile uint32_t * cr = ( i < 8 ) ? ( &_port->CRL ) : ( &_port->CRH );
    uint8_t grp = ( i < 8 ) ? i : i - 8;
    uint32_t mode_0 = 0x1U << ( grp * 4 );
    uint32_t mode_1 = 0x2U << ( grp * 4 );
    uint32_t cnf_0 = 0x1U << ( grp * 4 + 2 );
    uint32_t cnf_1 = 0x2U << ( grp * 4 + 2 );
    cr[0] |= mode_0 | mode_1;
    cr[0] &= ~ ( cnf_0 | cnf_1 );
    i++;

  }
}

/*!
 * Set pins as input
 * @param pins - pins in 1<<n format (each bit means one pin)
 */
void SSTM_GPIO::setInput ( uint16_t pins ) {
  // TODO: fix code to make input
  if ( _port == nullptr ) {
    return;
  }

  uint8_t i = 0;

  while ( i < 16 ) {
    if ( ! ( pins & ( 1U << i ) ) ) {
      i++;
      continue;
    }

    // control register
    volatile uint32_t * cr = ( i < 8 ) ? ( &_port->CRL ) : ( &_port->CRH );
    uint8_t grp = ( i < 8 ) ? i : i - 8;
    uint32_t mode_0 = 0x1U << ( grp * 4 );
    uint32_t mode_1 = 0x2U << ( grp * 4 );
    uint32_t cnf_0 = 0x1U << ( grp * 4 + 2 );
    uint32_t cnf_1 = 0x2U << ( grp * 4 + 2 );

    // CNF0  = 1
    // CNF1  = 0
    // MODE0 = 0
    // MODE1 = 0
    cr[0] &= ~ ( mode_0 | mode_1 );
    cr[0] |= cnf_0;
    cr[0] &= ~ cnf_1;
    i++;

  }
}

/*!
 * Change pins state to specified.
 * @param pin - it's for pin number (for example value 4 will affect to pin 4)
 * @param state - true means enabled
 */
void SSTM_GPIO::writePin ( uint8_t pin, bool state ) {
  if ( _port == nullptr ) {
    return;
  }

  uint32_t bsrr_val = 1 << pin;

  if ( !state ) {
    bsrr_val <<= 16;

  }

  _port->BSRR = bsrr_val;
}

/*!
 * Change pins state to specified.
 * @param pin - it's for pin number (for example value 4 will affect to pin 4)
 * @return true is for enabled
 */
bool SSTM_GPIO::readPin ( uint8_t pin ) {
  if ( _port == nullptr ) {
    return false;
  }

  uint16_t pin_mask = 1 << pin;
  bool ret = ( _port->IDR & pin_mask ) != 0;
  return ret;
}

/*!
 * Read pins state.
 * @return pins in 1<<n format (each bit means one pin)
 */
uint16_t SSTM_GPIO::readPins() {
  if ( _port == nullptr ) {
    return 0;
  }

  uint16_t ret = _port->IDR;

  return ret;
}
