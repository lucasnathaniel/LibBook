PROG = LibBook
CC = g++

CPPFLAGS = -O0 -g -Wall -pedantic -std=c++11

OBJS = main.o Livro.o Lista.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : ../src/main.cpp ../src/main.h
	$(CC) $(CPPFLAGS) -c ../src/main.cpp

Livro.o : ../src/Livro.cpp ../src/Livro.h
	$(CC) $(CPPFLAGS) -c ../src/Livro.cpp

Lista.o : ../src/Lista.cpp ../src/Lista.h
	$(CC) $(CPPFLAGS) -c ../src/Lista.cpp

clean:
	rm -f core $(PROG) $(OBJS)
