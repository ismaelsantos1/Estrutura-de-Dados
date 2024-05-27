#include "listaligada.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct No* inserir(struct No *lista, int mat, char *nome) {
    struct No *novo = (struct No *) malloc(sizeof(struct No));
    if(novo == NULL) {
        printf("Erro de alocacao\n");
        return lista;
    }
                //function allocates sufficient memory for a copy of the string str , does the copy, and returns a pointer to it. 
    novo->nome = strdup(nome);
    novo->mat = mat;
    if(lista == NULL) {
        novo->prox = NULL;
        novo->ant = NULL;
        return novo;
    }
    struct No *atual = lista;


    while(atual != NULL){
        if(strcmp(nome, atual->nome)>0 && ((atual->prox == NULL) || strcmp(nome, atual->prox->nome)<0)){
            novo->prox = atual->prox;
            novo->ant = atual;
            atual->prox = novo;
            return lista;
        }
        atual = atual->prox;
    }

    novo->prox = lista; //acessa o prox e recebe lista (supõe-se que a lista não está vazia (NULL))
    novo->ant = NULL; //novo, ou seja, o nome que foi inserido agora, acessará o anterior e vai receber NULL pois o anterior a ele é vazio
    lista->ant = novo; //lista vai acessar o anterior e receber o novo nome inserido (se houver) e colocá-lo na lista 
    return novo; //ao retornar novo, ele  passa a ser o primeiro da lista, além estar salvo
   
        return novo;
}


struct No* remover(struct No *lista, int mat) { 
    
    struct No* remover = buscarMatricula(lista, mat);
    struct No* temp;

    //Se o elemento não existir vai retornar a lista original
    if(remover == NULL) return NULL;

    /*Caso seja o primeiro elem, lista passará a apontar papra o elemento seguinte (novo início da lista) e o elemento passa apontar para NULL*/
    if(remover->ant == NULL){//Se é o primero
        lista= remover->prox;
        remover-> prox == NULL;

    }else{
        temp = remover->ant->prox;
        remover->ant->prox = remover->prox;
        remover->prox = NULL;
    }

    free(remover);
    return lista;

}

struct No* buscarMatricula(struct No *lista, int mat) {
    
    struct No* atual = lista;
    
    while(atual!= NULL){
        if(atual->mat == mat){
            printf("\nEncontrou!\n");
            return atual;
        }
        atual = atual->prox;
    }
    
    return NULL;
}

struct No* buscarNome(struct No *lista, char *nome) {
    
    struct No* atual = lista;

    while(atual!= NULL && strcmp(atual->nome, nome)<0) atual  = atual->prox;
    
    if(atual != NULL && !strcmp(atual->nome, nome)) return atual;
    
    return NULL;
}

int tamanho(struct No *lista) {
    
    struct No* fDaLista = lista;

    int tam = 0;

    while(fDaLista != NULL) {

        tam++;
        fDaLista = fDaLista->prox;
    }
    return tam;
}


void imprimir(struct No *lista) {
    if(lista == NULL) {
        printf("Lista vazia\n");
        return;
    }

    printf("%s - %d", lista->nome, lista->mat);
    
    lista = lista->prox;
    while(lista != NULL) {
        printf(" %s - %d", lista->nome, lista->mat);
        lista = lista->prox;
    }
    printf("\n");
}