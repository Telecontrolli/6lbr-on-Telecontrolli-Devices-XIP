/*
 * Author: Telecontrolli srl
 * File: mqtt-client.h V1.3
 * Description: Header file for the CC26xx web demo MQTT client functionality
 */
/*---------------------------------------------------------------------------*/
#ifndef MQTT_CLIENT_H_
#define MQTT_CLIENT_H_
/*---------------------------------------------------------------------------*/
#define MQTT_CLIENT_CONFIG_ORG_ID_LEN        32
#define MQTT_CLIENT_CONFIG_TYPE_ID_LEN       32
#define MQTT_CLIENT_CONFIG_AUTH_TOKEN_LEN    32
#define MQTT_CLIENT_CONFIG_EVENT_TYPE_ID_LEN 32
#define MQTT_CLIENT_CONFIG_CMD_TYPE_LEN       8
#define MQTT_CLIENT_CONFIG_IP_ADDR_STR_LEN   64
/*---------------------------------------------------------------------------*/
#define MQTT_CLIENT_PUBLISH_INTERVAL_MAX      86400 /* secs: 1 day */
#define MQTT_CLIENT_PUBLISH_INTERVAL_MIN          5 /* secs */
/*---------------------------------------------------------------------------*/
PROCESS_NAME(mqtt_client_process);
/*---------------------------------------------------------------------------*/
/**
 * \brief Data structure declaration for the MQTT client configuration
 */
typedef struct mqtt_client_config {
  char org_id[MQTT_CLIENT_CONFIG_ORG_ID_LEN];
  char type_id[MQTT_CLIENT_CONFIG_TYPE_ID_LEN];
  char auth_token[MQTT_CLIENT_CONFIG_AUTH_TOKEN_LEN];
  char event_type_id[MQTT_CLIENT_CONFIG_EVENT_TYPE_ID_LEN];
  char broker_ip[MQTT_CLIENT_CONFIG_IP_ADDR_STR_LEN];
  char cmd_type[MQTT_CLIENT_CONFIG_CMD_TYPE_LEN];
  clock_time_t pub_interval;
  uint16_t broker_port;
} mqtt_client_config_t;
/*---------------------------------------------------------------------------*/
#endif /* MQTT_CLIENT_H_ */
/*---------------------------------------------------------------------------*/
/**
 * @}
 */
