/*
 * Author: Telecontrolli srl
 * File: res-net.c V1.4
 * Description: CoAP resource handler for network-related resources
 */
/*---------------------------------------------------------------------------*/
#include "contiki.h"
#include "rest-engine.h"
#include "er-coap.h"
#include "coap-server.h"
#include "cc26xx-web-demo.h"

#include "ti-lib.h"

#include <string.h>
/*---------------------------------------------------------------------------*/
extern int def_rt_rssi;
/*---------------------------------------------------------------------------*/
static void
res_get_handler_parent_rssi(void *request, void *response, uint8_t *buffer,
                            uint16_t preferred_size, int32_t *offset)
{
  unsigned int accept = -1;

  REST.get_header_accept(request, &accept);

  if(accept == -1 || accept == REST.type.TEXT_PLAIN) {
    REST.set_header_content_type(response, REST.type.TEXT_PLAIN);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "%d", def_rt_rssi);

    REST.set_response_payload(response, (uint8_t *)buffer, strlen((char *)buffer));
  } else if(accept == REST.type.APPLICATION_JSON) {
    REST.set_header_content_type(response, REST.type.APPLICATION_JSON);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "{\"Parent RSSI\":\"%d\"}",
             def_rt_rssi);

    REST.set_response_payload(response, buffer, strlen((char *)buffer));
  } else if(accept == REST.type.APPLICATION_XML) {
    REST.set_header_content_type(response, REST.type.APPLICATION_XML);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE,
             "<parent-rssi val=\"%d\"/>", def_rt_rssi);

    REST.set_response_payload(response, buffer, strlen((char *)buffer));
  } else {
    REST.set_response_status(response, REST.status.NOT_ACCEPTABLE);
    REST.set_response_payload(response, coap_server_supported_msg,
                              strlen(coap_server_supported_msg));
  }
}
/*---------------------------------------------------------------------------*/
static void
res_get_handler_pref_parent(void *request, void *response, uint8_t *buffer,
                            uint16_t preferred_size, int32_t *offset)
{
  unsigned int accept = -1;
  char def_rt_str[64];

  REST.get_header_accept(request, &accept);

  memset(def_rt_str, 0, sizeof(def_rt_str));
  cc26xx_web_demo_ipaddr_sprintf(def_rt_str, sizeof(def_rt_str),
                                 uip_ds6_defrt_choose());

  if(accept == -1 || accept == REST.type.TEXT_PLAIN) {
    REST.set_header_content_type(response, REST.type.TEXT_PLAIN);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "%s", def_rt_str);

    REST.set_response_payload(response, (uint8_t *)buffer, strlen((char *)buffer));
  } else if(accept == REST.type.APPLICATION_JSON) {
    REST.set_header_content_type(response, REST.type.APPLICATION_JSON);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE, "{\"Parent\":\"%s\"}",
             def_rt_str);

    REST.set_response_payload(response, buffer, strlen((char *)buffer));
  } else if(accept == REST.type.APPLICATION_XML) {
    REST.set_header_content_type(response, REST.type.APPLICATION_XML);
    snprintf((char *)buffer, REST_MAX_CHUNK_SIZE,
             "<parent=\"%s\"/>", def_rt_str);

    REST.set_response_payload(response, buffer, strlen((char *)buffer));
  } else {
    REST.set_response_status(response, REST.status.NOT_ACCEPTABLE);
    REST.set_response_payload(response, coap_server_supported_msg,
                              strlen(coap_server_supported_msg));
  }
}
/*---------------------------------------------------------------------------*/
RESOURCE(res_parent_rssi, "title=\"Nodo RSSI\";rt=\"dBm\"",
         res_get_handler_parent_rssi, NULL, NULL, NULL);
/*---------------------------------------------------------------------------*/
RESOURCE(res_parent_ip, "title=\"Nodo preferito\";rt=\"Indirizzo IPv6\"",
         res_get_handler_pref_parent, NULL, NULL, NULL);
/*---------------------------------------------------------------------------*/
/** @} */
