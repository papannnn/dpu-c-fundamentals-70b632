#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

// A fixed table mapping register index -> human name. An array is a contiguous
// run of same-typed elements; indexing is just pointer arithmetic underneath.
static const char *REG_NAMES[] = {
    "ID",          // index 0
    "STATUS",      // index 1
    "CONTROL",     // index 2
    "THROUGHPUT",  // index 3
};

#define N_REGS (sizeof(REG_NAMES) / sizeof(REG_NAMES[0]))

// Return the name for a register index, or "?" if out of range. The bounds
// check is what stands between us and reading past the array.
const char *reg_name(size_t idx) {
    if (idx >= N_REGS) {
        return "?";            // out of range — never index past the end
    }
    return REG_NAMES[idx];
}

int main(void) {
    for (size_t i = 0; i < N_REGS; i++) {
        printf("reg[%zu] = %s\n", i, reg_name(i));
    }
    printf("reg[99]  = %s\n", reg_name(99));   // safely handled
    return 0;
}
