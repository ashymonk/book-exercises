CC = gcc
CPPFLAGS = -I../common/include
CFLAGS = -Wall -Wextra
LDFLAGS =
LDLIBS =
TARGET = const noconst const_b layer layer2_local edata initialize ctors constructor

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

layer: layer.o layer2.o layer_sub1.o layer_sub2.o
	gcc $(CPPFLAGS) $(CFLAGS) layer.o layer_sub?.o -o $@
	nm layer_sub1.o
	nm layer_sub2.o
	ld -r layer_sub1.o layer_sub2.o -o layer_lib.o
	nm layer_lib.o
	objcopy --localize-symbol=num layer_lib.o layer_lib_local.o
	nm layer_lib_local.o
	-gcc $(CPPFLAGS) $(CFLAGS) layer.o layer_lib_local.o -o $@_local
	gcc $(CPPFLAGS) $(CFLAGS) layer2.o layer_lib_local.o -o $@2_local

edata: edata.o
	gcc $(CPPFLAGS) $(CFLAGS) $^ -o $@ -T elf_x86_64.xdwe.sdata

initialize: initialize.o
	gcc $(CPPFLAGS) $(CFLAGS) $^ -o $@ -T elf_x86_64.xdwe.sdata

ctors: ctors.o

constructor: constructor.o

test: test_const test_noconst test_to_static test_const_b test_layer test_edata test_initialize test_ctors test_constructor

test_const: const
	-./const

test_noconst: noconst
	-diff -u elf_x86_64.xdwe elf_x86_64.xdwe.noconst
	./noconst

test_to_static: const_local

test_const_b: const_b
	./const_b

test_layer: layer
	./layer
	./layer2_local

test_edata: edata
	./edata
	objdump -h edata

test_initialize: initialize
	./initialize

test_ctors: ctors
	./ctors

test_constructor: constructor
	./constructor
