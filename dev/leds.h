/*
 * Author: Telecontrolli srl
 * File: leds.h V1.4
 * Description: The LEDs API defines a set of functions for accessing LEDs for Contiki plaforms with LEDs.
 */

#ifndef LEDS_H_
#define LEDS_H_

/* Allow platform to override LED numbering */
#include "contiki-conf.h"

void leds_init(void);

/**
 * Blink all LEDs.
 */
void leds_blink(void);

#ifndef LEDS_GREEN
#define LEDS_GREEN  1
#endif /* LEDS_VERDE */
#ifndef LEDS_YELLOW
#define LEDS_YELLOW  2
#endif /* LEDS_GIALLO */
#ifndef LEDS_RED
#define LEDS_RED  4
#endif /* LEDS_ROSSO */
#ifndef LEDS_BLUE
#define LEDS_BLUE LEDS_YELLOW
#endif /* LEDS_BLU */

#ifdef LEDS_CONF_ALL
#define LEDS_ALL    LEDS_CONF_ALL
#else /* LEDS_CONF_ALL */
#define LEDS_ALL    7
#endif /* LEDS_CONF_ALL */

/**
 * Returns the current status of all leds
 */
unsigned char leds_get(void);
void leds_set(unsigned char leds);
void leds_on(unsigned char leds);
void leds_off(unsigned char leds);
void leds_toggle(unsigned char leds);

/**
 * Leds implementation
 */
void leds_arch_init(void);
unsigned char leds_arch_get(void);
void leds_arch_set(unsigned char leds);

#endif /* LEDS_H_ */

/** @} */
/** @} */
