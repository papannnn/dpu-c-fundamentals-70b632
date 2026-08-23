#include <stdio.h>
#include "decode.h"

// PRIVATE implementation. Callers include decode.h and never see this file's
// internals — they rely only on the contract the header declares.
void decode_status(uint32_t status) {
    if (status & DPU_LINK_UP)  printf("  LINK_UP\n");
    if (status & DPU_FAULT)    printf("  FAULT\n");
    if (status & DPU_OVERHEAT) printf("  OVERHEAT\n");
}

int status_is_healthy(uint32_t status) {
    // Healthy = link up AND no fault AND not overheating.
    if (!(status & DPU_LINK_UP)) return 0;
    if (status & DPU_FAULT)      return 0;
    if (status & DPU_OVERHEAT)   return 0;
    return 1;
}
