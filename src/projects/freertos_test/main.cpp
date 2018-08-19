
#include "main.h"
#include <SSTM.hpp>

#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <stdlib.h>


// SSTM_GPIO gpio;


void vFreeRTOSInitAll() {
  SSTM_Init();
//   gpio.init();
  //gpio.toggle();

}

void vLedTask ( void * pvParameters ) {
  
  while ( 1 ) {
    void * m = malloc(1000);
    uint16_t max_ticks = 500;
    uint16_t ticks_on = m!=0?100:500;
    uint16_t ticks_off = max_ticks - ticks_on;
    if(m!=0)free(m);
//     gpio.toggle();
    vTaskDelay(ticks_on);
//     gpio.toggle();
    vTaskDelay(ticks_off);
  }

  vTaskDelete ( NULL );
}

int main() {

  vFreeRTOSInitAll();
  xTaskCreate ( vLedTask, ( char * ) "LedTask", configMINIMAL_STACK_SIZE,
                NULL, tskIDLE_PRIORITY + 1, NULL );
  vTaskStartScheduler();

}

