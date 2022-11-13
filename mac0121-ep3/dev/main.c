#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

/* compiling
gcc -Wall -ansi -pedantic -O0 -g main.c -o a
*/

#define MAXWORD 12


int main(){
    /* Inicialização das palavras */
    char **words;
    int nwords=0, i=0;   
    /*char buffer[MAXWORD];*/

    char **words_insertion;
    char **words_merge;
    char **words_quick;
    char **words_heap;

    printf("How many words? ");
    scanf("%d", &nwords);

    words = malloc(nwords * sizeof(char *));

    for(i = 0; i < nwords; i++){
        words[i] = malloc(MAXWORD * sizeof(char));
        /*scanf("%s", buffer);
        strcpy(words[i], buffer);*/
        scanf("%s", words[i]);
    }

    printWords(words, nwords);


    /* Ordenação */

    printf("After insertion sort\n");
    words_insertion = copyWords(words, nwords);
    insertionSort(words_insertion, nwords);
    printWords(words_insertion, nwords);
    freeWords(words_insertion, nwords);
    
    printf("After merge sort\n");
    words_merge = copyWords(words, nwords);
	mergeSort(0, nwords-1, words_merge);
	printf("comparações: %d\n", comparacoes_merge);
	printf("trocas: %d\n", trocas_merge);
    printWords(words_merge, nwords);
    freeWords(words_merge, nwords);
    /*
    printf("After quick sort\n");
    words_quick = copyWords(words, nwords);
	quickSort(words_quick, 0, nwords-1);
    printWords(words_quick, nwords);
    freeWords(words_quick, nwords);
	*/
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



