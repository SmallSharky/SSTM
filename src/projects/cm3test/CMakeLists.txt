
set(cm3test_dir ${PROJECTS_DIR}/cm3test)

include_directories(${cm3test_dir})


add_executable( 
  cm3test.elf
  
  ${cm3test_dir}/main.cpp
#  ${SSTM_SRC}
#  ${CMSIS_SRC}
)

target_link_libraries(
   cm3test.elf
   
   CMSIS
# #   FREERTOS
   SSTM
#   SSTM_LIBC
)

## Make .bin file from .elf
add_custom_command(TARGET cm3test.elf POST_BUILD
    COMMAND arm-none-eabi-objcopy -O binary cm3test.elf cm3test.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Create .bin file"
)
