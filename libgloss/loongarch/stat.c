/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "stat.h"
#include "syscall.h"

int
_stat (const char *file, struct stat *st)
{
  struct statx tmp;
  long ret;

  ret = syscall5 (SYS_statx, AT_FDCWD, (long)file, AT_NO_AUTOMOUNT, STATX_BASIC_STATS, (long)&tmp);
  _conv_stat (st, &tmp);

  return ret;
}
