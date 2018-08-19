
set(freertos_test_dir ${PROJECTS_DIR}/freertos_test)

include_directories(${freertos_test_dir})


add_executable( 
  freertos_test.elf
  
  ${freertos_test_dir}/main.cpp
#   ${SSTM_SRC}
#   ${CMSIS_SRC}
#   ${FREERTOS_SRC}
)

target_link_libraries(
  freertos_test.elf
  
  CMSIS
   FREERTOS
   SSTM
#  SSTM_LIBC
)

## Make .bin file from .elf
add_custom_command(TARGET freertos_test.elf POST_BUILD
    COMMAND arm-none-eabi-objcopy -O binary freertos_test.elf freertos_test.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Create .bin file for freertos_test"
)
