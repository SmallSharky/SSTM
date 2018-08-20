#set(CMAKE_SYSTEM_NAME STM32)
#set(CMAKE_SYSTEM_PROCESSOR arm)


set(COMPILER_FLAGS "${COMPILER_FLAGS} -mcpu=cortex-m3 -mthumb -Wall -Wno-unused-variable -Wstrict-aliasing -pedantic -Wunreachable-code -MD -g")
set(LINKFLAGS "${LINKFLAGS} -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -Xlinker -lm -Wl,-Map=output.map -Wl,--gc-sections -Wl,--warn-once -g")


set(COMPILER_PREFIX "arm-none-eabi-")

set(CMAKE_C_COMPILER "${COMPILER_PREFIX}gcc")
set(CMAKE_CXX_COMPILER "${COMPILER_PREFIX}g++")
set(CMAKE_ASM_COMPILER "${COMPILER_PREFIX}gcc")
set(CMAKE_AR "${COMPILER_PREFIX}ar")

set(CMAKE_C_FLAGS ${COMPILER_FLAGS})
set(CMAKE_CXX_FLAGS ${COMPILER_FLAGS})

#set(CMAKE_C_LINK_FLAGS "${LINKFLAGS}")
#set(CMAKE_CXX_LINK_FLAGS "${LINKFLAGS}")
#set(CMAKE_EXE_LINKER_FLAGS "${LINKFLAGS} ")
set( CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "${LINKFLAGS}  -specs=nano.specs -specs=nosys.specs" )
set( CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "${LINKFLAGS} -specs=nano.specs -specs=nosys.specs" )

#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

