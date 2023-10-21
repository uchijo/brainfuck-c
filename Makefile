CC=gcc
CFLAGS = -Wall -O2

TARGET = brainfuck

.PHONY: all clean test

all: $(TARGET)

$(TARGET): main.o memory.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

test: test_memory test_memory_collection
	./test_memory
	./test_memory_collection

test_memory: memory.o memory_test.o
	$(CC) $(CFLAGS) -o test_memory memory_test.o memory.o

test_memory_collection: memory.o memory_collection.o memory_collection_test.o
	$(CC) $(CFLAGS) -o test_memory_collection memory_collection_test.o memory.o memory_collection.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

memory.o: memory.c
	$(CC) $(CFLAGS) -c memory.c

memory_test.o: tests/memory_test.c memory.h
	$(CC) $(CFLAGS) -c tests/memory_test.c

memory_collection_test.o: tests/memory_collection_test.c
	$(CC) $(CFLAGS) -c tests/memory_collection_test.c

clean:
	rm -f *.o $(TARGET) test_*
