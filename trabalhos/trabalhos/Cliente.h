#ifndef CLIENTE_H_
#define CLIENTE_H_


typedef struct cliente Cliente;

void inicializaCliente(Cliente** l);
int estaVazia(Cliente** l);
void inserirCliente(Cliente** l);

#endif /* CLIENTE_H_ */