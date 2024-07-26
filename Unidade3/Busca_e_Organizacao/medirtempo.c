#include <stdio.h>
//#include <windows.h>
#include "vetores.h"

void buscaSequencial(int vetor[], int qntdElementos){
	for(int i = 0; i < qntdElementos; i++) {
		//printf("%d ", vetor[i]);
	}
	printf("\n");
}
 
void buscaBinaria (int vetor[], int qntdElementos) { 
    int chave = 10000000;
    int ini = -1; 
    int fim = qntdElementos;
    while (ini < fim - 1) {  
        int meio = (ini + fim) / 2;
        if (vetor[meio] < chave){
            ini = meio;
        }
        else {
            fim = meio;
        } 
    }
}

void bubbleSort(int vetor[], int qntdElementos) {
    int aux;
    for (int i = 0; i < qntdElementos - 1; i++) {
        for (int j = 0; j < qntdElementos - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void selectionSort(int vetor[], int qntdElementos) {
    int i, j, min_idx, aux;
    
    for (i = 0; i < qntdElementos-1; i++) {
        min_idx = i;
        for (j = i+1; j < qntdElementos; j++){
            if (vetor[j] < vetor[min_idx])
                min_idx = j;
		}
        aux = vetor[min_idx];
        vetor[min_idx] = vetor[i];
        vetor[i] = aux;
    }
}

void quickSort(int vetor[], int qntdElementos) {
    if (qntdElementos <= 1) {
        return; // Se o vetor tiver 1 ou 0 elementos, ele já está ordenado
    }

    int pivot = vetor[qntdElementos - 1]; // Escolhe o último elemento como pivô
    int i = -1; // Índice do menor elemento

    for (int j = 0; j < qntdElementos - 1; j++) {
        if (vetor[j] <= pivot) {
            i++;
            // Swap usando uma variável temporária
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    // Swap do pivô para a posição correta
    int aux = vetor[i + 1];
    vetor[i + 1] = vetor[qntdElementos - 1];
    vetor[qntdElementos - 1] = aux;

    // Índice de partição
    int pi = i + 1;

    // Recursivamente ordena os elementos antes e depois da partição
    quickSort(vetor, pi); // Ordena a primeira metade
    quickSort(vetor + pi + 1, qntdElementos - pi - 1); // Ordena a segunda metade
}

/* CODIGO PARA O WINDOWS CASO A IDE NAO MOSTRE O TEMPO DE EXECUCAO */

int main() {
	int qntdElementos = 100000;
	int inicio, final;

	//inicio = GetTickCount(); /* guarda o tempo inicial em milisegundos */

	/* codigo a ser calculado o tempo de execucao deve ficar entre as duas chamadas a funcao GetTickCount() */
	quickSort(aleat, qntdElementos);

	//final = GetTickCount(); /* guarda o tempo final em milisegundos */

	//printf("Tempo = %dms\n", final - inicio);

	return 0;
}