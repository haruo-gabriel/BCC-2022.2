//typedef struct {
//  int lin;
//  int col;
//  int mov; /* movimento que é feito a partir da casa que o cavalo está */
//} cavalo; 
//
//typedef cavalo item;

typedef struct{
	int tam;
	char *[int];
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
pilha * cria(); 
void destroi(pilha * p); 
