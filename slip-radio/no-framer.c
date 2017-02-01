/*
 * Author: Telecontrolli srl
 * File: project-conf.h V1.0
 * Description: MAC framer that does nothing...
 */
#include "net/mac/framer.h"
#include "net/mac/frame802154.h"
#include "net/packetbuf.h"
#include <string.h>

#define DEBUG 0

#if DEBUG
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#define PRINTADDR(addr) PRINTF(" %02x%02x:%02x%02x:%02x%02x:%02x%02x ", ((uint8_t *)addr)[0], ((uint8_t *)addr)[1], ((uint8_t *)addr)[2], ((uint8_t *)addr)[3], ((uint8_t *)addr)[4], ((uint8_t *)addr)[5], ((uint8_t *)addr)[6], ((uint8_t *)addr)[7])
#else
#define PRINTF(...)
#define PRINTADDR(addr)
#endif

/**  \brief The 16-bit identifier of the PAN on which the device is
 *   sending to.  If this value is 0xffff, the device is not
 *   associated.
 */
static const uint16_t mac_dst_pan_id = IEEE802154_PANID;

/**  \brief The 16-bit identifier of the PAN on which the device is
 *   operating.  If this value is 0xffff, the device is not
 *   associated.
 */
static const uint16_t mac_src_pan_id = IEEE802154_PANID;
/*---------------------------------------------------------------------------*/
static int
is_broadcast_addr(uint8_t mode, uint8_t *addr)
{
  int i = mode == FRAME802154_SHORTADDRMODE ? 2 : 8;
  while(i-- > 0) {
    if(addr[i] != 0xff) {
      return 0;
    }
  }
  return 1;
}
/*---------------------------------------------------------------------------*/
static int
hdr_length(void)
{
  /* never adds any header */
  return 0;
}
/*---------------------------------------------------------------------------*/
static int
create(void)
{
  /* nothing extra... */
  return 0;
}
/*---------------------------------------------------------------------------*/
static int
parse(void)
{
  frame802154_t frame;
  int len;
  len = packetbuf_datalen();
  if(frame802154_parse(packetbuf_dataptr(), len, &frame)) {
    if(frame.fcf.dest_addr_mode) {
      if(frame.dest_pid != mac_src_pan_id &&
         frame.dest_pid != FRAME802154_BROADCASTPANDID) {
        /* Packet to another PAN */
        PRINTF("15.4: for another pan %u\n", frame.dest_pid);
        return 0;
      }
      if(!is_broadcast_addr(frame.fcf.dest_addr_mode, frame.dest_addr)) {
        packetbuf_set_addr(PACKETBUF_ADDR_RECEIVER, (linkaddr_t *)&frame.dest_addr);
      }
    }
    packetbuf_set_addr(PACKETBUF_ADDR_SENDER, (linkaddr_t *)&frame.src_addr);
    packetbuf_set_attr(PACKETBUF_ATTR_PENDING, frame.fcf.frame_pending);
    packetbuf_set_attr(PACKETBUF_ATTR_MAC_SEQNO, frame.seq);

    PRINTF("15.4-IN: %2X", frame.fcf.frame_type);
    PRINTADDR(packetbuf_addr(PACKETBUF_ADDR_SENDER));
    PRINTADDR(packetbuf_addr(PACKETBUF_ADDR_RECEIVER));
    PRINTF("%u (%u)\n", packetbuf_datalen(), len);

    return 0;
  }
  return 0;
}
/*---------------------------------------------------------------------------*/
const struct framer no_framer = {
  hdr_length,
  create,
  parse
};
