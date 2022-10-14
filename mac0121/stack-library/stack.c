#include "stack.h"

void empilha (pilha *p, item x){
    if (p->topo == p->max)
        resize(p);
    
    p->V[p->topo] = x;
    p->topo++;
}

item desempilha (pilha *p){
    item temp;

    if (pilhaVazia(p))
        return ERRO;

    p->topo--;
    temp = p->V[p->topo];
    p->V[p->topo] = ERRO;
    return temp;
}

item topoPilha (pilha *p){
    if (pilhaVazia(p))
        return ERRO;

    return p->V[p->topo-1];
}

int pilhaVazia (pilha *p){
    return (p->topo == 0);
}

pilha cria (){
    pilha *p = malloc(sizeof(pilha));
    pilha->max = 1;
    pilha->topo = 0;
    pilha->V = malloc(p->max * sizeof(item));
    return p;
}

void destroi (pilha *p){
    free p->V;
    free p;
}

void resize (pilha *p){
    int i;
    item *q = malloc(2 * p->max * sizeof(item));

    for (i=0; i < 2*p->max; i++)
        q[i] = p->V[i];
    
    
    free(p->V);
    p->V = q;
}
