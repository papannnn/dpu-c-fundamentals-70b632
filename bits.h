#ifndef BITS_H
#define BITS_H

#include <stdint.h>

// A register is a row of named bits. These helpers are the vocabulary every
// driver speaks: set, clear, toggle, and test a single bit by position.
static inline uint32_t bit_set(uint32_t v, unsigned pos)    { return v |  (1u << pos); }
static inline uint32_t bit_clear(uint32_t v, unsigned pos)  { return v & ~(1u << pos); }
static inline uint32_t bit_toggle(uint32_t v, unsigned pos) { return v ^  (1u << pos); }
static inline int      bit_test(uint32_t v, unsigned pos)   { return (v >> pos) & 1u; }

#endif // BITS_H
