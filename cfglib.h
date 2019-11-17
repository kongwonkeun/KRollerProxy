#ifndef CFGLIB_H
#define CFGLIB_H

#include <stdlib.h>

typedef struct
{
    char *key;
    char *val;
}
cfg_item_s;

typedef struct
{
    char *key;
    int   val;
}
cfg_item_i;

#endif /* CFGLIB_H */
