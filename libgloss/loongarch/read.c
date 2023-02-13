/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "syscall.h"

int _read (int file, char *ptr, int len)
{
  return syscall3 (SYS_read, file, (long)ptr, len);
}
