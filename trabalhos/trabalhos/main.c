// trabalhos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Representante.h"


void menu(Cliente* clie)
{
	int op = 0;
	do
	{
		fflush(stdout);
		printf("----------------MENU------------------\n");
		printf("1 - Cadastrar novo cliente\n");
		printf("2 - Remover cliente\n");
		printf("3 - Imprimir clientes\n");
		printf("4 - Cadastrar novo representante\n");
		printf("5 - Remover representante\n");
		printf("6 - Imprimir representante\n");
		printf("7 - Sair\n");
		printf("Escolha uma opcao:\n");
		printf("--------------------------------------\n");
		scanf("%i", &op);
		printf("opcao = %d\n", op);
		switch (op)
		{
		case 1:
			printf("chegou\n");
			inserirCliente(&clie);
			printf("fail aqui?\n");
			break;

		case 2:
			printf("caso 2\n");
			//removeCliente();
			break;
		case 3:
			printf("caso 3\n");
			//imprimeCliente();
			break;
		case 4:
			printf("caso 4\n");
			//cadastrarRepresentante();
			break;
		case 5:
			printf("caso 5\n");
			//removerRepresentante();
			break;
		case 6:
			printf("caso 6\n");
			//imprimirRepresentante();
			break;

		case 7:
			printf("Finalizando...");
			exit(0);
			break;

		default:
			printf("Opcao invalida!");
		}
		printf("ou foi aqui?\n");

		printf("mas nao aqui\n");
	} while (op != 7);
}

int main()
{
	Cliente* clie;
	Representante* repre;
	inicializaCliente(&clie);
	inicializaRepresentante(&repre);
	inserirCliente(&clie);
	inserirCliente(&clie);
	inserirCliente(&clie);
	inserirCliente(&clie);
	return 0;
}

