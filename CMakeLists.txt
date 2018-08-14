project(cm3test)


cmake_minimum_required(VERSION 3.0)

include(src/CMakeLists.txt)


set(CMAKE_SYSTEM_NAME STM32)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_C_COMPILER "arm-none-eabi-gcc")
set(CMAKE_C_FLAGS "-mcpu=cortex-m3 -mthumb -Wall -Wextra -Wstrict-aliasing -pedantic -Werror -Wunreachable-code -MD")
set(CMAKE_CXX_FLAGS "-mcpu=cortex-m3 -mthumb -Wall -Wextra -Wstrict-aliasing -pedantic -Werror -Wunreachable-code -MD")
set(CMAKE_CXX_COMPILER "arm-none-eabi-gcc")
set(CMAKE_ASM_COMPILER "arm-none-eabi-gcc")

set(CMAKE_C_LINK_FLAGS "${LINKFLAGS} -mcpu=cortex-m3 -mthumb -mfloat-abi=soft --specs=nosys.specs -Xlinker -lm -Wl,-Map=output.map -Wl,--gc-sections -Wl,--warn-once")
set(CMAKE_CXX_LINK_FLAGS "${LINKFLAGS} -mcpu=cortex-m3 -mthumb -mfloat-abi=soft --specs=nosys.specs -Xlinker -lm -Wl,-Map=output.map -Wl,--gc-sections -Wl,--warn-once")
set(CMAKE_EXE_LINKER_FLAGS "${LINKFLAGS} -mcpu=cortex-m3 -mthumb")
set( CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${LINKFLAGS} -mcpu=cortex-m3 -mthumb -mfloat-abi=soft --specs=nosys.specs -Xlinker -lm -Wl,-Map=output.map -Wl,--gc-sections -Wl,--warn-once" )
set( CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${LINKFLAGS} -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -Xlinker -lm -Wl,-Map=output.map -Wl,--gc-sections -Wl,--warn-once" )

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)



add_definitions(
    -DSTM32F103xB
)



