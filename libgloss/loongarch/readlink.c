/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include <unistd.h>
#include "stat.h"
#include "syscall.h"

int
_readlink (const char *path,
        char *buf,
        size_t bufsize)
{
  return syscall4 (SYS_readlinkat, AT_FDCWD, (long)path, (long)buf, bufsize);
}
