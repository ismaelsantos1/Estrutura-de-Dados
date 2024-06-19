#include <stdio.h>
#include <stdlib.h>
#include "arvoreheap.h"

int main(){
    struct Heap *h;

    imprime(h);

    h = inserir(h, 10);
    imprime(h);

    h = inserir(h, 5);
    imprime(h);

    h = inserir(h, 6);
    imprime(h);

    h = inserir(h, 12);
    imprime(h);

    h = inserir(h, 7);
    imprime(h);


    h = remover(h, 4);
    imprime(h);

    h = remover(h, 5);
    imprime(h);

    int n;
    printf("Digite o valor 0 para destruir a árvore: ");
    scanf("%d", &n);
    return 0;
}
