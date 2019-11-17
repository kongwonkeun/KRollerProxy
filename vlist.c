/**/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <windows.h>

#include "vlist.h"

int vlist_init(vlist_s *st, vlist_destroy_func_t destroyitem) 
{
    st->head = NULL;
    st->tail = NULL;
    st->count = 0;
    st->owner = 1;
    st->destroyitem = destroyitem;
    return 0;
}

void vlist_cleanup(vlist_s *st)
{
    vlist_clear(st);
}

void vlist_clear(vlist_s *st)
{
    vlist_i *it = st->head;
    while (it) {
        vlist_delete(st, it);
        it = st->head;
    }
}

vlist_i *vlist_addfirst(vlist_s *st, void *data)
{
    vlist_i *it = malloc(sizeof(vlist_i));
    if (!it)
        return NULL;
    
    it->data = data;
    it->prev = NULL;
    it->next = NULL;
    st->head = it;
    st->tail = it;
    st->count = 1;
    return it;
}

vlist_i *vlist_add(vlist_s *st, vlist_i *it, void *data)
{
    vlist_i *nextit;
    if (st->count == 0)
        return vlist_addfirst(st, data);
    
    nextit = it->next;
    it->next = malloc(sizeof(vlist_i));
    if (!it->next)
        return NULL;
    
    it->next->data = data;
    it->next->prev = it;
    it->next->next = nextit;

    if (nextit)
        nextit->prev = it->next;
    else
        st->tail = it->next;

    st->count++;
    return it->next;
}

void vlist_delete(vlist_s *st, vlist_i *it)
{
    if (st->owner) {
        st->destroyitem(it->data);
        it->data = NULL;
    }
    if (it->next)
        it->next->prev = it->prev;
    else
        st->tail = it->prev;
        
    if (it->prev)
        it->prev->next = it->next;
    else
        st->head = it->next;
        
    free(it);
    st->count--;
}

/**/
