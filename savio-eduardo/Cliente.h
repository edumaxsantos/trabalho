#ifndef CLIENTE_H_
#define CLIENTE_H_
//#include "Lista.h"

typedef struct cli Cli;
typedef struct cliente Cliente;



void inicializaCli(Cliente **l);
int estaVazioCli(Cliente **l);
void pegaInfoCli(Cliente **l, int t);
void liberaListaCli(Cliente **l);
void imprimirCli(Cliente **l);

#endif /* CLIENTE_H_ */