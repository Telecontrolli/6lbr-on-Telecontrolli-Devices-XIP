/*
 * Author: Telecontrolli srl
 * File: leds.c V1.1
 * Description: The file leds.c set the function of leds
*/
#include "dev/leds.h"
#include "sys/clock.h"
#include "sys/energest.h"

static unsigned char leds;
/*---------------------------------------------------------------------------*/
static void
show_leds(unsigned char new_leds)
{
  unsigned char changed;
  changed = leds ^ new_leds;
  leds = new_leds;

  if(changed & LEDS_VERDE) {
    /* Green did change */
    if(leds & LEDS_VERDE) {
      ENERGEST_ON(ENERGEST_TYPE_LED_VERDE);
    } else {
      ENERGEST_OFF(ENERGEST_TYPE_LED_VERDE);
    }
  }
  if(changed & LEDS_GIALLO) {
    if(leds & LEDS_GIALLO) {
      ENERGEST_ON(ENERGEST_TYPE_LED_GIALLO);
    } else {
      ENERGEST_OFF(ENERGEST_TYPE_LED_GIALLO);
    }
  }
  if(changed & LEDS_ROSSO) {
    if(leds & LEDS_ROSSO) {
      ENERGEST_ON(ENERGEST_TYPE_LED_ROSSO);
    } else {
      ENERGEST_OFF(ENERGEST_TYPE_LED_ROSSO);
    }
  }
  leds_arch_set(leds);
}
/*---------------------------------------------------------------------------*/
void
leds_init(void)
{
  leds_arch_init();
  leds = 0;
}
/*---------------------------------------------------------------------------*/
void
leds_blink(void)
{
  /* Blink all leds that were initially off. */
  unsigned char blink;
  blink = ~leds;
  leds_toggle(blink);

  clock_delay(400);

  leds_toggle(blink);
}
/*---------------------------------------------------------------------------*/
unsigned char
leds_get(void) {
  return leds_arch_get();
}
/*---------------------------------------------------------------------------*/
void
leds_set(unsigned char ledv)
{
  show_leds(ledv);
}
/*---------------------------------------------------------------------------*/
void
leds_on(unsigned char ledv)
{
  show_leds(leds | ledv);
}
/*---------------------------------------------------------------------------*/
void
leds_off(unsigned char ledv)
{
  show_leds(leds & ~ledv);
}
/*---------------------------------------------------------------------------*/
void
leds_toggle(unsigned char ledv)
{
  show_leds(leds ^ ledv);
}
/*---------------------------------------------------------------------------*/
