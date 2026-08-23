#ifndef DECODE_H
#define DECODE_H

#include <stdint.h>

// PUBLIC interface of the decode module: what callers may use. The header is a
// CONTRACT — it promises these functions exist with these signatures.

#define DPU_LINK_UP   (1u << 1)
#define DPU_FAULT     (1u << 5)
#define DPU_OVERHEAT  (1u << 8)

// Print each set flag in `status` by name to stdout.
void decode_status(uint32_t status);

// Return 1 if the status indicates a healthy link with no faults, else 0.
int status_is_healthy(uint32_t status);

#endif // DECODE_H
