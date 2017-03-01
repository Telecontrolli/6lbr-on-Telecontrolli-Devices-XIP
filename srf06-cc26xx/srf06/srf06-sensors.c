/*
 * Author: Telecontrolli srl
 * File: srf06-sensors.c V1.3
 * Description:Generic module controlling sensors on the SmartRF06EB when a CC26xx is mounted on the board
 */
/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "srf06/button-sensor.h"
#include "srf06/als-sensor.h"

#include <string.h>
/*---------------------------------------------------------------------------*/
/** \brief Exports a global symbol to be used by the sensor API */
SENSORS(&button_select_sensor, &button_left_sensor, &button_right_sensor,
        &button_up_sensor, &button_down_sensor, &als_sensor);
/*---------------------------------------------------------------------------*/
/** @} */
