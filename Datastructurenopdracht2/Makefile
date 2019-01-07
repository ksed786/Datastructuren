CC = g++

CompileParms = -c -Wall

Opdracht2: opdracht2.o tree.o node.o token.o
    	c++ opdracht2.o tree.o node.o token.o -o Opdracht2

opdracht2.o: opdracht2.cc
			c++ -c opdracht2.cc -o opdracht2.o

tree.o: tree.cc tree.h
			c++ -c tree.cc -o tree.o

node.o: node.cc node.h
			c++ -c node.cc -o node.o

token.o: token.cc token.h
			c++ -c token.cc -o token.o
