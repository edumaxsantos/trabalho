#ifndef REPRESENTANTE_H_
#define REPRESENTANTE_H_


typedef struct representante Representante;
typedef struct rep Rep;

void inicializaRep(Representante** l);
int estaVazioRep(Representante** l);
void pegaInfoRep(Representante** l, int op);
void imprimirRep(Representante** l);
void liberaListaRep(Representante** l);
#endif /* REPRESENTANTE_H_ */