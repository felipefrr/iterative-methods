all:
	gcc matrix.c gausseidel.c main.c -o main -lm

run:
	./main
