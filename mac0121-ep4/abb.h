typedef struct celIND {
	int linha;
	int cont;
	struct celIND *prox;
} noIND;

typedef struct celABB {
	char *chave;
	struct cel *esq;
	struct cel *dir; 
	struct noIND *info;
} noABB;

noABB *buscaABB (noABB *raiz, char *palavra);
noABB *insereABB (noABB *raiz, char *palavra);
void insereLinhas ()
void destroi (noABB *raiz);
void preordem (noABB *raiz);