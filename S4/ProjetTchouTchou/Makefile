#Variables personnalisées
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=main

#Fichier qui regroupe l'ensemble des exécutables
all: $(EXEC)

main: main.o menu.o id.o reseau.o
	$(CC) -o main main.o menu.o id.o reseau.o $(LDFLAGS)

main.o: source/main.c
	$(CC) -o main.o -c source/main.c $(CFLAGS)

menu.o: source/menu.c
	$(CC) -o menu.o -c source/menu.c $(CFLAGS)

reseau.o: source/reseau.c
	$(CC) -o reseau.o -c source/reseau.c $(CFLAGS)

id.o: source/id.c
	$(CC) -o id.o -c source/id.c $(CFLAGS)

menu.c: headers/menu.h 

id.c: headers/id.h

reseau.c: headers/reseau.h

#Supprime les fichiers intermédiaires
clean:
	rm -rf *.o

#Supprime tout ce qui peut être regénéré et permet donc une reconstruction complète du projet
mrproper: clean
	rm -rf $(EXEC)
