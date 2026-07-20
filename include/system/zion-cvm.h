/*
 * Zion confidential virtual machine support.
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef SYSTEM_ZION_CVM_H
#define SYSTEM_ZION_CVM_H

#include <sys/ioctl.h>

#include "exec/hwaddr.h"

#define ZION_CVM_KVM_TYPE 1
#define ZION_CVM_KERNEL_LOAD_ADDR 0x80200000ULL

#define TVMIO 0xCC
#define CVM_LOAD_MEM _IO(TVMIO, 0x03)

struct cvm_load_mem_para {
    unsigned long stash;
    unsigned long pos;
    unsigned long size;
};

void zion_cvm_enable(void);
bool zion_cvm_is_enabled(void);
void zion_cvm_set_memory_region(hwaddr addr, uint64_t size);
bool zion_cvm_memory_contains(hwaddr addr, hwaddr len);
int zion_cvm_load_memory(hwaddr addr, const void *buf, hwaddr len);

#endif /* SYSTEM_ZION_CVM_H */
