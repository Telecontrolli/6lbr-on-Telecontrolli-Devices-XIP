/*
 * Author: Telecontrolli srl
 * File:button-sensor.h V1.0
 * Description: This file is part of the Contiki operating system.
 */
#ifndef BUTTON_SENSOR_H_
#define BUTTON_SENSOR_H_

#include "lib/sensors.h"

extern const struct sensors_sensor button_sensor;
extern const struct sensors_sensor button_sensor2;

#define BUTTON_SENSOR "Button"

#endif /* BUTTON_SENSOR_H_ */
