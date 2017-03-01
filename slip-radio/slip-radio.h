/*
 *  * Author: Telecontrolli srl
 * File: slip-radio.h V1.3
 * Description: The file slip-radio.h set the sensors of slip-radio
 */
#ifndef SLIP_RADIO_H_
#define SLIP_RADIO_H_

struct slip_radio_sensors {
  /** Initialize the driver */
  void (* init)(void);
  /** Send the sensor data packet via the command send */
  void (* send)(void);
};

#endif /* SLIP_RADIO_H_ */
