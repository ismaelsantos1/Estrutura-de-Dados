#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "fila1.h"
#include <stdbool.h>

int main() {
 struct Fila *fila = NULL;
	int n, insere, num, aviso, *num2;
	bool ver=false;

	do{
		sleep(400);
		system("clear");
		printf(" - digite a funcao que deseja acessar\n"
			"\n[1] - criar"
			"\n[2] - inserir"
			"\n[3] - remover"
			"\n[4] - imprimir"
            "\n[5] - destruir"
			"\n[0] - finalizar codigo\n/==> ");
		scanf("%d", &insere);

		if(insere==1){
			printf("Insira o tamanho do vetor\n/==> ");
			scanf("%d", &n);
			fila = criar(n);
            //printf("\nDIGITE O CODIGO NOVAMENTE PARA CONFIRMAR\n");
			//scanf("%d", &insere);
            
		} else if(insere==2){
			int confirma = 1;
			if(confirma){

			printf("Informe o valor que deseja inserir\n/==> ");
			scanf("%d", &num);
			}
			confirma = inserir(fila, num);
			//printf("--%d--\n", aviso);
            //printf("\nDIGITE O CODIGO NOVAMENTE PARA CONFIRMAR\n");
			//scanf("%d", &insere);
		
        } else if (insere==3){
            remover(fila, num2);
            //printf("\nDIGITE O CODIGO NOVAMENTE PARA CONFIRMAR\n");
            scanf("%d",&insere);
        
        }else if(insere==4){
            imprimir(fila);
            //printf("\nDIGITE O CODIGO NOVAMENTE PARA CONFIRMAR\n");
            scanf("%d", &insere);
        
        } else if(insere==5){
            //printf("\nDIGITE O CODIGO NOVAMENTE PARA CONFIRMAR\n");
			destruir(fila);
		} else{
			//sleep(1000);
            printf("Programa finalizado");
            return 0;
        }
        
	} while (ver==false);
	
	return 0;
}