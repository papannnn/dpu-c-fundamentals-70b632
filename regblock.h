#ifndef REGBLOCK_H
#define REGBLOCK_H

#include <stdint.h>

// A device exposes a contiguous BLOCK of registers. A struct lets us name each
// one and access it as `blk->status` instead of `*(base + 2)`. The field ORDER
// and sizes must match the hardware's memory layout exactly.
typedef struct DpuRegs {
    uint32_t id;          // +0x00: read-only device id
    uint32_t status;      // +0x04: status bits
    uint32_t control;     // +0x08: control bits
    uint32_t throughput;  // +0x0C: packets/sec counter
} DpuRegs;

#endif // REGBLOCK_H
