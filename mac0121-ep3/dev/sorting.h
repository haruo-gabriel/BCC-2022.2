extern int comparacoes_insertion;
extern int trocas_insertion;

extern int comparacoes_merge;
extern int trocas_merge;

extern int comparacoes_quick;
extern int trocas_quick;

extern int comparacoes_heap;
extern int trocas_heap;


void printWords(char **words, int nwords);
char **copyWords (char **words, int nwords);
void freeWords (char **words, int nwords);

void insertionSort (char **A, int n);

void merge (int ini, int meio, int fim, char **v);
void mergeSort (int meio, int fim, char **v);

void troca (int *indexes, int i, int j);
int particiona (char **v, int *indexes, int ini, int fim);
void quickSort (char **v, int *indexes, int ini, int fim);
char **remontaWords (char **original, int *indexes, int nwords);