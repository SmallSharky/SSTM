


set(SSTM_DIR ${SRC_DIR}/SSTM)

include_directories(${SSTM_DIR})

add_library(
  SSTM
  
  ${SSTM_DIR}/SSTM_GPIO.cpp
  ${SSTM_DIR}/SSTM_SysTick.cpp
  ${SSTM_DIR}/SSTM.cpp
)
