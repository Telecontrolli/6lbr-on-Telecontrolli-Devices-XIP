/*
 * Author: Telecontrolli srl
 * File: coap-server.c V1.4
 * Description: The file coap-server.c built the list of resources.
 */
/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "contiki-net.h"
#include "rest-engine.h"
#include "board-peripherals.h"
#include "rf-core/rf-ble.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*---------------------------------------------------------------------------*/
/* Common resources */
extern resource_t res_leds;

extern resource_t res_batmon_temp;
extern resource_t res_batmon_volt;
extern resource_t res_adc_ioid14;
extern resource_t res_digital_ioid0;
extern resource_t res_digital;

extern resource_t res_device_sw;
extern resource_t res_device_hw;
//extern resource_t res_device_uptime;
//extern resource_t res_device_cfg_reset;

//extern resource_t res_parent_rssi;
extern resource_t res_parent_ip;

#if RF_BLE_ENABLED
//extern resource_t res_ble_advd;
#endif

extern resource_t res_toggle_red;
extern resource_t res_toggle_green;
extern resource_t res_toggle_yellow;
//extern resource_t res_toggle_orange;

/* Board-specific resources */
#if BOARD_SENSORTAG
extern resource_t res_bmp280_temp;
extern resource_t res_bmp280_press;
extern resource_t res_tmp007_amb;
extern resource_t res_tmp007_obj;
extern resource_t res_hdc1000_temp;
extern resource_t res_hdc1000_hum;
extern resource_t res_opt3001_light;
extern resource_t res_mpu_acc_x;
extern resource_t res_mpu_acc_y;
extern resource_t res_mpu_acc_z;
extern resource_t res_mpu_gyro_x;
extern resource_t res_mpu_gyro_y;
extern resource_t res_mpu_gyro_z;
#else
// extern resource_t res_toggle_orange;
// extern resource_t res_toggle_yellow;
#endif
/*---------------------------------------------------------------------------*/
const char *coap_server_not_found_msg = "Resource not found";
const char *coap_server_supported_msg = "Supported:"
                                        "text/plain,"
                                        "application/json,"
                                        "application/xml";
/*---------------------------------------------------------------------------*/
static void
start_board_resources(void)
{

  rest_activate_resource(&res_toggle_green, "Output/Digital/IOID11");
  rest_activate_resource(&res_toggle_red, "Output/Led on Board/Red");
  rest_activate_resource(&res_toggle_yellow, "Output/Led on Board/Yellow");
  //rest_activate_resource(&res_toggle_orange, "Output/Led on Board/Orange");
  rest_activate_resource(&res_digital, "Output/Digital");
  rest_activate_resource(&res_leds, "lt");

#if BOARD_SMARTRF06EB
  // rest_activate_resource(&res_toggle_yellow, "lt/y");
  // rest_activate_resource(&res_toggle_orange, "lt/o");
#endif
}
/*---------------------------------------------------------------------------*/
PROCESS(coap_server_process, "CC26XX CoAP Server");
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(coap_server_process, ev, data)
{
  PROCESS_BEGIN();

  printf("CC26XX CoAP Server\n");

  /* Initialize the REST engine. */
  rest_init_engine();

  rest_activate_resource(&res_batmon_temp, "Sensor/batmon/Temperature");
  rest_activate_resource(&res_batmon_volt, "Sensor/batmon/Battery Level");
  rest_activate_resource(&res_adc_ioid14, "Input/Analog/IOID14");
  rest_activate_resource(&res_digital_ioid0, "Input/Digital/IOID0");
  
  rest_activate_resource(&res_device_hw, "Device/Middleware/Hardware");
  rest_activate_resource(&res_device_sw, "Device/Middleware/Software");
  //rest_activate_resource(&res_device_uptime, "Device/Uptime");
  //rest_activate_resource(&res_device_cfg_reset, "Device/Reset");

  //rest_activate_resource(&res_parent_rssi, "Rete/Nodo/RSSI");
  rest_activate_resource(&res_parent_ip, "Network/Address/IPv6");

#if RF_BLE_ENABLED
  //rest_activate_resource(&res_ble_advd, "Device/ble_advd");
  #endif

  start_board_resources();

  /* Define application-specific events here. */
  while(1) {
    PROCESS_WAIT_EVENT();
  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/
/**
 * @}
 */
