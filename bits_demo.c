#include <stdint.h>
#include <stdio.h>
#include "bits.h"

// Named bit positions in a fictional CONTROL register.
#define CTRL_ENABLE   0u
#define CTRL_RESET    3u
#define CTRL_IRQ_EN   7u

int main(void) {
    uint32_t ctrl = 0u;

    ctrl = bit_set(ctrl, CTRL_ENABLE);     // power the block on
    ctrl = bit_set(ctrl, CTRL_IRQ_EN);     // enable its interrupt
    printf("after enable+irq: 0x%08X\n", ctrl);

    if (bit_test(ctrl, CTRL_ENABLE)) {
        printf("block is enabled\n");
    }

    ctrl = bit_clear(ctrl, CTRL_IRQ_EN);   // mask the interrupt again
    printf("after clearing irq: 0x%08X\n", ctrl);
    return 0;
}
