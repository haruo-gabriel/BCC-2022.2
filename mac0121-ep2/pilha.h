#define ERRO '\0'

typedef struct {
  int len;
  int naPilha;
  int direcao; /* 0 para horizontal e 1 para vertical */
  int pini[2]; /* coordenadas (linha, coluna) da primeira letra da palavra */
  int pfim[2]; /* coordenadas (linha, coluna) da ultima letra da palavra */
  /*char *string;*/
  char string[46];
} palavra;

typedef palavra item;

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
pilha * cria(int tam); 
void destroi(pilha * p); 

/* vetor vocabulario que armazena todas as palavras*/
typedef struct {
  int tam;
  int topo;
  palavra *v;
} vocab;

void lePalavras(palavra *voc, int npal);
void imprimeVocab(palavra *voc, int npal);
void destroiVocab(vocab *voc);