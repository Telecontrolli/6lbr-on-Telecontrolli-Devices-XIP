/*
 * Author: Telecontrolli srl
 * File: httpd-simple.h V1.0
 * Description: A simple webserver
 */

#ifndef HTTPD_SIMPLE_H_
#define HTTPD_SIMPLE_H_

#include "contiki-net.h"

/* The current internal border router webserver ignores the requested file name */
/* and needs no per-connection output buffer, so save some RAM */
#ifndef WEBSERVER_CONF_CFS_PATHLEN
#define HTTPD_PATHLEN 2
#else /* WEBSERVER_CONF_CFS_CONNS */
#define HTTPD_PATHLEN WEBSERVER_CONF_CFS_PATHLEN
#endif /* WEBSERVER_CONF_CFS_CONNS */

struct httpd_state;
typedef char (* httpd_simple_script_t)(struct httpd_state *s);

struct httpd_state {
  struct timer timer;
  struct psock sin, sout;
  struct pt outputpt;
  char inputbuf[HTTPD_PATHLEN + 24];
/*char outputbuf[UIP_TCP_MSS]; */
  char filename[HTTPD_PATHLEN];
  httpd_simple_script_t script;
  char state;
};

void httpd_init(void);
void httpd_appcall(void *state);

httpd_simple_script_t httpd_simple_get_script(const char *name);

#define SEND_STRING(s, str) PSOCK_SEND(s, (uint8_t *)str, strlen(str))

#endif /* HTTPD_SIMPLE_H_ */
