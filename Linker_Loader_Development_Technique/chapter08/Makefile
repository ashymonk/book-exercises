CC = gcc
CPPFLAGS += -I../common/include
CFLAGS += -Wall -Wextra -g
LDFLAGS += -L.
LDLIBS +=
TARGET = chflg stack_sample.s loader sample

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f *.o *.a *.dat core* $(TARGET)

chflg: chflg.o

stack_sample.s: stack_sample.c
	$(CC) -S $^

sample: sample.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $^ -o $@ -static

loader: loader.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $^ -o $@ -T static_space.ld -static

test: test_chflg test_stack_sample test_sample test_loader

test_chflg: chflg
	cp chflg chflg_tmp
	readelf -l chflg_tmp
	./chflg chflg_tmp
	readelf -l chflg_tmp
	rm chflg_tmp

test_stack_sample: stack_sample.s
	view stack_sample.c stack_sample.s

test_sample: sample
	./sample abc def ghi

test_loader: chflg sample loader
	./chflg loader
	./loader sample abc def ghi
