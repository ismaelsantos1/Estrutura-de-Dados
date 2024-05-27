#include "Arvorebb.h"
#include <stdio.h>
#include <stdlib.h>

struct No *criarArv(int num){

    struct No *raiz = (struct No*) malloc(sizeof(struct No));

    if(raiz != NULL){
        raiz->num = num;
        raiz->FB = 0;
        raiz->fesq = NULL;
        raiz->fdir = NULL; 
    }
    return raiz;

}


int altura(struct No *arv){
    if(arv == NULL){
        return 0;
    }

    int alturaMax = 0;
    int alturaEsq = altura(arv->fesq);
    int alturaDir = altura(arv->fdir);

    if(alturaDir > alturaEsq){
        
        alturaMax = alturaEsq +1;
    
    } else{
        alturaMax = alturaDir + 1;
    }
    return alturaMax;
}

int fDeBalanceamento(struct No *arv){
    if(arv == NULL){
        return 0;
    }

    int FB = (altura(arv->fesq))- (altura(arv->fdir));
    return FB;
}

struct No *rotDir(struct No *Y){

}

struct No *rotEsq(struct No *arv){

    struct No *Y;

    Y = arv->fdir;

    int minB = Y->FB < 0 ? Y->FB : 0;

    arv->FB = arv->FB +1 - minB;
    
    int maxA = arv->FB  > 0 ? arv->FB : 0;

    Y-> FB = Y->FB +1 + maxA;

    arv->fdir = Y->fesq;
    Y->fesq = arv;

    if(Y->FB <0){

        int minB = Y->FB;

    } else{
        minB = 0;
    }

    arv->FB = arv->FB +1 - minB;
    return Y;

}

struct No *balancear(struct No *arv, int num){

    if(arv == NULL){
        return arv;
    }

    arv->FB = fDeBalanceamento(arv);

    if(arv->FB > 1){
        //Se LL: Desbalanceamento à esq do filho do esq

        if (num < arv->fesq->num){
            return rotDir(arv);
        }

        //Se LR: Desbalanceamento à direita do filho esq
        else if(num>arv->fesq->num){
            arv->fesq = rotEsq(arv->fesq);

            return rotDir(arv);
        }
    }

    if(arv->FB< -1){
        
    }
}

