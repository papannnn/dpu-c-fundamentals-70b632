#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include "regblock.h"
#include "bits.h"

#define STATUS_LINK_UP 1u

int main(void) {
    // Here the "registers" are a plain struct in RAM; on hardware a pointer of
    // this type would aim at the device's MMIO base — same field access.
    DpuRegs regs = { .id = 0xD9U, .status = 0u, .control = 0u, .throughput = 0u };

    regs.control = bit_set(regs.control, 0);        // enable
    regs.status  = bit_set(regs.status, STATUS_LINK_UP);

    printf("id=0x%X control=0x%X link_up=%d\n",
           regs.id, regs.control, bit_test(regs.status, STATUS_LINK_UP));
    printf("sizeof(DpuRegs) = %u bytes\n", (unsigned)sizeof(DpuRegs));
    printf("offset of throughput = %u\n", (unsigned)offsetof(DpuRegs, throughput));
    return 0;
}
