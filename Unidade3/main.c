#include <stdio.h>
#include "tabhash.h" // Arquivo header onde estarão as declarações das funções e structs

int main() {
    // Cria uma tabela hash com tamanho 10
    struct tabela_hash *tabela = hash_criar(10);

    if (!tabela) {
        printf("Erro ao criar a tabela hash.\n");
        return 1;
    }

    // Insere algumas palavras e valores na tabela
    if (hash_inserir(tabela, "palavra1", 100))
        printf("Inserido: palavra1 -> 100\n");
    else
        printf("Erro ao inserir palavra1.\n");

    if (hash_inserir(tabela, "palavra2", 200))
        printf("Inserido: palavra2 -> 200\n");
    else
        printf("Erro ao inserir palavra2.\n");

    if (hash_inserir(tabela, "palavra3", 300))
        printf("Inserido: palavra3 -> 300\n");
    else
        printf("Erro ao inserir palavra3.\n");

    // Tenta inserir uma palavra já existente
    if (hash_inserir(tabela, "palavra1", 400)){

        printf("Inserido: palavra1 -> 400\n");
    }
    else{

        printf("Erro ao inserir palavra1 (já existente).\n");
    }

    // Busca por uma palavra na tabela
    int resultado = hash_buscar(tabela, "palavra2");
    if (resultado >= 0)
        printf("Encontrado: palavra2 -> %d\n", resultado);
    else
        printf("palavra2 não encontrada.\n");

    // Remove uma palavra da tabela
    if (hash_remover(tabela, "palavra2"))
        printf("Removido: palavra2\n");
    else
        printf("Erro ao remover palavra2.\n");

    // Tenta buscar uma palavra removida
    resultado = hash_buscar(tabela, "palavra2");
    if (resultado >= 0)
        printf("Encontrado: palavra2 -> %d\n", resultado);
    else
        printf("palavra2 não encontrada.\n");

    // Destrói a tabela hash
    hash_destruir(tabela);
    printf("Tabela hash destruída.\n");

    return 0;
}