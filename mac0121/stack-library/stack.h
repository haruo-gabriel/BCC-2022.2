/*
    Biblioteca para a estrutura de dado "pilha"
    criada manualmente.

    Autor: Gabriel Haruo
    Apoio: Prof. Carlinhos
 */

typedef struct{
    char *V;
    int topo;
    int max;
} pilha;

typedef char item;

#define ERRO '\0'

void empilha (pilha *p, item x);

item desempilha (pilha *p);

item topoPilha (pilha *p);

int pilhaVazia (pilha *p);

pilha cria ();

void destroi (pilha *p);

void resize (pilha *p);
