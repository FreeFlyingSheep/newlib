/* SPDX-License-Identifier: GPL-2.0-only
 *
 * Copyright (C) 2023 Loongson Technology Corporation Limited
 */

extern char _end[];

void *
_sbrk (int incr)
{
  static char *heap_ptr;
  char *base;

  if (!heap_ptr)
    heap_ptr = (char *)&_end;
  base = heap_ptr;
  heap_ptr += incr;

  return base;
}
