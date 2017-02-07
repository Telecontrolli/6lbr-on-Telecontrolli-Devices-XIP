/*
 * Author: Telecontrolli srl
 * File: slip-net.c.h V1.1
 * Description: The file slip-net.c define the various components and set initial conditions
 */

#include "contiki.h"
#include "net/netstack.h"
#include "net/ip/uip.h"
#include "net/packetbuf.h"
#include "dev/slip.h"
#include <stdio.h>

#define SLIP_END     0300
#define SLIP_ESC     0333
#define SLIP_ESC_END 0334
#define SLIP_ESC_ESC 0335

#define DEBUG 0

/*---------------------------------------------------------------------------*/
void
slipnet_init(void)
{
}
/*---------------------------------------------------------------------------*/
void
slip_send_packet(const uint8_t *ptr, int len)
{
  uint16_t i;
  uint8_t c;

  slip_arch_writeb(SLIP_END);
  for(i = 0; i < len; ++i) {
    c = *ptr++;
    if(c == SLIP_END) {
      slip_arch_writeb(SLIP_ESC);
      c = SLIP_ESC_END;
    } else if(c == SLIP_ESC) {
      slip_arch_writeb(SLIP_ESC);
      c = SLIP_ESC_ESC;
    }
    slip_arch_writeb(c);
  }
  slip_arch_writeb(SLIP_END);
}
/*---------------------------------------------------------------------------*/
void
slipnet_input(void)
{
  int i;
  /* radio should be configured for filtering so this should be simple */
  /* this should be sent over SLIP! */
  /* so just copy into uip-but and send!!! */
  /* Format: !R<data> ? */
  uip_len = packetbuf_datalen();
  i = packetbuf_copyto(uip_buf);

  if(DEBUG) {
    printf("Slipnet got input of len: %d, copied: %d\n",
	   packetbuf_datalen(), i);

    for(i = 0; i < uip_len; i++) {
      printf("%02x", (unsigned char) uip_buf[i]);
      if((i & 15) == 15) printf("\n");
      else if((i & 7) == 7) printf(" ");
    }
    printf("\n");
  }

  /* printf("SUT: %u\n", uip_len); */
  slip_send_packet(uip_buf, uip_len);
}
/*---------------------------------------------------------------------------*/
const struct network_driver slipnet_driver = {
  "slipnet",
  slipnet_init,
  slipnet_input
};
/*---------------------------------------------------------------------------*/
