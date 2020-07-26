CC = gcc
CPPFLAGS = -I../common/include
CFLAGS = -Wall -Wextra
LDFLAGS =
LDLIBS =
TARGET = readname ardump

.PHONY: all clean

all: $(TARGET)

readname: readname.o

ardump: ardump.o

test: test_readname test_ardump

test_readname: readname
	echo ABCD   > file15xxxxx.txt
	echo ABCDE  > file16xxxxxx.txt
	echo ABCDEF > file17xxxxxxx.txt
	ar rUc gnuar.a file*.txt
	cat gnuar.a
	./readname gnuar.a

test_ardump: ardump
	./ardump ardump.o

clean:
	rm -f *.o file*.txt *.a $(TARGET)
