CC = g++

CompileParms = -c -Wall

OBJS = element.o binaryheap.o main.o

Opdr: $(OBJS)
	$(CC) $(OBJS) -o opdracht

element.o: element.cc element.h
	$(CC) $(CompileParms)  element.cc

binaryheap.o: binaryheap.cc binaryheap.h
	$(CC) $(CompileParms)  binaryheap.cc


main.o: main.cc element.h
	$(CC) $(CompileParms) main.cc