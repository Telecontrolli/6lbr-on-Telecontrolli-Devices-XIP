/*
 * Author: Telecontrolli srl
 * File: res-ble-advd.c V1.2
 * Description: CoAP resource to start/stop/configure BLE advertisements
 */
/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "rest-engine.h"
#include "er-coap.h"
#include "rf-core/rf-ble.h"

#include <string.h>
#include <stdlib.h>
/*---------------------------------------------------------------------------*/
#define BLE_NAME_BUF_LEN 32
/*---------------------------------------------------------------------------*/
const char *forbidden_payload = "Name to advertise unspecified.\n"
                                "Use name=<name> in the request";
/*---------------------------------------------------------------------------*/
static void
res_ble_post_put_handler(void *request, void *response, uint8_t *buffer,
                         uint16_t preferred_size, int32_t *offset)
{
  size_t len = 0;
  const char *text = NULL;
  char name[BLE_NAME_BUF_LEN];
  int success = 0;
  int rv;

  memset(name, 0, BLE_NAME_BUF_LEN);

  len = REST.get_post_variable(request, "name", &text);

  if(len > 0 && len < BLE_NAME_BUF_LEN) {
    memcpy(name, text, len);
    rf_ble_beacond_config(0, name);
    success = 1;
  }

  len = REST.get_post_variable(request, "interval", &text);

  rv = atoi(text);

  if(rv > 0) {
    rf_ble_beacond_config((clock_time_t)(rv * CLOCK_SECOND), NULL);
    success = 1;
  }

  len = REST.get_post_variable(request, "mode", &text);

  if(len) {
    if(strncmp(text, "on", len) == 0) {
      if(rf_ble_beacond_start()) {
        success = 1;
      } else {
        REST.set_response_status(response, REST.status.FORBIDDEN);
        REST.set_response_payload(response, forbidden_payload,
                                  strlen(forbidden_payload));
        return;
      }
    } else if(strncmp(text, "off", len) == 0) {
      rf_ble_beacond_stop();
      success = 1;
    } else {
      success = 0;
    }
  }

  if(!success) {
    REST.set_response_status(response, REST.status.BAD_REQUEST);
  }
}
/*---------------------------------------------------------------------------*/
RESOURCE(res_ble_advd,
         "title=\"BLE advd config: POST/PUT name=<name>&mode=on|off"
         "&interval=<secs>\";rt=\"Control\"",
         NULL,
         res_ble_post_put_handler,
         res_ble_post_put_handler,
         NULL);
/*---------------------------------------------------------------------------*/
/** @} */
