
set(button_dir ${PROJECTS_DIR}/button)

include_directories(${button_dir})


add_executable( 
  button.elf
  
  ${button_dir}/main.cpp
#  ${SSTM_SRC}
#  ${CMSIS_SRC}
)

target_link_libraries(
   button.elf
   
   CMSIS
# #   FREERTOS
   SSTM
#   SSTM_LIBC
)

## Make .bin file from .elf
add_custom_command(TARGET button.elf POST_BUILD
    COMMAND arm-none-eabi-objcopy -O binary button.elf button.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Create .bin file for project 'button'"
)
