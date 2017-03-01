/*
 * Author: Telecontrolli srl
 * File: project-conf.h V1.3
 * Description: The file project-conf.h define the various components and set initial conditions
 */

#ifndef PROJECT_CONF_H_
#define PROJECT_CONF_H_

#undef QUEUEBUF_CONF_NUM
#define QUEUEBUF_CONF_NUM          4

#undef UIP_CONF_BUFFER_SIZE
#define UIP_CONF_BUFFER_SIZE    140

#define RF_CORE_CONF_CHANNEL 	25
#undef UIP_CONF_ROUTER
#define UIP_CONF_ROUTER                 0

#define CMD_CONF_OUTPUT slip_radio_cmd_output

/* add the cmd_handler_cc2420 + some sensors if TARGET_SKY */
#ifdef CONTIKI_TARGET_SKY
#define CMD_CONF_HANDLERS slip_radio_cmd_handler,cmd_handler_cc2420
#define SLIP_RADIO_CONF_SENSORS slip_radio_sky_sensors
/* add the cmd_handler_rf230 if TARGET_NOOLIBERRY. Other RF230 platforms can be added */
#elif CONTIKI_TARGET_NOOLIBERRY
#define CMD_CONF_HANDLERS slip_radio_cmd_handler,cmd_handler_rf230
#elif CONTIKI_TARGET_ECONOTAG
#define CMD_CONF_HANDLERS slip_radio_cmd_handler,cmd_handler_mc1322x
#else
#define CMD_CONF_HANDLERS slip_radio_cmd_handler
#endif


/* configuration for the slipradio/network driver */
#undef NETSTACK_CONF_MAC
#define NETSTACK_CONF_MAC     nullmac_driver

#undef NETSTACK_CONF_RDC
/* #define NETSTACK_CONF_RDC     nullrdc_noframer_driver */
#define NETSTACK_CONF_RDC     contikimac_driver

#undef NETSTACK_CONF_NETWORK
#define NETSTACK_CONF_NETWORK slipnet_driver

#undef NETSTACK_CONF_FRAMER
#define NETSTACK_CONF_FRAMER no_framer

#undef CC2420_CONF_AUTOACK
#define CC2420_CONF_AUTOACK              1

#undef UART1_CONF_RX_WITH_DMA
#define UART1_CONF_RX_WITH_DMA           1

#endif /* PROJECT_CONF_H_ */
