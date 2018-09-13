/*
 * cmsis.h
 *
 * Author: sharky
 */

#ifndef CM3TEST_CMSIS_H
#define CM3TEST_CMSIS_H


#if defined(MCU_FAMILY_F4)
#include "stm32f4xx.h"
#elif defined(MCU_FAMILY_F1)
#include "stm32f1xx.h"
#else
#error "Please, specify supported MCU family"
#endif













#endif //CM3TEST_CMSIS_H
