/*
 * Author: Telecontrolli srl
 * File: net-uart.h V1.2
 * Description: The file net-uart.h define the function of net-uart.c
 */
#ifndef NET_UART_H_
#define NET_UART_H_
/*---------------------------------------------------------------------------*/
#include "net/ip/uip.h"

#include <stdint.h>
/*---------------------------------------------------------------------------*/
#define NET_UART_IP_ADDR_STRLEN   64
/*---------------------------------------------------------------------------*/
PROCESS_NAME(net_uart_process);
/*---------------------------------------------------------------------------*/
typedef struct net_uart_config_s {
  char remote_address[NET_UART_IP_ADDR_STRLEN];
  uint16_t remote_port;
  uint8_t enable;
} net_uart_config_t;
/*---------------------------------------------------------------------------*/
#endif /* NET_UART_H_ */
/*---------------------------------------------------------------------------*/
