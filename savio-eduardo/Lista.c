#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "Cliente.h"

typedef struct cliente
{
	int *info;
	struct cliente *next;
} Cliente;


// O t é a opção para onde deve ser jogado as informações
// Se t = 1, inserir Ordenado
// Se t = 2, Remover Cliente
void pegaInfoCli(Cliente **l, int t)
{
	int crm = 0;
	char *nome = malloc(sizeof(char));
	char *espe = malloc(sizeof(char));
	printf("Digite o CRM: ");
	scanf("%d", &crm);
	
	printf("Digite o nome do cliente: ");
	scanf(" %[^\n]s", nome);
	printf("Digite o nome da especificacao do cliente: ");
	fflush(stdin);
	fflush(stdout);
	scanf(" %[^\n]s", espe);
	system("cls");
	nome = strupr(nome);
	espe = strupr(espe);
	if (t == 0)
		inserirOrdenado(l, crm, nome, espe);
	else
		alterar(l, crm, nome, espe);
}

void inicializaCli(Cliente **l)
{
	*l = NULL;
}

int estaVazioCli(Cliente **l)
{
	return (*l == NULL);
}