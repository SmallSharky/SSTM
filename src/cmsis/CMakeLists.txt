set(CMSIS_DIR ${SRC_DIR}/cmsis)

if(NOT MCU_FAMILY)
  message( FATAL_ERROR "Specify MCU family in mcu_select.cmake")
endif(NOT MCU_FAMILY)

if(MCU_FAMILY STREQUAL "F1")
  include(${CMSIS_DIR}/f1/CMakeLists.txt)
else()
  message( FATAL_ERROR "Specify !correct! MCU family in mcu_select.cmake")
endif()


include_directories(
  ${CMSIS_DIR}/cortex
)
