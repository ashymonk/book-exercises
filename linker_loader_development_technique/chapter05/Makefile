CC = gcc
CPPFLAGS += -I../common/include
CFLAGS += -Wall -Wextra
LDFLAGS +=
LDLIBS +=
TARGET = linksamp otherscr

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f *.o $(TARGET)

linksamp: main.o lib1.o lib2.o
	$(CC) $(CFLAGS) $^ -o $@

otherscr: main.o lib1.o lib2.o
	$(CC) $(CFLAGS) $^ -o $@ -T sample.x

test: test_linksamp test_otherscr

test_linksamp: linksamp
	./linksamp
	objdump -h -p main.o
	objdump -h -p lib1.o
	objdump -h -p lib2.o
	objdump -h -p linksamp

test_otherscr: otherscr
	./otherscr
	objdump -h -p otherscr
	readelf -x 7 otherscr
