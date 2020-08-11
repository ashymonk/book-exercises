CC = gcc
CPPFLAGS = -I../common/include
CFLAGS = -Wall -Wextra
LDFLAGS =
LDLIBS =
TARGET = elfsamp readsec elfread elfdump

.PHONY: all clean

all: $(TARGET)

elfsamp: elfsamp.o main.o

readsec: readsec.o

elfread: elfread.o

elfdump: elfdump.o

test: test_elfsamp test_readsec test_elfread test_elfdump

test_elfsamp: elfsamp
	./elfsamp

test_readsec: elfsamp readsec
	./readsec elfsamp.o
	./readsec main.o
	./readsec elfsamp

test_elfread: elfread
	sudo sysctl kernel.randomize_va_space=0
	./elfread
	sudo sysctl kernel.randomize_va_space=2

test_elfdump: elfdump
	./elfdump elfsamp.o
	./elfdump elfsamp

clean:
	rm -f *.o $(TARGET)
