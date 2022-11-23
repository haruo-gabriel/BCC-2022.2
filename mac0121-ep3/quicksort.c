
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

/* compiling
gcc -Wall -ansi -pedantic -O2 -g quicksort.c sorting.c -o a
*/

#define MAXWORD 12

int main(){
    /*Inicialização*/
    char **words;
    int *indexes;
    int nwords=0, i=0;   

    FILE *randomwords;
    randomwords = fopen("../randomwords.txt", "r");
    if (randomwords == NULL){
        printf("failed to open file. exiting now.\n");
        return 1;
    }

    fscanf(randomwords, "%d", &nwords);
    printf("%d words\n", nwords);

    words = malloc(nwords * sizeof(char *));
    
    for(i = 0; i < nwords; i++){
        words[i] = malloc(MAXWORD * sizeof(char));
        fscanf(randomwords, "%s", words[i]);
    }

    printWords(words, nwords);

    fclose(randomwords);

    indexes = malloc(nwords * sizeof(int));
    for (i = 0; i < nwords; i++)
        indexes[i] = i;

    /*Ordenação*/
    printf("After quick sort\n");
	quickSort(words, indexes, 0, nwords-1);
    words = remontaWords(words, indexes, nwords);
	printf("comparações: %d\n", comparacoes_quick);
	printf("trocas: %d\n", trocas_quick);
    printWords(words, nwords);
    freeWords(words, nwords);
    free(indexes);

    return 0;
}



