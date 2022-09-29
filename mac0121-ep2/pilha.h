#define ERRO '\0'

typedef struct {
  int len;
  int naPilha;
  int direcao; /* 0 para horizontal e 1 para vertical */
  int pini[2]; /* coordenadas (linha, coluna) da primeira letra da pal */
  int pfim[2]; /* coordenadas (linha, coluna) da ultima letra da pal */
  /*char *string;*/
  char string[46];
} pal;

typedef pal item;

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

void lePalavras(pal *voc, int npal);
void imprimeVocab(pal *voc, int npal);
void ordenaVocab (pal *voc, int npal);