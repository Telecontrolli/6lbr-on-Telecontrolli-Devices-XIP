/*
 * Author: Telecontrolli srl
 * File: board.c V1.2
 * Description:Board-initialisation for the Srf06EB with a CC13xx/CC26xx EM.
 */
/*---------------------------------------------------------------------------*/
#include "contiki-conf.h"
#include "ti-lib.h"
#include "lpm.h"
#include "prcm.h"
#include "hw_sysctl.h"

#include <stdint.h>
#include <string.h>
/*---------------------------------------------------------------------------*/
static void
lpm_handler(uint8_t mode)
{
  /* Ambient light sensor (off, output low) */
  ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_ALS_PWR);
  ti_lib_gpio_clear_dio(BOARD_IOID_ALS_PWR);
  ti_lib_ioc_pin_type_gpio_input(BOARD_IOID_ALS_OUT);
  ti_lib_ioc_io_port_pull_set(BOARD_IOID_ALS_OUT, IOC_NO_IOPULL);
}
/*---------------------------------------------------------------------------*/
static void
wakeup_handler(void)
{
  /* Turn on the PERIPH PD */
  ti_lib_prcm_power_domain_on(PRCM_DOMAIN_PERIPH);
  while((ti_lib_prcm_power_domain_status(PRCM_DOMAIN_PERIPH)
        != PRCM_DOMAIN_POWER_ON));
}
/*---------------------------------------------------------------------------*/
/*
 * Declare a data structure to register with LPM.
 * We don't care about what power mode we'll drop to, we don't care about
 * getting notified before deep sleep. All we need is to be notified when we
 * wake up so we can turn power domains back on
 */
LPM_MODULE(srf_module, NULL, lpm_handler, wakeup_handler, LPM_DOMAIN_NONE);
/*---------------------------------------------------------------------------*/
static void
configure_unused_pins(void)
{
  /* Turn off 3.3-V domain (lcd/sdcard power, output low) */
  ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_3V3_EN);
  ti_lib_gpio_clear_dio(BOARD_IOID_3V3_EN);

  /* Accelerometer (PWR output low, CSn output, high) */
  ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_ACC_PWR);
  ti_lib_gpio_clear_dio(BOARD_IOID_ACC_PWR);
}
/*---------------------------------------------------------------------------*/
void
board_init()
{
  uint8_t int_disabled = ti_lib_int_master_disable();

  /* Turn on relevant PDs */
  wakeup_handler();

  /* Enable GPIO peripheral */
  ti_lib_prcm_peripheral_run_enable(PRCM_PERIPH_GPIO);

  /* Apply settings and wait for them to take effect */
  ti_lib_prcm_load_set();
  while(!ti_lib_prcm_load_get());

  lpm_register_module(&srf_module);

  configure_unused_pins();

  /* Re-enable interrupt if initially enabled. */
  if(!int_disabled) {
    ti_lib_int_master_enable();
  }
}
/*---------------------------------------------------------------------------*/
/** @} */
