/*
 * * Author: Telecontrolli srl
 * File: res-toggle-leds.c V1.4
 * Description:CoAP resource to toggle LEDs. Slightly modified copy of the one found
 *             in Contiki's original CoAP example.
/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "rest-engine.h"
#include "dev/leds.h"

#include <string.h>
/*---------------------------------------------------------------------------*/
static void
res_post_handler_red(void *request, void *response, uint8_t *buffer,
                     uint16_t preferred_size, int32_t *offset)
{
  leds_toggle(LEDS_RED);
}
/*---------------------------------------------------------------------------*/
static void
res_post_handler_green(void *request, void *response, uint8_t *buffer,
                       uint16_t preferred_size, int32_t *offset)
{
  leds_toggle(LEDS_GREEN);
}
/*---------------------------------------------------------------------------*/
static void
res_post_handler_yellow(void *request, void *response, uint8_t *buffer,
                        uint16_t preferred_size, int32_t *offset)
{
  leds_toggle(LEDS_YELLOW);
} 
/*---------------------------------------------------------------------------*/
static void
res_post_handler_orange(void *request, void *response, uint8_t *buffer,
                        uint16_t preferred_size, int32_t *offset)
{
  leds_toggle(LEDS_ORANGE);
}
/*---------------------------------------------------------------------------*/
/* Toggles the red led */
RESOURCE(res_toggle_red,
         "title=\"Red LED\";rt=\"Control\"",
         NULL,
         res_post_handler_red,
         NULL,
         NULL);

/* Toggles the green led */
RESOURCE(res_toggle_green,
         "title=\"Green LED\";rt=\"Control\"",
         NULL,
         res_post_handler_green,
         NULL,
         NULL);

/* Toggles the yellow led */
RESOURCE(res_toggle_yellow,
         "title=\"Yellow LED\";rt=\"Control\"",
         NULL,
         res_post_handler_giallo,
         NULL,
         NULL);

/* Toggles the orange led */
RESOURCE(res_toggle_orange,
         "title=\"Orange LED\";rt=\"Control\"",
         NULL,
         res_post_handler_orange,
         NULL,
         NULL);
/*---------------------------------------------------------------------------*/
/** @} */
