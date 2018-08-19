ENABLE_LANGUAGE(ASM)

set(CMSIS_F1_DIR ${CMSIS_DIR}/f1)

include_directories(
  ${CMSIS_F1_DIR}/cortex
  ${CMSIS_F1_DIR}/registers
)

if(NOT MCU_SUBFAMILY)
  message( FATAL_ERROR "Please, specify MCU subfamily in mcu_select.cmake")
endif()

if(MCU_SUBFAMILY STREQUAL "F100XB")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F100XB_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f100xb.s)
  add_definitions( -DSTM32F100xB )

elseif(MCU_SUBFAMILY STREQUAL "F100XE")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F100XE_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f100xe.s)
  add_definitions( -DSTM32F100xE )
  
elseif(MCU_SUBFAMILY STREQUAL "F101X6")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F101X6_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f101x6.s)
  add_definitions( -DSTM32F101x6 )
  
elseif(MCU_SUBFAMILY STREQUAL "F101XB")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F101XB_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f101xb.s)
  add_definitions( -DSTM32F101xB )
  
elseif(MCU_SUBFAMILY STREQUAL "F101XE")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F101XE_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f101xe.s)
  add_definitions( -DSTM32F101xE )
  
elseif(MCU_SUBFAMILY STREQUAL "F101XG")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F101XG_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f101xg.s)
  add_definitions( -DSTM32F101xG )
  
elseif(MCU_SUBFAMILY STREQUAL "F102X6")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F102X6_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f102x6.s)
  add_definitions( -DSTM32F102x6 )
  
elseif(MCU_SUBFAMILY STREQUAL "F102XB")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F102XB_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f102xb.s)
  add_definitions( -DSTM32F102xB )
  
elseif(MCU_SUBFAMILY STREQUAL "F103X6")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F103X6_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f103x6.s)
  add_definitions( -DSTM32F103x6 )
  
elseif(MCU_SUBFAMILY STREQUAL "F103XB")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F103XB_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f103xb.s)
  add_definitions( -DSTM32F103xB )
  
elseif(MCU_SUBFAMILY STREQUAL "F103XE")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F103XE_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f103xe.s)
  add_definitions( -DSTM32F103xE )
  
elseif(MCU_SUBFAMILY STREQUAL "F103XG")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F103XG_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f103xg.s)
  add_definitions( -DSTM32F103xG )
  
elseif(MCU_SUBFAMILY STREQUAL "F105XC")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F105XC_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f105xc.s)
  add_definitions( -DSTM32F105xC )
  
elseif(MCU_SUBFAMILY STREQUAL "F107XC")
  set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F107XC_FLASH.ld")
  set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/startup/startup_stm32f107xc.s)
  add_definitions( -DSTM32F107xC )

else()
  message( FATAL_ERROR "Please, specify !correct! MCU subfamily in mcu_select.cmake")
endif()


set(CMSIS_SRC ${CMSIS_SRC} ${CMSIS_F1_DIR}/registers/system_stm32f1xx.c)

add_library(
   CMSIS
   ${CMSIS_SRC}
)
