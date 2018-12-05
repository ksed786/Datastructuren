CC = g++

CompileParms = -c -Wall

OBJS = standaard.o steen.o stand.o opdracht2.o

Opdr: $(OBJS)
	$(CC) $(OBJS) -o opdracht

standaard.o: tree.cc tree.h
	$(CC) $(CompileParms)  tree.cc

steen.o: node.cc node.h
	$(CC) $(CompileParms)  node.cc

stand.o: token.cc token.h
	$(CC) $(CompileParms) token.cc

opdracht2.o: opdracht2.cc tree.h
	$(CC) $(CompileParms)  opdracht2.cc