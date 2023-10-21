CC=gcc
CFLAGS = -Wall -O2

TARGET = brainfuck

.PHONY: all clean test

all: $(TARGET)

$(TARGET): main.o memory.o memory_collection.o stack.o engine.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o memory.o memory_collection.o stack.o engine.o

test: test_memory test_memory_collection test_engine test_stack
	./test_memory
	./test_memory_collection
	./test_engine
	./test_stack

test_memory: memory.o memory_test.o
	$(CC) $(CFLAGS) -o test_memory memory_test.o memory.o

test_memory_collection: memory.o memory_collection.o memory_collection_test.o
	$(CC) $(CFLAGS) -o test_memory_collection memory_collection_test.o memory.o memory_collection.o

test_engine: memory.o memory_collection.o engine.o engine_test.o stack.o
	$(CC) $(CFLAGS) -o test_engine engine_test.o engine.o memory.o memory_collection.o stack.o

test_stack: stack.o stack_test.o
	$(CC) $(CFLAGS) -o test_stack stack.o stack_test.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

memory.o: memory.c
	$(CC) $(CFLAGS) -c memory.c

engine.o: engine.c
	$(CC) $(CFLAGS) -c engine.c

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

memory_test.o: tests/memory_test.c memory.h
	$(CC) $(CFLAGS) -c tests/memory_test.c

memory_collection_test.o: tests/memory_collection_test.c
	$(CC) $(CFLAGS) -c tests/memory_collection_test.c

engine_test.o: tests/engine_test.c
	$(CC) $(CFLAGS) -c tests/engine_test.c

stack_test.o: tests/stack_test.c
	$(CC) $(CFLAGS) -c tests/stack_test.c

clean:
	rm -f *.o $(TARGET) test_*
