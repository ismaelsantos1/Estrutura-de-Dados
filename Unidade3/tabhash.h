#ifndef TABHASH__
#define TABHASH__

struct tabela_hash {
struct No **v;
int pesos[100];
int tam;
};

struct tabela_hash *hash_criar(int tam);
void hash_destruir(struct tabela_hash *t);
int hash_inserir(struct tabela_hash *t, char *palavra, int dado);
int hash_remover(struct tabela_hash *t, char *palavra);
int hash_buscar(struct tabela_hash *t, char *palavra);

#endif