


set(FREERTOS_DIR ${SRC_DIR}/freertos)

include_directories(
  ${FREERTOS_DIR}
  ${FREERTOS_DIR}/inc
)

set(
  FREERTOS_SRC
  
  ${FREERTOS_DIR}/src/croutine.c
  ${FREERTOS_DIR}/src/event_groups.c
  ${FREERTOS_DIR}/src/heap_3.c
  ${FREERTOS_DIR}/src/list.c
  ${FREERTOS_DIR}/src/port.c
  ${FREERTOS_DIR}/src/stream_buffer.c
  ${FREERTOS_DIR}/src/tasks.c
  ${FREERTOS_DIR}/src/timers.c
  ${FREERTOS_DIR}/src/queue.c
)

add_library(
  FREERTOS
  ${FREERTOS_SRC}
)

 
