#makefile

all:	HashCode	Clean

Main.o:	Main.c Practice.h	
	gcc -Wall -pedantic -ansi -g -c Main.c

Files.o:	Files.c	Practice.h
	gcc -Wall -pedantic -ansi -g -c Files.c

HashCode:	Main.o	Files.o
	gcc Main.o Files.o -o HashCode

Clean:
	rm Main.o Files.o