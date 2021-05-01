CC = gcc
CPPFLAGS = -I../common/include
CFLAGS = -Wall -Wextra
LDFLAGS =
LDLIBS =
TARGET = readname ardump samp_obj samp2_obj samp_ar samp2_ar libsamp.a

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f *.o file*.txt *.a $(TARGET)

readname: readname.o

ardump: ardump.o

samp_obj: main.o samp1.o samp2.o samp3.o samp4.o
	$(CC) $^ -o $@

samp2_obj: main.o samp1.o samp2d.o samp3.o samp4.o
	$(CC) $^ -o $@

libsamp.a: main.o samp1.o samp2.o samp3.o samp4.o
	ar rUc $@ $^

samp_ar: main.o libsamp.a
	$(CC) $< -L. -lsamp -o $@

samp2_ar: main.o libsamp.a samp2d.o
	mv samp2d.o samp2.o
	ar rUc libsamp.a samp2.o
	$(CC) $< -L. -lsamp -o $@

test: test_readname test_ardump test_link

test_readname: readname
	echo ABCD   > file15xxxxx.txt
	echo ABCDE  > file16xxxxxx.txt
	echo ABCDEF > file17xxxxxxx.txt
	ar rUc gnuar.a file*.txt
	cat gnuar.a
	./readname gnuar.a

test_ardump: ardump
	./ardump ardump.o

test_link: samp_obj samp_ar samp2_obj samp2_ar ardump
	./ardump samp_obj | grep samp
	./ardump samp_ar | grep samp
	./ardump samp2_obj | grep samp
	./ardump samp2_ar | grep samp
