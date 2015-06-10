// AUTORES: SÁVIO CUNHA DE SOUZA - 2011204405
//          EDUARDO MAXIMINIANO CARDOSO SANTOS - 2014204356
// 1° trabalho de Estrutura de Dados 1

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Representante.h"

// Gera um menu e chama uma função de acordo com a opção selecionada.
void menu(Cliente* clie, Representante* rep)
{
	int op = 0;
	do
	{
		system("cls");
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
		//printf("opcao = %d\n", op);
		switch(op)
		{
			case 1 :
				pegaInfoCli(&clie, op);
			break;
			
			case 2 :
				pegaInfoCli(&clie, op);
			break;
			case 3 :
				imprimirCli(&clie);
			break;
			case 4 :
				pegaInfoRep(&rep, op);
			break;
			case 5 :
				pegaInfoRep(&rep, op);
			break;
			case 6 :
				//printf("caso 6\n");
				imprimirRep(&rep);
			break;
			case 7 :
				printf("Finalizando...");
				liberaListaCli(&clie);
				liberaListaRep(&rep);
				exit(0);
			break;
			
			default:
				printf("Opcao invalida!");
		}
	}while (op != 7);
}

int main()
{
	Cliente *lisCli;
	Representante *lisRep;
	inicializaCli(&lisCli);
	inicializaRep(&lisRep);
	printf(" Esta vazio? %s\n", (estaVazioCli(&lisCli) ? "Sim" : "Nao"));
	printf(" Esta vazio? %s\n", (estaVazioRep(&lisRep) ? "Sim" : "Nao"));
	menu(lisCli, lisRep);
	
	return 0;
}