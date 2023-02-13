/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include <sys/time.h>
#include "syscall.h"

int
_gettimeofday (struct timeval *ptimeval, void *ptimezone)
{
  return syscall2 (SYS_gettimeofday, (long)ptimeval, (long)ptimezone);
}
