#include <stdint.h>
#include <stdio.h>
#include "decode.h"

int main(void) {
    uint32_t s = DPU_LINK_UP | DPU_FAULT;   // link up, but faulted
    printf("status = 0x%08X\n", s);
    printf("flags set:\n");
    decode_status(s);
    printf("healthy? %s\n", status_is_healthy(s) ? "yes" : "no");
    return 0;
}
