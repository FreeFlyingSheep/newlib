/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

#include "syscall.h"

void
_exit (int rc)
{
  syscall0 (SYS_exit);

  while (1)
    ;
}
