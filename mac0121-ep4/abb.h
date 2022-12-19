typedef struct celIND {
	int linha;
	int cont;
	struct celIND *esq;
	struct celIND *dir;
} noIND;

typedef struct celABB {
	char *chave;
	struct celABB *esq;
	struct celABB *dir; 
	noIND *info;
} noABB;

noABB *insereABB (noABB *raiz, char *palavra, int linha);
noIND *insereLinhas (noIND *info, int linha);
noABB *buscaABB (noABB *raiz, char *palavra);
void destroi (noABB *raiz);
void preordemABB (noABB *raiz);
void preordemIND (noIND *raiz);