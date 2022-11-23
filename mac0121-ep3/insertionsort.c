#include "sorting.h"

/* compiling
gcc -Wall -ansi -pedantic -O2 insertionsort.c sorting.c -o a
*/

int main(){
    /*Inicialização*/
    char **words;
    int i, j;

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

    /*Ordenação*/
    printf("After insertion sort\n");
    insertionSort(words, NWORDS);
    printf("comparações: %d\n", comparacoes);
    printf("trocas: %d\n", trocas);
    printWords(words, NWORDS);
    
    /*FREE*/
    freeWords(words, NWORDS);    

    return 0;
}



