#include <stdint.h>
#include <stdio.h>

// On real hardware a "register" is just a fixed-width slot of bits at a known
// address. uint32_t is EXACTLY 32 bits on every platform — we never guess.
uint32_t status_reg = 0x0000002Au;

// Each named bit (a "field") carries one piece of hardware state.
#define LINK_UP_BIT  (1u << 1)
#define FAULT_BIT    (1u << 5)

// Read a register THROUGH a pointer. In a real driver the pointer would aim at
// a hardware address; here it aims at our variable — the mechanics are identical.
uint32_t read_reg(const uint32_t *reg) {
    return *reg;            // dereference: fetch the value the pointer points to
}

// Set the FAULT bit by writing back through the pointer.
void set_fault(uint32_t *reg) {
    *reg = *reg | FAULT_BIT;
}

int main(void) {
    printf("before: 0x%08X\n", read_reg(&status_reg));
    set_fault(&status_reg);
    printf("after:  0x%08X\n", read_reg(&status_reg));
    return 0;
}
