#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

/* compiling
gcc -Wall -ansi -pedantic -O2 *.c -o a
*/

#define MAXWORD 12


int main(){
    /*Inicialização*/
    char **words;
    int nwords=0, i=0;   
    /*char buffer[MAXWORD];*/

    char **words_insertion;
    char **words_merge;
    char **words_quick;
    int *indexes_quick;
    char **words_heap;


    FILE *randomwords;
    randomwords = fopen("randomwords.txt", "r");
    if (randomwords == NULL){
        printf("failed to open file. exiting now.\n");
        return 1;
    }
    /*printf("How many words? ");
    scanf("%d", &nwords);*/

    fscanf(randomwords, "%d", &nwords);
    printf("%d words\n", nwords);

    words = malloc(nwords * sizeof(char *));
    
    for(i = 0; i < nwords; i++){
        words[i] = malloc(MAXWORD * sizeof(char));
        /*scanf("%s", buffer);
        strcpy(words[i], buffer);*/
        /*scanf("%s", words[i]);*/
        fscanf(randomwords, "%s", words[i]);
    }

    printWords(words, nwords);

    fclose(randomwords);


    /*Ordenação*/

    printf("After insertion sort\n");
    words_insertion = copyWords(words, nwords);
    insertionSort(words_insertion, nwords);
    printf("comparações: %d\n", comparacoes_insertion);
    printf("trocas: %d\n", trocas_insertion);
    printWords(words_insertion, nwords);
    freeWords(words_insertion, nwords);
    
    printf("After merge sort\n");
    words_merge = copyWords(words, nwords);
	mergeSort(0, nwords-1, words_merge);
	printf("comparações: %d\n", comparacoes_merge);
	printf("trocas: %d\n", trocas_merge);
    printWords(words_merge, nwords);
    freeWords(words_merge, nwords);


    printf("After quick sort\n");
    words_quick = copyWords(words, nwords);
    indexes_quick = malloc(nwords * sizeof(int));
    for (i = 0; i < nwords; i++){
        indexes_quick[i] = i;
    }
	quickSort(words_quick, indexes_quick, 0, nwords-1);
    words_quick = remontaWords(words_quick, indexes_quick, nwords);
	printf("comparações: %d\n", comparacoes_quick);
	printf("trocas: %d\n", trocas_quick);
    printWords(words_quick, nwords);
    freeWords(words_quick, nwords);
    free(indexes_quick);

    /*
    printf("After heap sort\n");
    words_heap = copyWords(words, nwords);
	heapSort(words_heap, nwords);
    printWords(words_heap, nwords);
    freeWords(words_heap, nwords);
    */


    freeWords(words, nwords);

    return 0;
}



