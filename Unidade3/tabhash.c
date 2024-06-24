#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabhash.h"


// Definição do nó que será utilizado no encadeamento
struct No {
    char *palavra;
    int dado;
    struct No *prox;
};

// Definição da estrutura da tabela hash
struct tabela_hash {
    struct No **v;
    int pesos[100];
    int tam;
};

// Função hash para calcular o índice da palavra na tabela
int funcao_hash(char *palavra, int tam, int pesos[]) {
    
    int hash = 0;
    for (int i = 0; palavra[i] != '\0'; i++) {
        hash = hash * 31 + palavra[i] * pesos[i % 100];
    }
    return hash % tam;
}

// Função para criar uma tabela hash de tamanho `tam`
struct tabela_hash *hash_criar(int tam) {
    struct tabela_hash *t = malloc(sizeof(struct tabela_hash));
    if (!t) return NULL;

    t->v = malloc(tam * sizeof(struct No *));
    if (!t->v) {
        free(t);
        return NULL;
    }

    for (int i = 0; i < tam; i++) {
        t->v[i] = NULL;
    }

    for (int i = 0; i < 100; i++) {
        t->pesos[i] = rand() % 100 + 1; // Inicializa pesos com valores aleatórios entre 1 e 100
    }

    t->tam = tam;
    return t;
}

// Função para destruir uma tabela hash
void hash_destruir(struct tabela_hash *t) {
    
    if (!t) return;

    for (int i = 0; i < t->tam; i++) {
        struct No *no = t->v[i];
        while (no) {
            struct No *tmp = no;
            no = no->prox;
            free(tmp->palavra);
            free(tmp);
        }
    }

    free(t->v);
    free(t);
}

// Função para inserir uma palavra e um dado na tabela hash
int hash_inserir(struct tabela_hash *t, char *palavra, int dado) {
    if (!t) return 0;

    int idx = funcao_hash(palavra, t->tam, t->pesos);
    struct No *no = t->v[idx];

    while (no) {
        if (strcmp(no->palavra, palavra) == 0) {
            return 0; // Palavra já existe na tabela
        }
        no = no->prox;
    }

    no = malloc(sizeof(struct No));
    if (!no) return 0;

    no->palavra = strdup(palavra); //vai duplicar a string, copiando a string para uma nova área da memória
    if (!no->palavra) {
        free(no);
        return 0;
    }

    no->dado = dado;
    no->prox = t->v[idx];
    t->v[idx] = no;
    return 1;
}

// Função para remover uma palavra da tabela hash
int hash_remover(struct tabela_hash *t, char *palavra) {
    if (!t) return 0;

    int idx = funcao_hash(palavra, t->tam, t->pesos);
    struct No *no = t->v[idx];
    struct No *prev = NULL;

    while (no) {
        if (strcmp(no->palavra, palavra) == 0) {
            if (prev) {
                prev->prox = no->prox;
            } else {
                t->v[idx] = no->prox;
            }
            free(no->palavra);
            free(no);
            return 1;
        }
        prev = no;
        no = no->prox;
    }
    return 0;
}

// Função para buscar uma palavra na tabela hash
int hash_buscar(struct tabela_hash *t, char *palavra) {
    if (!t) return -1;

    int idx = funcao_hash(palavra, t->tam, t->pesos);
    struct No *no = t->v[idx];

    while (no) {
        if (strcmp(no->palavra, palavra) == 0) {
            return no->dado;
        }
        no = no->prox;
    }
    return -1;
}
