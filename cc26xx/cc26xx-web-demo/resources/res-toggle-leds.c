/*
 * * Author: Telecontrolli srl
 * File: res-toggle-leds.c V1.3
 * Description:CoAP resource to toggle LEDs. Slightly modified copy of the one found
 *             in Contiki's original CoAP example.
/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "rest-engine.h"
#include "dev/leds.h"

#include <string.h>
/*---------------------------------------------------------------------------*/
static void
res_post_handler_rosso(void *request, void *response, uint8_t *buffer,
                     uint16_t preferred_size, int32_t *offset)
{
  leds_toggle(LEDS_ROSSO);
}
/*---------------------------------------------------------------------------*/
static void
res_post_handler_verde(void *request, void *response, uint8_t *buffer,
                       uint16_t preferred_size, int32_t *offset)
{
  leds_toggle(LEDS_VERDE);
}
/*---------------------------------------------------------------------------*/
static void
res_post_handler_giallo(void *request, void *response, uint8_t *buffer,
                        uint16_t preferred_size, int32_t *offset)
{
  leds_toggle(LEDS_GIALLO);
} 
/*---------------------------------------------------------------------------*/
static void
res_post_handler_arancio(void *request, void *response, uint8_t *buffer,
                        uint16_t preferred_size, int32_t *offset)
{
  leds_toggle(LEDS_ORANGE);
}
/*---------------------------------------------------------------------------*/
/* Toggles the red led */
RESOURCE(res_toggle_rosso,
         "title=\"Rosso LED\";rt=\"Control\"",
         NULL,
         res_post_handler_rosso,
         NULL,
         NULL);

/* Toggles the green led */
RESOURCE(res_toggle_verde,
         "title=\"Verde LED\";rt=\"Control\"",
         NULL,
         res_post_handler_verde,
         NULL,
         NULL);

/* Toggles the yellow led */
RESOURCE(res_toggle_giallo,
         "title=\"Giallo LED\";rt=\"Control\"",
         NULL,
         res_post_handler_giallo,
         NULL,
         NULL);

/* Toggles the orange led */
RESOURCE(res_toggle_arancio,
         "title=\"Arancio LED\";rt=\"Control\"",
         NULL,
         res_post_handler_arancio,
         NULL,
         NULL);
/*---------------------------------------------------------------------------*/
/** @} */
