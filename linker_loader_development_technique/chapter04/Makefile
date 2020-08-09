CC = gcc
CPPFLAGS = -I../common/include
CFLAGS = -Wall -Wextra
LDFLAGS =
LDLIBS =
TARGET = const noconst const_b

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f *.o $(TARGET)

const: const.o const_sub.o
	gcc $(CPPFLAGS) $(CFLAGS) $^ -o $@ -T elf_x86_64.xdwe

noconst: const.o const_sub.o
	gcc $(CPPFLAGS) $(CFLAGS) $^ -o $@ -T elf_x86_64.xdwe.noconst

const_local: const.o const_sub.o
	nm const_sub.o
	objcopy --localize-symbol=a const_sub.o const_sub_local.o
	nm const_sub_local.o
	-gcc $(CPPFLAGS) $(CFLAGS) const.o const_sub_local.o -o $@

const_b: const_b.o const_sub.o
	-gcc $(CPPFLAGS) $(CFLAGS) $^ -o $@
	objcopy --redefine-sym a=b const_sub.o const_sub_b.o
	nm const_sub_b.o
	gcc $(CPPFLAGS) $(CFLAGS) const_b.o const_sub_b.o -o $@

test: test_const test_noconst test_to_static test_const_b

test_const: const
	-./const

test_noconst: noconst
	-diff -u elf_x86_64.xdwe elf_x86_64.xdwe.noconst
	./noconst

test_to_static: const_local

test_const_b: const_b
	./const_b
