#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila1.h"
#include <stdbool.h>


struct Fila *criar(int tam){
    struct Fila *nova = (struct Fila *) malloc(sizeof(struct Fila));
	nova->tam=tam;
	nova->ini=0;
	nova->fim=0;
	nova->qtd=0;
	nova->vet = (int *)malloc(tam * sizeof(int));
    
    printf("é nós\n\n");
	return nova;
}

int inserir(struct Fila *f, int num){
    
        if((f->qtd <= f-> tam) && (f->fim != f->tam)){  //Verificando se a fila está cheia ou não e se o fim da fila é menor que o tamanho
            f->fim++;
            f->vet[f->qtd]= num;

            f->qtd++;
            /*if(f->fim==f->tam-1){
                /*if(f->ini!=0 && f->vet+0== NULL){
                    f->fim = 0;
                    return 1;
                    if(f->vet+(f->fim+1)==NULL){
                        f->fim++;
                        return 1;
                    }
                } else{
                    f->fim++;
                    return 1;
                }
            } */
        } else{
            printf("\nFila cheia!\n");
            return 0;
        }
    return 1;
}


int remover(struct Fila *f, int *num){
    f->qtd--;
    
    if(f->vet+f->ini!=NULL){
        num=&f->vet[f->ini];
        printf("%d\n", *num);
        f->vet[f->ini]=0;
        
        if(f->ini==f->tam-1){
            if(f->vet+0!=NULL){ //fila continua com elementos
                f->ini=0;
                return 1;
            } else{
                f->ini = f->fim=0; //IF = FF 
                return 1;
            }
        } else{
            f->ini++; 
            return 1;
        }
        return 1;
    }
    return 0;
}

void imprimir(struct Fila *f){
    for(int i=0; i<f->qtd; i++){
        printf("%d, ", f->vet[i]);
    }
}


void destruir(struct Fila *f){free(f);}

