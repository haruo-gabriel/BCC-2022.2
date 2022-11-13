#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* compiling
gcc -Wall -ansi -pedantic -O0 -g main.c -o a
*/


void printWords(char **words, int nwords);
void insertionSort (char **A, int n);

int main(){
    /* Inicialização das palavras */
    char **words;
    int nwords=0, i=0;   
    char buffer[12];

    printf("How many words? ");
    scanf("%d", &nwords);

    words = malloc(nwords * sizeof(char *));

    for(i = 0; i < nwords; i++){
        words[i] = malloc(12 * sizeof(char));
        /*scanf("%s", buffer);
        strcpy(words[i], buffer);*/
        scanf("%s", words[i]);
    }

    printWords(words, nwords);

    /* Ordenação */
    insertionSort(words, nwords);
    printf("After insertion sort\n");
    printWords(words, nwords);

	mergeSort(words, nwords);
    printf("After merge sort\n");
    printWords(words, nwords);


	quickSort(words, nwords);
    printf("After quick sort\n");
    printWords(words, nwords);
	
	heapSort(words, nwords);
    printf("After heap sort\n");
    printWords(words, nwords);



    /* free */
    for (i = 0; i < nwords; i++){
        free(words[i]);
    }
    free(words);

    return 0;
}

void printWords(char **words, int nwords){
    int i;
    for (i = 0; i < nwords; i++){
        printf("Word[%d] = %s\n", i+1, words[i]);
        printf("\n");
    }
    printf("\n");
}

void insertionSort (char **A, int n) {
  int i, j, comparacoes=0;
  char *chave;
  chave = malloc(12 * sizeof(char));
  /* a cada iteração, teremos o vetor A[1..i] ordenado */
  /* começamos de A[i], porque obviamente o vetor em A[0..0] está 
     trivialmente ordenado */
     
  for (i = 1; i < n; i++) {
    strcpy(chave, A[i]);
    j = i - 1;

    /* encontra a posicao correta de chave (A[i]) no vetor A[0..i-1] */
    while (j >= 0 && strcmp(A[j], chave) > 0 /*A[j] > chave*/) {
      strcpy(A[j+1], A[j]); /*A[j + 1] = A[j];*/
      comparacoes++;
      j = j - 1;
    }
	strcpy(A[j+1], chave);
  }
}