#include <stdio.h>
#include <stdlib.h>

// Cria��o de uma estrutura rep, onde possui o ID, o nome e a especializa��o
struct rep
{
	int ID;
	char* nome;
	char* esp;
};

// Cria��o da estrutura representante, onde possui um ponteiro do tipo rep e um ponteiro do tipo representante
struct representante
{
	struct rep* info;
	struct representante* next;
};

// Cria��o do tipo representante;
typedef struct representante Representante;

void inicializaRepresentante(Representante** l)
{
	*l = NULL;
}