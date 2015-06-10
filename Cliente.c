#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Criação de uma estrutura cli, onde possui o CRM, o nome e a especialização
typedef struct cli
{
	int CRM;
	char *nome;
	char *esp;
} Cli;

// Criação da estrutura cliente, onde possui um ponteiro do tipo cli e um ponteiro do tipo cliente
typedef struct cliente
{
	Cli *info;
	struct cliente *next;
} Cliente;


// Inicialização da lista de Cliente.
void inicializaCli(Cliente **l)
{
	*l = NULL;
}

//Verifica se a lista está vazia e retorna 1 ou 0.
int estaVazioCli(Cliente **l)
{
	return (*l == NULL);
}

// Função que procura pelo CRM desejado.
int buscaCRM(Cliente **l, int crm)
{
	Cliente *p;

	for (p = *l; p != NULL; p = p->next)
	{
		if (p->info->CRM == crm)
		{
			printf("CRM = %d\n", crm);
			return 1;
		}
	}
	return 0;
}

//Função para salvar o cliente registrado no arquivo clientes.txt
void salvaCliente(Cliente **l)
{
	FILE *arq = fopen("clientes.txt", "a");
	if (arq != NULL)
	{
		Cliente *p;
		p = *l;
		printf("Arquivo aberto com sucesso!\n");
		fprintf(arq, "CRM:%d NOME:%s :%s\n", p->info->CRM, p->info->nome, p->info->esp);
	}
	else
		printf("Erro ao abrir o arquivo\n");
	
	fclose(arq);
}


// Função: Inserir clientes de forma ordenada pelo CRM
// Parâmetros: endereço da lista, número CRM, nome do cliente e especificação do cliente
// Retorno: nenhum retorno
void inserirOrdenadoCli(Cliente **l, int crm, char* nome, char* espe)
{
	// Criação de dois ponteiros para o TAD Cliente, um sendo inicializado em NULL
	Cliente *p, *ant = NULL;
	// Repetição onde p aponta para lista, e continua nesse loop até que P seja NULL ou p->info->CRM >= crm. 
	// Enquanto não parar, p apontará para p->next
	// Dentro da repetição, ant aponta para p
	for (p = *l; p != NULL && p->info->CRM < crm; p = p->next)
		ant = p;
	// Após a repetição, é criado um ponteiro para Cliente com o nome de novo.
	// O ponteiro novo é alocado na memória através de malloc e com o tamanho de Cliente.
	// O ponteiro info que é apontado por novo também é alocado com o tamanho de Cli.
	// os valores recebidos por parâmetros são passados para os componentes de info
	// e o ponteiro next dentro do TAD Cliente aponta para o que p apontava
	Cliente *novo;
	novo = malloc(sizeof(Cliente));
	novo->info = malloc(sizeof(Cli));

	if (!buscaCRM(l, crm))
	{
		novo->info->CRM = crm;
		novo->info->nome = nome;
		novo->info->esp = espe;
		novo->next = p;
		// Condição para verificar se o ponteiro ant continua NULL
		// Caso seja positivo, o conteúdo de l aponta para novo.
		// Caso seja negativo, o ponteiro next dentro de Cliente que é apontado por ant irá apontar para novo.
		if (ant == NULL)
			*l = novo;
		else
			ant->next = novo;
	}
	else
		printf("Ja existe cadastro com esse CRM!\n");
}

//Função para passar o conteúdo do arquivo para a lista
void passarArq(Cliente **l)
{
	FILE *arq = fopen("clientes.txt", "r");
	if (arq != NULL)
	{
		int crm;
		char *nome = malloc(sizeof(char) * 100);
		char *espe = malloc(sizeof(char) * 100);
		do
		{
			inserirOrdenadoCli(l, crm, nome, espe);	
			nome = malloc(sizeof(char) * 100);
			espe = malloc(sizeof(char) * 100);
		}while((fscanf(arq, ":%d :%s :%s\n", &crm, nome, espe)) != EOF);
	}
	fclose(arq);
}


// Remove o cliente após receber o CRM e fazer uma busca por ele.
void removerCli(Cliente **l, int crm)
{
	Cliente *p, *ant = NULL;
	for (p = *l; p != NULL && p->info->CRM != crm; p = p->next)
		ant = p;
	if (p == NULL)
		printf("Valor nao encontrado!\n");
	else
	{
		if (ant == NULL)
			*l = p->next;
		else
			ant->next = p->next;
		free(p);
		printf("Removido com sucesso!\n");
	}
}


void alterarCli(Cliente **l, int crm, char* nome, char* espe)
{
	if (buscaCRM(l, crm))
	{
		Cliente *novo = malloc(sizeof(Cliente));
		novo->info->nome = nome;
		novo->info->esp = espe;
		if (strcmp(novo->info->esp, espe) && strcmp(novo->info->nome, nome))
			printf("Alterado com sucesso!\n");
		else
			printf("Algum erro ocorreu e nao foi possivel alterar Cliente!\n");
	}
	else
		printf("Cliente nao encontrado para alteracao!\n");
}

// O t é a opção para onde deve ser jogado as informações
// Se t = 1, inserir Ordenado
// Se t = 2, Remover Cliente
void pegaInfoCli(Cliente **l, int t)
{
	int crm = 0;
	char *nome = malloc(sizeof(char) * 100);
	char *espe = malloc(sizeof(char) * 100);
	//char *espe;
	printf("Digite o CRM: ");
	scanf("%d", &crm);
	if (t == 2)
	{
		removerCli(l, crm);
		printf("Pressione [ENTER] para continuar\n");
		fflush(stdin);
		getchar();
		return;
	}

	printf("Digite o nome do cliente: ");
	fflush(stdin);
	fflush(stdout);
	scanf(" %[^\n]s", nome);
	nome = strupr(nome);

	printf("Digite o nome da especializacao do cliente: ");
	fflush(stdin);
	fflush(stdout);
	scanf(" %[^\n]", espe);

	espe = strupr(espe);
	if (t == 1)
		inserirOrdenadoCli(l, crm, nome, espe);
	else
		alterarCli(l, crm, nome, espe);
	printf("Pressione [ENTER] para continuar\n");
	fflush(stdin);
	getchar();
}

//Função para imprimir a lista de clientes.
void imprimirCli(Cliente **l)
{
	Cliente *p;
	if (estaVazioCli(l))
	{
		printf("Esta vazia!\n");
	}
	else
	{
		printf("\t\tLista completa de clientes:\n\n");
		for (p = *l; p != NULL; p = p->next)
			printf("CRM: %d\t Nome: %s\t Especializacao: %s\n", p->info->CRM, p->info->nome, p->info->esp);
	}
	printf("Pressione [ENTER] para continuar\n");
	fflush(stdin);
	getchar();

}

//Função para liberar a lista antes de fechar o programa
void liberaListaCli(Cliente **l)
{
	if (!estaVazioCli(l))
	{
		Cliente *p, *temp;
		for (p = *l; p != NULL; p = temp)
		{
			temp = p->next;
			free(p);
		}
		*l = NULL;
	}
	
}

