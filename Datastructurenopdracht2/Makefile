CC = g++

CompileParms = -c -Wall

OBJS = node.o token.o tree.o opdracht2.o

Opdr: $(OBJS)
	$(CC) $(OBJS) -o opdracht

node.o: node.cc node.h
	$(CC) $(CompileParms)  node.cc

token.o: token.cc token.h
	$(CC) $(CompileParms) token.cc

tree.o: tree.cc tree.h
	$(CC) $(CompileParms)  tree.cc

opdracht2.o: opdracht2.cc
	$(CC) $(CompileParms)  opdracht2.cc