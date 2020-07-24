CC = gcc
CPPFLAGS = -I../../common/include
CFLAGS = -Wall -Wextra
LDFLAGS =
LDLIBS =

.PHONY: all clean

all: elfsamp readsec

elfsamp: elfsamp.o main.o

readsec: readsec.o

test_elfsamp: elfsamp
	./elfsamp

test_readsec: elfsamp readsec
	./readsec elfsamp.o
	./readsec main.o
	./readsec elfsamp

clean:
	rm -f *.o elfsamp readsec
