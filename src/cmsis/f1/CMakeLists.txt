ENABLE_LANGUAGE(ASM)

set(CMSIS_F1_DIR ${CMSIS_DIR}/f1)

include_directories(
  ${CMSIS_F1_DIR}/cortex
  ${CMSIS_F1_DIR}/registers
)

set(LINKFLAGS "${LINKFLAGS} -T ${CMSIS_F1_DIR}/linker/STM32F103XB_FLASH.ld")

set(
  CMSIS_SRC
  
  ${CMSIS_F1_DIR}/startup/startup_stm32f103xb.s
  ${CMSIS_F1_DIR}/registers/system_stm32f1xx.c
  
)


add_library(
  CMSIS_F1
  ${CMSIS_F1_DIR}/startup/startup_stm32f103xb.s
  ${CMSIS_F1_DIR}/registers/system_stm32f1xx.c
)
