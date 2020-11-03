CC = gcc
CPPFLAGS += -I../common/include
CFLAGS += -Wall -Wextra -g
LDFLAGS += -L.
LDLIBS +=
TARGET = normal normal_a reverse reverse_a collect_a collect2_a duplicate duplicate_a group_a duplicate1 duplicate2 duplicate3 duplicate4 binary binary3

.PHONY: all clean

all: $(TARGET)

clean:
	rm -f *.o *.a *.dat core* $(TARGET)

normal: ordermain.o order1.o order2.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

normal_a:  ordermain.o liborder1.a liborder2.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(patsubst lib%.a,-l%,$^) -o $@

reverse: ordermain.o order2.o order1.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

reverse_a:  ordermain.o liborder2.a liborder1.a
	-$(CC) $(CFLAGS) $(LDFLAGS) $(patsubst lib%.a,-l%,$^) -o $@

collect_a:  ordermain.o libcollect.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(patsubst lib%.a,-l%,$^) -o $@

collect2_a:  ordermain.o libcollect2.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(patsubst lib%.a,-l%,$^) -o $@

duplicate: ordermain.o order2.o order1.o order2.o
	-$(CC) $(CFLAGS) $(LDFLAGS) $+ -o $@

duplicate_a:  ordermain.o liborder2.a liborder1.a liborder2.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(patsubst lib%.a,-l%,$+) -o $@

group_a:  ordermain.o liborder2.a liborder1.a
	-$(CC) $(CFLAGS) $(LDFLAGS) ordermain.o -Wl,--start-group -lorder2 -lorder1 -Wl,--end-group -o $@

duplicate1: dupmain.o libduptest1.a libduptest2.a libdup.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(patsubst lib%.a,-l%,$^) -o $@

duplicate2: dupmain.o libduptest1.a libdup1.a libduptest2.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(patsubst lib%.a,-l%,$^) -o $@

duplicate3: dupmain.o libduptest1.a libdup1.a libduptest2.a libdup2.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(patsubst lib%.a,-l%,$^) -o $@

duplicate4: dupmain.o libduptest1.a libdup2.a libdup1.a libduptest2.a
	$(CC) $(CFLAGS) $(LDFLAGS) $(patsubst lib%.a,-l%,$^) -o $@

binary: binary_tmp.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	nm $@ | grep bindata
	objdump -h -j bindata $@

binary3: binary_tmp3.o binary.o
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	nm $@ | grep bindata
	objdump -h -j .bindata $@

liborder1.a: order1.o
	ar rUc $@ $^

liborder2.a: order2.o
	ar rUc $@ $^

libcollect.a: order1.o order2.o
	ar rUc $@ $^
	ar t $@

libcollect2.a: order2.o order1.o
	ar rUc $@ $^
	ar t $@

libduptest1.a: duptest1.o
	ar rUc $@ $^

libduptest2.a: duptest2.o
	ar rUc $@ $^

libdup1.a: dup1.o
	ar rUc $@ $^

libdup2.a: dup2.o
	ar rUc $@ $^

libdup.a: dup1.o dup2.o
	ar rUc $@ $^

binary_tmp.o: binary.o
	echo "This is test." >binary.dat
	objcopy --add-section=bindata=binary.dat \
		--set-section-flags=bindata=contents,alloc,load,readonly,data \
		$< $@

binary_tmp3.o:
	echo "This is test." >binary.dat
	ld -r --format binary --oformat elf64-x86-64 binary.dat -o binary_tmp2.o
	ld -r -T bindata.scr binary_tmp2.o -o $@

test: test_normal test_reverse test_collect test_duplicate test_group test_duplicate1 test_binary test_binary3

test_normal: normal normal_a
	-./$(word 1,$^)
	-./$(word 2,$^)

test_reverse: reverse reverse_a
	-./$<

test_collect: collect_a collect2_a
	-./$(word 1,$^)
	-./$(word 2,$^)

test_duplicate: duplicate duplicate_a
	-./$(word 2,$^)

test_group: group_a
	-./$<

test_duplicate1: duplicate1 duplicate2 duplicate3 duplicate4
	-./$(word 1,$^)
	-./$(word 2,$^)
	-./$(word 3,$^)
	-./$(word 4,$^)

test_binary: binary
	-./$<

test_binary3: binary3
	-./$<
