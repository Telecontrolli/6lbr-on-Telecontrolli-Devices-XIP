/*
 * Author: Telecontrolli srl
 * File: leds-arch.c V1.4
 * Description: Driver for the SmartRF06EB LEDs when a CC13xx/CC26xx EM is mounted on it
 */
/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "dev/leds.h"
#include "ti-lib.h"
/*---------------------------------------------------------------------------*/
static unsigned char c;
static int inited = 0;
/*---------------------------------------------------------------------------*/
void
leds_arch_init(void)
{
  if(inited) {
    return;
  }
  inited = 1;

  ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_LED_1);
  ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_LED_2);
  ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_LED_3);
  ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_LED_4);

  ti_lib_gpio_clear_multi_dio(BOARD_LED_ALL);
}
/*---------------------------------------------------------------------------*/
unsigned char
leds_arch_get(void)
{
  return c;
}
/*---------------------------------------------------------------------------*/
void
leds_arch_set(unsigned char leds)
{
  c = leds;

  /* Clear everything */
  ti_lib_gpio_clear_multi_dio(BOARD_LED_ALL);

  if((leds & LEDS_RED) == LEDS_RED) {
    ti_lib_gpio_set_dio(BOARD_IOID_LED_1);
  }
  if((leds & LEDS_YELLOW) == LEDS_YELLOW) {
    ti_lib_gpio_set_dio(BOARD_IOID_LED_2);
  }
  if((leds & LEDS_GREEN) == LEDS_GREEN) {
    ti_lib_gpio_set_dio(BOARD_IOID_LED_3);
  }
  if((leds & LEDS_ORANGE) == LEDS_ORANGE) {
    ti_lib_gpio_set_dio(BOARD_IOID_LED_4);
  }
}
/*---------------------------------------------------------------------------*/
/** @} */
