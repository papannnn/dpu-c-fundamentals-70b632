#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

// HAZARD 1: dereferencing NULL. NULL is "points at nothing" (address 0).
uint32_t bad_null(void) {
    uint32_t *p = NULL;
    return *p;             // UB: there is no value at address 0
}

// HAZARD 2: returning a pointer to a local. `tmp` lives on the stack and is
// gone the instant this function returns — the pointer dangles.
uint32_t *bad_dangling(void) {
    uint32_t tmp = 0xDEAD;
    return &tmp;           // UB: &tmp is invalid after we return
}

// HAZARD 3: reading uninitialized memory. `x` holds whatever garbage was on
// the stack before — not a defined value.
uint32_t bad_uninit(void) {
    uint32_t x;
    return x;              // UB: x was never given a value
}

int main(void) {
    // The CORRECT way: point at real, live storage and check before use.
    uint32_t value = 0;
    uint32_t *p = &value;
    if (p != NULL) {
        *p = 42;
        printf("safe read: %u\n", *p);
    }
    return 0;
}
