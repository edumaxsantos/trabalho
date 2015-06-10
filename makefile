all: compila
compila: main.o Cliente.o Representante.o
	gcc main.o Cliente.o Representante.o -o prog
	
main.o: main.c
	gcc -c main.c
Aluno.o: Cliente.c
	gcc -c Cliente.c
Representante.o: Representante.c
	gcc -c Representante.c

clean:
	del main.o Cliente.o Representante.o prog.exe