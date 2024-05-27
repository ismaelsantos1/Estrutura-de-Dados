#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct No{
    int *ult;
    int *init;
    int num;
    int vet2[];
};

    struct No vet;

int inserir(int n2) {

    bool verif = false;
    
    if(vet.init == NULL && vet.ult == NULL){  //Se a fila estiver vazia
        vet.vet2[0] = n2;
        vet.ult = &vet.vet2[0];
        vet.init = &vet.vet2[vet.num -1]; //ou &vet[0], dá no mesmo

        return 0;
    }

    int i=-1, b;          //enquanto o índice (n) for diferente do tam máximo do vetor              
    while(verif==false || (i!=vet.num)){    
        i++;
        if(vet.vet2[i]==NULL) {
            verif = true;
        }
    }

    if(verif==true){
        vet.vet2[i]= n2;
        vet.ult = &vet.vet2[b]; //mostra o endereço do final da fila (FF)
        printf("a\n");

    }else{
        printf("Está cheio");
    }

}

void imprimir(){

    printf("\n\n");
    for(int i=0; i<vet.num; i++){
        printf("%d, ", vet.vet2[i]);
    }
    printf("%d, %x", vet.vet2[2], *vet.ult);
}
int main(){

    int n;
    
    printf("Insira o tamanho da fila: "); scanf("%d", &n);
    vet.num = n;
    //FILA
    printf("%d\n", vet.num);
    
    
    vet.vet2[vet.num];

    printf("Digite um valor:\n --> ");
    scanf("%d", &n);
    getchar(); //limpa buffer do enter


    return 0;
}