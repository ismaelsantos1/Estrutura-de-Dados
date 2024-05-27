#ifndef _LLIGADA_H_
#define _LLIGADA_H_

#include <stddef.h>

struct No {
    int mat;
    char *nome;
    struct No *ant;
    struct No *prox;
};

struct No* inserir(struct No *lista, int mat, char *nome);
struct No* remover(struct No *lista, int mat);
struct No* buscarMatricula(struct No *lista, int mat);
struct No* buscarNome(struct No *lista, char *nome);
int tamanho(struct No *lista);
void imprimir(struct No *lista);

#endif