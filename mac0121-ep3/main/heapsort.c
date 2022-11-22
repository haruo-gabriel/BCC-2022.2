#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sorting.h"

#define MAXWORD 12
#define NWORDS 64000

/* compiling
gcc -Wall -ansi -pedantic -O2 *.c -o a
*/


void heapSort (char **v, int *indexes, int n);
void heapfica (char **v, int *indexes, int n, int i);
void trocaHeap (int *v, int i, int j);

int main(){
    /*Inicialização*/
    char **words;
    int nwords, i, j;
    FILE *randomwords, *sortedwords;
    int *indexes;
    char buf[0x100];

    randomwords = fopen("../worddata/randomwords.txt", "r");
    if (randomwords == NULL){
        printf("failed to open file. aborting now.\n");
        return 1;
    }

    /*i = fscanf(randomwords, "%d", &nwords);
    if (i != 1){
        printf("error reading nwords. aborting now.\n");
        return 1;
    }*/
    nwords = NWORDS;
    printf("%d words\n", nwords);

    words = malloc(nwords * sizeof(char *));
    
    for(i = 0; i < nwords; i++){
        words[i] = malloc(MAXWORD * sizeof(char));
        j = fscanf(randomwords, "%s", words[i]);
        if (j != 1){
            printf("error reading word. aborting now.\n");
            return 1;
        }
    }

    /*printWords(words, nwords);*/

    fclose(randomwords);

    indexes = malloc(nwords * sizeof(int));
    for (i = 0; i < nwords; i++){
        indexes[i] = i;
    }

    /*Ordenação*/
    printf("After heap sort\n");
	heapSort(words, indexes, nwords);
    /*printWords(words, nwords);*/
    words = remontaWords(words, indexes, nwords);
	printf("comparações: %d\n", comparacoes_heap);
	printf("trocas: %d\n", trocas_heap);
    /*printWords(words, nwords);*/

    /*Impressão em arquivo*/
    snprintf(buf, sizeof(buf), "../worddata/sortedwords%d.txt", nwords);
    sortedwords = fopen(buf, "w");
    if (sortedwords == NULL){
        printf("error while opening write file. aborting now.\n");
    }
    escreveWords(words, nwords, sortedwords);
    fclose(sortedwords);
    
    
    freeWords(words, nwords);
    free(indexes);

    return 0;
}


/*
fila *constroiFila (char **v, int n){
    int i;
    fila *f = criaFila();
    item t;

    for (i = 0; i < n; i++){
        t = criaItem(v, n, i);
        insereFila(f, t);
    }
}

item criaItem (char **v, int n, int i){
    item x;
    x->chave = v[i];
    if (2*i <= n)
        x->esq = v[2*i];
    else
        x->esq = NULL;
    
    if (2*i + 1 <= n)
        x->dir = v[2*i + 1];
    else
        x->dir = NULL;

    return x;
}*/