#ifndef _LLIGADA_H_
#define _LLIGADA_H_

#include <stddef.h>

struct Fila {
int tam;
int qtd;
int ini;
int fim;
int *vet;
};

struct Fila *criar(int tam);
int inserir(struct Fila *f, int num);
int remover(struct Fila *f, int *num);
void imprimir(struct Fila *f);
void destruir(struct Fila *f);

#endif