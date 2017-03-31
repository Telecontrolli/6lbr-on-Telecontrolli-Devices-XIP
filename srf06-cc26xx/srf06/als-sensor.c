/*
 * Author: Telecontrolli srl
 * File: als-sensor.c V1.4
 * Description: Driver for the SmartRF06EB ALS when a CC13xx/CC26xxEM is mounted on it
 */
/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "lib/sensors.h"
#include "srf06/als-sensor.h"
#include "sys/timer.h"
#include "dev/adc-sensor.h"
#include "dev/aux-ctrl.h"

#include "ti-lib.h"

#include <stdint.h>
/*---------------------------------------------------------------------------*/
static aux_consumer_module_t als_aux = {
  .clocks = AUX_WUC_ADI_CLOCK | AUX_WUC_ANAIF_CLOCK | AUX_WUC_SMPH_CLOCK
};
/*---------------------------------------------------------------------------*/
static int
config(int type, int enable)
{
  switch(type) {
  case SENSORS_HW_INIT:
    ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_ALS_PWR);
    break;
  case SENSORS_ACTIVE:
    ti_lib_rom_ioc_pin_type_gpio_output(BOARD_IOID_ALS_PWR);
    ti_lib_rom_ioc_port_configure_set(BOARD_IOID_ALS_OUT, IOC_PORT_GPIO,
                                      IOC_STD_OUTPUT);
    ti_lib_rom_ioc_pin_type_gpio_input(BOARD_IOID_ALS_OUT);

    if(enable) {
      ti_lib_gpio_set_dio(BOARD_IOID_ALS_PWR);
      aux_ctrl_register_consumer(&als_aux);
      ti_lib_aux_adc_select_input(ADC_COMPB_IN_AUXIO7);
      clock_delay_usec(2000);
    } else {
      ti_lib_gpio_clear_dio(BOARD_IOID_ALS_PWR);
      aux_ctrl_unregister_consumer(&als_aux);
    }
    break;
  default:
    break;
  }
  return 1;
}
/*---------------------------------------------------------------------------*/
static int
value(int type)
{
  int val;

  ti_lib_aux_adc_enable_sync(AUXADC_REF_VDDS_REL, AUXADC_SAMPLE_TIME_2P7_US,
                             AUXADC_TRIGGER_MANUAL);
  ti_lib_aux_adc_gen_manual_trigger();
  val = ti_lib_aux_adc_read_fifo();
  ti_lib_aux_adc_disable();

  return val;
}
/*---------------------------------------------------------------------------*/
static int
status(int type)
{
  return 1;
}
/*---------------------------------------------------------------------------*/
SENSORS_SENSOR(als_sensor, ALS_SENSOR, value, config, status);
/*---------------------------------------------------------------------------*/
/** @} */
