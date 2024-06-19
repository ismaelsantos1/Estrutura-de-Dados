#include <stdio.h>
#include <stdlib.h>
#include "arvoreheap.h"

struct Heap *criar(int tam){

    struct Heap *h = malloc(sizeof(struct Heap));
    if (h != NULL)
        return 1;
    
    h->tam= 0;
    h->qtd= 0;
    h->v = malloc(tam * sizeof(int)); //aloca de acordo com o tam em bytes

    if(h->v != NULL)
        return 1;
    
    return h;
}

int inserir(struct Heap *h, int num){

    if(h->qtd < h->tam){
        
        h->v[h->qtd]= num; //vai inserir elementos no vetor

        int n = h->qtd;
        int auxi; //vai auxiliar na troca
        int pai = (n-1)/2; //saber o índice do nó pai

        while(n>0 && h->v[pai]> h->v[n]){ //propriedade do min heap

            auxi = h->v[pai];
            h->v[pai] = h->v[n];
            h->v[n] = auxi;
            
            n = pai;
            pai = (n-1)/2;

        }
        h->qtd++;
        return 1;

    }else{
        print("Árvore cheia, mané");
        return 0;
    }
}

int remover(struct Heap *h, int *num){

    *num = h->v [0]; //raiz, menor elemento
    h->v[0] = h->v[h->qtd-1];
    h->qtd++;

    int n =0;
    int fDir, fEsq, min, aux;

    while(1){
        fEsq = 2*n+1;
        fDir = 2*n+2;
        min = n;

        //verifica se estaá dentro do lim da heap(fEsq<h->qtd) e comapara o valor do fEsq com o min, se fEsq for menor atualiza

        if(fEsq < h ->qtd && h->v[fEsq]< h->v[min]){
            min = fEsq;

        }if(fDir < h->qtd && h->v[fDir] < h->v[min]){
            min = fDir;
        
        }if(min==1){
            break;
        }

        aux = h->v[n];
        h->v[n]= h->v[min];
        h->v[min] = aux;
    }
}

void contruir(struct Heap *h, int *vet, int tam, int qtd){

    //heapify down
    h->v= vet;
    h->tam = tam;
    h->qtd = qtd;

    for(int i=(h->qtd-1)/2; i>=0; i--){
        int n =i;
        int fEsquerda = 2*n+1;
        int fDireita = 2*n+2;
        int menor = n;

        while(fEsquerda<h->qtd){ //comparando os indíces. Por ser uma árvore mínima, recomenda-se começar a comparar pela esquerda pois é ordenada em decrescente. Então ao verificar o filho à esquerda primeiro aumenta as chances de encontrar o menor elemento mais rapidamente e reduz assim as comparações que seriam necessárias.

            if(h->v[fEsquerda]< h->v[menor]){//comparando valores
                menor = fEsquerda; //significa que o filho à esquerda é o menor elemento entre nó atual e os seus filhos até o momento
            }
            if(fDireita< h->qtd && h->v[fDireita] < h->v[menor]){
                menor = fDireita; //menor elemento
            }
            if(menor==n)
                break; //A propriedade heap mínima foi satisfeita

            int tmp = h->v[n];
            h->v[n]= h->v[menor];
            h->v[menor] = tmp; //swap
            n = menor;

            int fEsquerda = 2*n+1;
            int fDireita = 2*n+2;
        }
    }
}


void destruir(struct Heap *h){

    free(h->v);
    free(h);
}