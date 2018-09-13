ENABLE_LANGUAGE(ASM)

set(CMSIS_F4_DIR ${CMSIS_DIR}/f4)

include_directories(
  ${CMSIS_F4_DIR}/registers
)

if(NOT MCU_SUBFAMILY)
  message( FATAL_ERROR "Please, specify MCU subfamily in mcu_select.cmake")
endif()

if(MCU_SUBFAMILY STREQUAL "F407xx")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F4_DIR}/linker/STM32F407xx_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F4_DIR}/startup/startup_stm32f407xx.s)
  add_definitions( -DSTM32F407xx )
else()
  message( FATAL_ERROR "Please, specify !correct! MCU subfamily in mcu_select.cmake")
endif()


set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F4_DIR}/registers/system_stm32f4xx.c)

add_library(
   CMSIS
   ${CMSIS_SRC}
)
