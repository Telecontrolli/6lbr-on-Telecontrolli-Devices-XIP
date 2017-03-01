/*
 * Author: Telecontrolli srl
 * File: res-device.c V1.3
 * Description: CoAP resource handler for CC26XX software and hardware version
/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "rest-engine.h"
#include "er-coap.h"
#include "sys/clock.h"
#include "coap-server.h"
#include "cc26xx-web-demo.h"

#include "ti-lib.h"

#include <string.h>
/*---------------------------------------------------------------------------*/
static uint16_t
detect_chip(void)
{
  if(ti_lib_chipinfo_chip_family_is_cc26xx()) {
    if(ti_lib_chipinfo_supports_ieee_802_15_4() == true) {
      if(ti_lib_chipinfo_supports_ble() == true) {
        return 2650;
      } else {
        return 2630;
      }
    } else {
      return 2640;
    }
  } else if(ti_lib_chipinfo_chip_family_is_cc13xx()) {
    if(ti_lib_chipinfo_supports_ble() == false &&
       ti_lib_chipinfo_supports_ieee_802_15_4() == false) {
      return 1310;
    } else if(ti_lib_chipinfo_supports_ble() == true &&
        ti_lib_chipinfo_supports_ieee_802_15_4() == true) {
      return 1350;
    }
  }

  return 0;
}
/*---------------------------------------------------------------------------*/
static void
res_get_handler_hw(void *request, void *response, uint8_t *buffer,
                   uint16_t preferred_size, int32_t *offset)
{
  unsigned int accept = -1;
  uint16_t chip = detect_chip();

  REST.get_header_accept(request, &accept);

  if(accept == -1 || accept == REST.type.TEXT_PLAIN) {
    REST.set_header_content_type(response, REST.type.TEXT_PLAIN);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "%s on CC%u", BOARD_STRING,
             chip);

    REST.set_response_payload(response, (uint8_t *)buffer, strlen((char *)buffer));
  } else if(accept == REST.type.APPLICATION_JSON) {
    REST.set_header_content_type(response, REST.type.APPLICATION_JSON);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "{\"HW Ver\":\"%s on CC%u\"}",
             BOARD_STRING, chip);

    REST.set_response_payload(response, buffer, strlen((char *)buffer));
  } else if(accept == REST.type.APPLICATION_XML) {
    REST.set_header_content_type(response, REST.type.APPLICATION_XML);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE,
             "<hw-ver val=\"%s on CC%u\"/>", BOARD_STRING,
             chip);

    REST.set_response_payload(response, buffer, strlen((char *)buffer));
  } else {
    REST.set_response_status(response, REST.status.NOT_ACCEPTABLE);
    REST.set_response_payload(response, coap_server_supported_msg,
                              strlen(coap_server_supported_msg));
  }
}
/*---------------------------------------------------------------------------*/
static void
res_get_handler_sw(void *request, void *response, uint8_t *buffer,
                   uint16_t preferred_size, int32_t *offset)
{
  unsigned int accept = -1;

  REST.get_header_accept(request, &accept);

  if(accept == -1 || accept == REST.type.TEXT_PLAIN) {
    REST.set_header_content_type(response, REST.type.TEXT_PLAIN);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "%s", CONTIKI_VERSION_STRING);

    REST.set_response_payload(response, (uint8_t *)buffer, strlen((char *)buffer));
  } else if(accept == REST.type.APPLICATION_JSON) {
    REST.set_header_content_type(response, REST.type.APPLICATION_JSON);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "{\"SW Ver\":\"%s\"}",
             CONTIKI_VERSION_STRING);

    REST.set_response_payload(response, buffer, strlen((char *)buffer));
  } else if(accept == REST.type.APPLICATION_XML) {
    REST.set_header_content_type(response, REST.type.APPLICATION_XML);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE,
             "<sw-ver val=\"%s\"/>", CONTIKI_VERSION_STRING);

    REST.set_response_payload(response, buffer, strlen((char *)buffer));
  } else {
    REST.set_response_status(response, REST.status.NOT_ACCEPTABLE);
    REST.set_response_payload(response, coap_server_supported_msg,
                              strlen(coap_server_supported_msg));
  }
}
/*---------------------------------------------------------------------------*/
static void
res_get_handler_uptime(void *request, void *response, uint8_t *buffer,
                       uint16_t preferred_size, int32_t *offset)
{
  unsigned int accept = -1;

  REST.get_header_accept(request, &accept);

  if(accept == -1 || accept == REST.type.TEXT_PLAIN) {
    REST.set_header_content_type(response, REST.type.TEXT_PLAIN);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "%lu", clock_seconds());

    REST.set_response_payload(response, (uint8_t *)buffer, strlen((char *)buffer));
  } else if(accept == REST.type.APPLICATION_JSON) {
    REST.set_header_content_type(response, REST.type.APPLICATION_JSON);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "{\"uptime\":%lu}",
             clock_seconds());

    REST.set_response_payload(response, buffer, strlen((char *)buffer));
  } else if(accept == REST.type.APPLICATION_XML) {
    REST.set_header_content_type(response, REST.type.APPLICATION_XML);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE,
             "<uptime val=\"%lu\" unit=\"sec\"/>", clock_seconds());

    REST.set_response_payload(response, buffer, strlen((char *)buffer));
  } else {
    REST.set_response_status(response, REST.status.NOT_ACCEPTABLE);
    REST.set_response_payload(response, coap_server_supported_msg,
                              strlen(coap_server_supported_msg));
  }
}
/*---------------------------------------------------------------------------*/
static void
res_post_handler_cfg_reset(void *request, void *response, uint8_t *buffer,
                           uint16_t preferred_size, int32_t *offset)
{
  cc26xx_web_demo_restore_defaults();
}
/*---------------------------------------------------------------------------*/
RESOURCE(res_device_sw,
         "title=\"Versione Software\";rt=\"text\"",
         res_get_handler_sw,
         NULL,
         NULL,
         NULL);
/*---------------------------------------------------------------------------*/
RESOURCE(res_device_uptime,
         "title=\"Uptime\";rt=\"seconds\"",
         res_get_handler_uptime,
         NULL,
         NULL,
         NULL);
/*---------------------------------------------------------------------------*/
RESOURCE(res_device_hw,
         "title=\"Versione Hardware\";rt=\"text\"",
         res_get_handler_hw,
         NULL,
         NULL,
         NULL);
/*---------------------------------------------------------------------------*/
RESOURCE(res_device_cfg_reset,
         "title=\"Reset Dispositivo: METODO POST\";rt=\"Control\"",
         NULL, res_post_handler_cfg_reset, NULL, NULL);
/*---------------------------------------------------------------------------*/
/** @} */
