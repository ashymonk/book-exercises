CC = gcc
CPPFLAGS += -I../common/include
CFLAGS += -Wall -Wextra -g
LDFLAGS +=
LDLIBS +=
TARGET = errwrite overwrite

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f *.o core* $(TARGET)

errwrite: overwrite.o
	$(CC) $(CFLAGS) $^ -o $@

overwrite: overwrite.o
	$(CC) $(CFLAGS) $^ -o $@ -T sample.x

test: test_errwrite  test_overwrite

test_errwrite: errwrite
	-./errwrite

test_overwrite: overwrite
	./overwrite
