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
void destroiABB (noABB *raiz);
void destroiIND (noIND *info);
void inordemABB (noABB *raiz);
void inordemIND (noIND *info);