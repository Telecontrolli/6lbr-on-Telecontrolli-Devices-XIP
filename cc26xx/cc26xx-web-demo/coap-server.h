/*
 * Author: Telecontrolli srl
 * File: coap-server.h V1.3
 * Description: The file coap-server.h define the function of coap_server.
 */
/*---------------------------------------------------------------------------*/
#include "sys/process.h"
/*---------------------------------------------------------------------------*/
#ifndef COAP_SERVER_H_
#define COAP_SERVER_H_
/*---------------------------------------------------------------------------*/
extern const char *coap_server_not_found_msg;
extern const char *coap_server_supported_msg;
/*---------------------------------------------------------------------------*/
PROCESS_NAME(coap_server_process);
/*---------------------------------------------------------------------------*/
#endif /* COAP_SERVER_H_ */
/*---------------------------------------------------------------------------*/
/**
 * @}
 */
