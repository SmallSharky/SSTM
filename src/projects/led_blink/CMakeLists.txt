
set(led_blink_dir ${PROJECTS_DIR}/led_blink)

include_directories(${led_blink_dir})


add_executable( 
  led_blink.elf
  
  ${led_blink_dir}/main.cpp
#  ${SSTM_SRC}
#  ${CMSIS_SRC}
)

target_link_libraries(
   led_blink.elf
   
   CMSIS
# #   FREERTOS
   SSTM
#   SSTM_LIBC
)

## Make .bin file from .elf
add_custom_command(TARGET led_blink.elf POST_BUILD
    COMMAND arm-none-eabi-objcopy -O binary led_blink.elf led_blink.bin
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Create .bin file for project 'led_blink'"
)
