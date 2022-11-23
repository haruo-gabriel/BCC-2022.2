#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sorting.h"

/* compiling
gcc -Wall -ansi -pedantic -O2 heapsort.c sorting.c -o a
*/


int main(){
    /*Inicialização*/
    char **words;
    int i, j;
    int *indexes;

    /*Leitura das palavras aleatórias e alocação*/
    FILE *randomwords = fopen("../worddata/randomwords.txt", "r");
    if (randomwords == NULL){
        printf("failed to open file. aborting now.\n");
        return 1;
    }
    words = malloc(NWORDS * sizeof(char *));
    for(i = 0; i < NWORDS; i++){
        words[i] = malloc(MAXWORD * sizeof(char));
        j = fscanf(randomwords, "%s", words[i]);
        if (j != 1){
            printf("error reading word. aborting now.\n");
            return 1;
        }
    }
    fclose(randomwords);

    printWords(words, NWORDS);

    /*Alocação do vetor auxiliar de índices*/
    indexes = malloc(NWORDS * sizeof(int));
    for (i = 0; i < NWORDS; i++){
        indexes[i] = i;
    }

    /*Ordenação*/
    printf("After heap sort\n");
	heapSort(words, indexes, NWORDS);
    words = remontaWords(words, indexes, NWORDS);
	printf("comparações: %d\n", comparacoes);
	printf("trocas: %d\n", trocas);
    printWords(words, NWORDS);

    writeWords(words, nwords);
    
    /*FREE*/
    freeWords(words, NWORDS);
    free(indexes);

    return 0;
}
