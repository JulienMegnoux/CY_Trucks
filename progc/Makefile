
CC = gcc

all: my_programs my_programt

main.o: CY_Trucks/progc/Traitement_s/main.c 
	$(CC) -c $< -o $@

AVLs.o: CY_Trucks/progc/Traitement_s/AVLs.c CY_Trucks/progc/Traitement_s/AVLs.h
	$(CC) -c $< -o $@

test.o: CY_Trucks/progc/Traitement_t/test.c
	$(CC) -c $< -o $@

my_programs: main.o AVLs.o
	$(CC) $^ -o $@

my_programt: test.o 
	$(CC) $^ -o $@

clean:
	rm -f *.o
	rm -f my_programs
	rm -f my_programt
