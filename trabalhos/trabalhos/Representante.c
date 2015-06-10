#include <stdio.h>
#include <stdlib.h>

// Criação de uma estrutura rep, onde possui o ID, o nome e a especialização
struct rep
{
	int ID;
	char* nome;
	char* esp;
};

// Criação da estrutura representante, onde possui um ponteiro do tipo rep e um ponteiro do tipo representante
struct representante
{
	struct rep* info;
	struct representante* next;
};

// Criação do tipo representante;
typedef struct representante Representante;

void inicializaRepresentante(Representante** l)
{
	*l = NULL;
}