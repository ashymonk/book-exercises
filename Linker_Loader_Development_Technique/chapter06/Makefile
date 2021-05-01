CC = gcc
CPPFLAGS += -I../common/include
CFLAGS += -Wall -Wextra -g
LDFLAGS +=
LDLIBS +=
TARGET = errwrite overwrite addr conflict valiable fill lma

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f *.o core* $(TARGET)

errwrite: overwrite.o
	$(CC) $(CFLAGS) $^ -o $@

overwrite: overwrite.o
	$(CC) $(CFLAGS) $^ -o $@ -T sample.x

addr: addr.o
	$(CC) $(CFLAGS) $^ -o $@ -T addr.x

conflict: conflict.o
	$(CC) $(CFLAGS) $^ -o $@ -T conflict.x

valiable: valiable.o
	$(CC) $(CFLAGS) $^ -o $@ -T valiable.x

lma: addr.o
	$(CC) $(CFLAGS) $^ -o $@ -T lma.x

fill: fill.o
	$(CC) $(CFLAGS) $^ -o $@ -T fill.x

test: test_errwrite  test_overwrite test_addr test_conflict test_valiable test_fill test_lma

test_errwrite: errwrite
	-./$<

test_overwrite: overwrite
	./$<

test_addr: addr
	./$<
	nm -n $< | grep -e ' s'  -e ' e' -e ' value'

test_conflict: conflict
	./$<
	objdump  -h -j '.text' -j '.data' $<

test_valiable: valiable
	./$<
	objdump  -h -j '.data' $<

test_fill: fill
	./$<
	objdump  -h -j '.data' $<

test_lma: lma
	./$<
	objdump -p lma
