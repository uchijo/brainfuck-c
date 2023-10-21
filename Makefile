CC=gcc
CFLAGS = -Wall -O2

TARGET = brainfuck

all: $(TARGET)

$(TARGET): main.o memory.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

test: memory.o memory_test.o
	$(CC) $(CFLAGS) -o test_memory memory_test.o memory.o
	./test_memory

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

memory.o: memory.c
	$(CC) $(CFLAGS) -c memory.c

memory_test.o: tests/memory_test.c memory.h
	$(CC) $(CFLAGS) -c tests/memory_test.c

clean:
	rm -f *.o $(TARGET) test_memory
