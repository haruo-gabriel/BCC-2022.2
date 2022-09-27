typedef struct {
  item * v; 
  int topo; 
  int tam; 
} pilha;

typedef palavra item;

void empilha (pilha * p, item x); 
item desempilha (pilha * p); 
item topoPilha (pilha * p); 
int pilhaVazia (pilha * p); 
pilha * resize (pilha * p);
pilha * cria(int tam); 
void destroi(pilha * p); 



typedef struct {
  int tam;
  int naPilha;
  int pini[2]; /* coordenadas (linha, coluna) da primeira letra da palavra */
  int pfim[2]; /* coordenadas (linha, coluna) da ultima letra da palavra */
  char string[tam];
  /* char string[46] */
} palavra;

/* vetor vocabulario que armazena todas as palavras*/
typedef struct {
  int tam;
  int topo;
  palavra *v;
} vocab;

palavra criaPalavra();
void adicionaPalavra();
void destroiVocabulario(vocab *voc);