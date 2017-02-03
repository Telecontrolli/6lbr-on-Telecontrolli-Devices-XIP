#include "contiki.h"
#include "dev/leds.h"
#include "dev/button-sensor.h"
#include <stdio.h>
#include "board.h"
#include "test_led2.h"

/*--------------------------------------------------------------------------*/
PROCESS(blink_process, "blink examples");
AUTOSTART_PROCESSES (&blink_process);
/*--------------------------------------------------------------------------*/
PROCESS_THREAD (blink_process, ev, data) {
PROCESS_EXITHANDLER(goto exit);
PROCESS_BEGIN ();

SENSORS_ACTIVATE(button_sensor);
printf ("Clicca il bottone \n");
leds_on(LEDS_ALL);

while(1) {
static uint8_t push = 0;

PROCESS_WAIT_EVENT_UNTIL((ev==sensors_event) && (data ==&button_left_sensor));

if (push % 2 == 0) {
leds_toggle(LEDS_ALL);
push++;
    } else {
	leds_toggle(LEDS_ALL);
	push++;
    } 
if (push == 255)  {
push = 0;
 }  } 
exit:
leds_off(LEDS_ALL);
PROCESS_END();
 } 
/*---------------------------------------------------------------------------*/
