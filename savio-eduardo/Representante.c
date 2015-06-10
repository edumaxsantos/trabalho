#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// Criação de uma estrutura rep, onde possui o ID, o nome e a especialização
typedef struct rep
{
	int ID;
	char* nome;
	char* esp;
} Rep;

// Criação da estrutura representante, onde possui um ponteiro do tipo rep e um ponteiro do tipo representante
typedef struct representante
{
	Rep* info;
	struct representante* next;
} Representante;

// Inicialização da lista de Representante.
void inicializaRep(Representante** l)
{
	*l = NULL;
}

//Verifica se a lista está vazia e retorna 1 ou 0.
int estaVazioRep(Representante **l)
{
	return (*l == NULL);
}



// Função: Inserir representantes de forma ordenada pelo nome
// Parâmetros: endereço da lista, id, nome do representante e especificação do representante
// Retorno: nenhum retorno
void inserirOrdenadoRep(Representante** l, int id, char* nome, char* espe)
{
	Representante* novo;
    
    //==========================================
    novo = malloc(sizeof(Representante));
    novo->info = malloc(sizeof(Rep));
    novo->info->ID = id;
    novo->info->nome = malloc(100*sizeof(char));
    novo->info->esp = malloc(100*sizeof(char));
    strcpy(novo->info->nome, nome);
    strcpy(novo->info->esp, espe);
    novo->next = NULL;
	//==========================================
	Representante *aux;
	Representante *ant;
	ant = NULL;
	
	
    for(aux = *l; aux != NULL && strcmp(nome, aux->info->nome) > 0; aux = aux->next){
    	ant = aux;	
	}
	
	if(ant == NULL){
		// Lista Vazia
		novo->next = aux;
		*l = novo;
	}else{
		ant->next = novo;
		novo->next = aux;
	}
}

// Remove o representante.
// Recebe o número id do representante, por ser único.
// Caso recebesse o nome, existe a possibilidade de mais de um representate possuir o mesmo nome.
void removerRep(Representante** l, int id)
{
	Representante *p, *ant = NULL;
	for (p = *l; p != NULL && p->info->ID != id; p = p->next)
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

void alterarRep(Representante** l, int id, char* nome, char* espe)
{
		Representante *novo = malloc(sizeof(Representante));
		novo->info->nome = nome;
		novo->info->esp = espe;
		if (strcmp(novo->info->esp, espe) && strcmp(novo->info->nome, nome))
			printf("Alterado com sucesso!\n");
		else
			printf("Algum erro ocorreu e nao foi possivel alterar Cliente!\n");
}

// O t é a opção para onde deve ser jogado as informações
// Se t = 4, inserir Ordenado
// Se t = 5, Remover Representante
void pegaInfoRep(Representante** l, int t)
{
	int id = contaRep(l);
	char *nome = malloc(sizeof(char) * 100);
	char *espe = malloc(sizeof(char) * 100);

	if (t == 5)
	{
		printf("Digite o ID: ");
		scanf("%d", &id);
		removerRep(l, id);
		printf("Pressione [ENTER] para continuar\n");
		fflush(stdin);
		getchar();
		return;
	}

	printf("Digite o nome do representante: ");
	fflush(stdin);
	fflush(stdout);
	scanf(" %[^\n]s", nome);
	nome = strupr(nome);

	printf("Digite o nome da especializacao: ");
	fflush(stdin);
	fflush(stdout);
	scanf(" %[^\n]", espe);

	espe = strupr(espe);
	if (t == 4)
		inserirOrdenadoRep(l, id, nome, espe);
	else
		alterarRep(l, id, nome, espe);
	printf("Pressione [ENTER] para continuar\n");
	fflush(stdin);
	getchar();
}

// Função para contar quantos representantes já foram incluidos
// retorna o id do último incluido
int contaRep(Representante** l)
{
	int valor = 0;
	Representante *p;
	if (estaVazioRep(l))
	{
		printf("Esta vazia!\n");
	}
	else
	{
		for (p = *l; p != NULL; p = p->next)
		{
			if (p->info->ID > valor)
				valor = p->info->ID;
		}
	}
	return ++valor;
}

//Função para imprimir a lista de representantes.
void imprimirRep(Representante** l)
{
	Representante* p;
	if (estaVazioRep(l))
	{
		printf("Esta vazia!\n");
	}
	else
	{
		printf("\t\tLista completa de representante:\n\n");
		for (p = *l; p != NULL; p = p->next)
			printf("ID: %d\t Nome: %s\t Especializacao: %s\n", p->info->ID, p->info->nome, p->info->esp);
	}
	printf("Pressione [ENTER] para continuar\n");
	fflush(stdin);
	getchar();

}

//Função para liberar a lista antes de fechar o programa
void liberaListaRep(Representante** l)
{
	if (!estaVazioRep(l))
	{
		Representante *p, *temp;
		for (p = *l; p != NULL; p = temp)
		{
			temp = p->next;
			free(p);
		}
		*l = NULL;
	}
	
}