#define ERRO '\0'

typedef struct {
  /*char *string;*/
  char string[46];
  int len;
  int naPilha;
  int posicao[2]; /* coordenadas (linha, coluna) da primeira letra da pal */
  int direcao; /* 0 para horizontal e 1 para vertical */
} pal;

typedef pal *item; /* Será uma pilha de ponteiros para as palavras do voc */

typedef struct {
  item * v;
  int topo; 
  int tam;
} pilha;

void empilha (pilha * p, item x);
item desempilha (pilha * p); 
item topoPilha (pilha * p); 
int pilhaVazia (pilha * p); 
pilha * resize (pilha * p);
pilha * criaPilha (int tam);
void destroiPilha (pilha * p);

