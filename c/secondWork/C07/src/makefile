HEADERS = ../../../MyLibrary/customSorts.c

default: exercise07

exercise07.o: exercise07.c $(HEADERS)
	gcc -c exercise07.c -o exercise07.o

exercise07: exercise07.o
	gcc exercise07.o -o exercise07

clean:
	-rm -f exercise07.o
	-rm -f exercise07