


set(SSTM_DIR ${SRC_DIR}/SSTM)

include_directories(${SSTM_DIR})

set(
  SSTM_SRC
  
  ${SSTM_DIR}/SSTM_GPIO.cpp
  ${SSTM_DIR}/SSTM_SysTick.cpp
  ${SSTM_DIR}/SSTM.cpp
)

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
