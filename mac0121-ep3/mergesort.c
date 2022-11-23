
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"
#define MAXWORD 12

/* compiling
gcc -Wall -ansi -pedantic -O2 mergesort.c sorting.c -o a
*/

int main(){
    /*Inicialização*/
    char **words;
    int nwords=0, i=0;   

    char **words_merge;

    FILE *randomwords;
    randomwords = fopen("randomwords.txt", "r");
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

    /*Ordenação*/
    printf("After merge sort\n");
	mergeSort(0, nwords-1, words);
	printf("comparações: %d\n", comparacoes_merge);
	printf("trocas: %d\n", trocas_merge);
    printWords(words, nwords);
    freeWords(words, nwords);

    return 0;
}



