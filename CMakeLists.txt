project(cm3test)


cmake_minimum_required(VERSION 3.0)

include(mcu_select.cmake)

include(src/CMakeLists.txt)

include(toolchain.cmake)


add_definitions(
    -DSTM32F103xB
)



