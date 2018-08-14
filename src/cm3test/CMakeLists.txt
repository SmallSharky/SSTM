
set(cm3test_dir ${SRC_DIR}/cm3test)

include_directories(${cm3test_dir})


add_executable( 
  cm3test.elf
  
  ${cm3test_dir}/main.cpp
)

target_link_libraries(
  cm3test.elf
  
  CMSIS_F1
  SSTM
)

## Make .bin file from .elf
add_custom_command(TARGET cm3test.elf POST_BUILD
    COMMAND arm-none-eabi-objcopy -O binary cm3test.elf cm3test.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Create .bin file"
)
