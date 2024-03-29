/**/

#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "string.h"

cfg_item_i cfg_int_defs[CFG_IEND] = {
    { "comm_baud", 9600 },
    { "comm_databits", 8 },
    { "comm_stopbits", 1 },
    { "comm_port", 30 },
    { "net_port", 5331 },
    { "timeout", 300 },
    { "net_protocol", 1 }
};

cfg_item_s cfg_str_defs[CFG_SEND] = {
    { "comm_parity", "none" },
    { "serial_device", "/dev/ttyS0" },
    { "net_allow", "all" },
    { "net_deny", "none" }
};

int cfg_init(cfg_s *cfg)
{
    int i;

    for (i = 0; i < CFG_IEND; i++) {
        cfg->ints[i].key = NULL;
        str_assign(&cfg->ints[i].key, cfg_int_defs[i].key);
        cfg->ints[i].val = cfg_int_defs[i].val;
    }
    for (i = 0; i < CFG_SEND; i++) {
        cfg->strs[i].key = NULL;
        str_assign(&cfg->strs[i].key, cfg_str_defs[i].key);
        cfg->strs[i].val = NULL;;
        str_assign(&cfg->strs[i].val, cfg_str_defs[i].val);		
    }
    return 0;
}

void cfg_cleanup(cfg_s *cfg)
{
    int i;

    for (i = 0; i < CFG_IEND; i++) {
        str_cleanup(&cfg->ints[i].key);
    }
    for (i = 0; i < CFG_SEND; i++) {
        str_cleanup(&cfg->strs[i].key);
        str_cleanup(&cfg->strs[i].val);
    }
}

void cfg_assign(cfg_s *dst, cfg_s *src)
{
    int i;

    for (i = 0; i < CFG_IEND; i++)
        dst->ints[i].val = src->ints[i].val;
    for (i = 0; i < CFG_SEND; i++)
        str_assign(&dst->strs[i].val, src->strs[i].val);
}

/**/
