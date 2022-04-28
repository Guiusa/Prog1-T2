FLAG = -g -Wall -std=c90
pilha=testa_pilha
lista=testa_lista
fila=testa_fila

all:
	gcc $(FLAG) -c libraries/libpilha.c
	gcc $(FLAG) -c testa_pilha.c
	gcc testa_pilha.o libpilha.o -o testa_pilha
	gcc $(FLAG) -c libraries/libfila.c
	gcc $(FLAG) -c testa_fila.c
	gcc testa_fila.o libfila.o -o testa_fila
	gcc $(FLAG) -c libraries/liblista.c
	gcc $(FLAG) -c testa_lista.c
	gcc testa_lista.o liblista.o -o testa_lista

clean:
	rm -f *.o *.gch $(pilha) $(fila) $(lista)

