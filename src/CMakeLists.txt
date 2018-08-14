

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

#include_directories(
#  ${SRC_DIR}/SSTM
#  ${SRC_DIR}/cm3test
#  ${SRC_DIR}/cmsis
#)


include(${SRC_DIR}/SSTM/CMakeLists.txt)
include(${SRC_DIR}/cm3test/CMakeLists.txt)
include(${SRC_DIR}/cmsis/CMakeLists.txt)
