


set(SSTM_DIR ${SRC_DIR}/SSTM)

include_directories(${SSTM_DIR})

set(
  SSTM_SRC
  
  ${SSTM_SRC}
  ${SSTM_DIR}/SSTM_SysTick.cpp
  ${SSTM_DIR}/SSTM.cpp
)




if(NOT MCU_FAMILY)
  message( FATAL_ERROR "Specify MCU family in mcu_select.cmake")
endif(NOT MCU_FAMILY)

if(MCU_FAMILY STREQUAL "F1")
  include(${SSTM_DIR}/f1/CMakeLists.txt)
else()
  message( FATAL_ERROR "Specify !correct! MCU family in mcu_select.cmake")
endif()

add_library(
  SSTM
  ${SSTM_SRC}
)

#add_library(
#  SSTM_LIBC
#  
#  
#  ${SSTM_DIR}/SSTM_LibC_Helpers.c
#)
