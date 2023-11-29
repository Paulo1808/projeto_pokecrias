all: principal.o
	gcc principal.o -o main

principal.o: *.c
	gcc *.c -o principal.o

clean:
	rm -f *.o main

run:
	./all