#include "listaligada.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
    struct No *lista =  NULL;
    char nome[100];
    imprimir(lista);
    scanf("%s", nome);
    lista = inserir(lista, 123, nome);
    imprimir(lista);
    scanf("%s", nome);
    lista = inserir(lista, 234, nome);
    imprimir(lista);
    scanf("%s", nome);
    lista = inserir(lista, 456, "Ismael");
    imprimir(lista);
    lista = inserir(lista, 678, "Natália");
    imprimir(lista);
    scanf("%s", nome);
    lista = inserir(lista, 789, nome);
    imprimir(lista);
    
    system("clear");
    
    printf("Abaixo existem algumas ações que podem ser realizadas\n\n");
    int choice;
    printf("Seleciona a opção que deseja:\n"
    "1 - inserir"
    "2 - remover"
    "3 - buscar matrícula"
    "4 - buscar nome"
    "5 - tamanho");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            inserir();
            break;
        case 2:
            remove();
            break;
        case 3:
            buscarMatricula();
            break;
        case 4:
            buscarNome();
            break;
        case 5:
            tamanho();
            break;
        default:
            printf("\nOpção inválida
    }
    //printf("FIM\n");
    return 0;
}