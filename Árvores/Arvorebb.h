#ifndef _ARVOREBB_H
#define _ARVOREBB_H

struct No{
    int num;
    int FB;
    struct No *fesq;
    struct No *fdir; 
};

struct No *inserir(struct No *arv, int num);
struct No *remover(struct No *arv, int num);

#endif
