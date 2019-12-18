CC=gcc

CFLAGS=-c -Wall

all: main

main: main.o filter.o imagem.o
	$(CC) main.o filter.o imagem.o -o main

main.o: main.c
	$(CC) $(CFLAGS) main.c

filter.o: filter.c
	$(CC) $(CFLAGS) filter.c

imagem.o: imagem.c
	$(CC) $(CFLAGS) imagem.c

clean:
	rm *.o main
