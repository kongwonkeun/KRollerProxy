#ifndef THREAD_H
#define THREAD_H

#include <windows.h>

typedef HANDLE thr_t;
typedef HANDLE thr_mutex_t;
typedef DWORD  thr_exitcode_t;
typedef LPTHREAD_START_ROUTINE thr_startfunc_ptr_t;
#define thr_startfunc_t thr_exitcode_t WINAPI

int   thr_create(thr_t *thread, int detached, thr_startfunc_ptr_t startfunc, void *arg);
void  thr_exit(thr_exitcode_t retval);

thr_mutex_t thr_mutex_create(void);
int   thr_mutex_destroy(thr_mutex_t *mutex);
int   thr_mutex_trylock(thr_mutex_t *mutex);
int   thr_mutex_unlock(thr_mutex_t *mutex);

#endif /* THREAD_H */
