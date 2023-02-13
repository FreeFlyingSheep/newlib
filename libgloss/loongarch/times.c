/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include <time.h>
#include <sys/time.h>
#include <sys/times.h>
#include "syscall.h"

int _gettimeofday (struct timeval *ptimeval, void *ptimezone);

clock_t
_times (struct tms *buf)
{
  static char initialized;
  static struct timeval t0;
  struct timeval t;

  _gettimeofday (&t, 0);

  // when called for the first time, initialize t0
  if (!initialized) {
    t0.tv_sec = t.tv_sec;
    t0.tv_usec = t.tv_usec;
    initialized = 1;
  }

  long long utime = (t.tv_sec - t0.tv_sec) * 1000000 + (t.tv_usec - t0.tv_usec);
  buf->tms_utime = utime * CLOCKS_PER_SEC / 1000000;
  buf->tms_stime = buf->tms_cstime = buf->tms_cutime = 0;

  return buf->tms_utime;
}
