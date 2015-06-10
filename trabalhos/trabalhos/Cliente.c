#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Criação de uma estrutura cli, onde possui o CRM, o nome e a especialização
struct cli
{
	int CRM;
	char *nome;
	char *esp;
};

// Criação da estrutura cliente, onde possui um ponteiro do tipo cli e um ponteiro do tipo cliente
struct cliente
{
	struct cli* info;
	struct cliente* next;
};

// Criação do tipo cliente;
typedef struct cliente Cliente;

// Procedimento que inicializa a lista de Clientes
void inicializaCliente(Cliente** l)
{
	*l = NULL;
}

// Função que retorna 1 caso lista esteja vazia, e 0 caso não esteja
int estaVazia(Cliente** l)
{
	return (*l == NULL);
}

void ClearScreen()
{
	int n;
	for (n = 0; n < 50; n++)
		printf("\n");
}

void inserirCliente(Cliente** l)
{
	Cliente* novo;
	novo = (Cliente*)malloc(sizeof(Cliente));
	if (novo != NULL)
	{
		int crm = 0;
		char *nomes, *espe;
		printf("Digite o CRM: ");
		fflush(stdin);
		scanf("%d", &crm);
		novo->info->CRM = crm;
		printf("Digite o nome do cliente: ");
		fflush(stdin);
		scanf(" %[^\n]", nomes);
		novo->info->nome = malloc(sizeof(novo->info->nome));
		novo->info->nome = nomes;
		printf("%s\n", novo->info->nome);

		printf("Digite a especializacao do cliente: ");
		fflush(stdin);
		scanf(" %[^\n]", nomes);
		novo->info->esp = malloc(sizeof(novo->info->esp));
		novo->info->esp = nomes;
		printf("%s\n", novo->info->esp);

		*l = novo;
	}
	else
	{
		printf("Nao foi possivel inserir elemento pois esta %d %s\n", novo, novo);
	}
}

