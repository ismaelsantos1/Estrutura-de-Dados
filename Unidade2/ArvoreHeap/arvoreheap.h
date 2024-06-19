#ifndef _ARVOREHEAP_H
#define _ARVOREHEAP_H


struct Heap {
    int tam;
    int qtd;
    int *v; //ponteiro para o vetor
};

struct Heap *criar(int tam);
int inserir(struct Heap *h, int num);
int remover(struct Heap *h, int *num);
void construir(struct Heap *h, int *vet, int tam, int qtd);
void destruir(struct Heap *h);
#endif