CC = gcc
# -Wall -Wextra: turn on warnings (your first bug detector).
# -Werror: treat warnings AS errors so they can't be ignored.
# -g: debug symbols. -O0: no optimization, so the debugger sees code as written.
# -std=c11: pin the language standard for reproducibility.
CFLAGS = -Wall -Wextra -Werror -g -O0 -std=c11

# The decode demo links three translation units into one binary.
decode_demo: decode_main.c decode.c decode.h
	$(CC) $(CFLAGS) -o decode_demo decode_main.c decode.c

# The bits and regblock demos are single-file builds.
bits_demo: bits_demo.c bits.h
	$(CC) $(CFLAGS) -o bits_demo bits_demo.c

regblock_demo: regblock_demo.c regblock.h bits.h
	$(CC) $(CFLAGS) -o regblock_demo regblock_demo.c

all: decode_demo bits_demo regblock_demo

clean:
	rm -f decode_demo bits_demo regblock_demo
