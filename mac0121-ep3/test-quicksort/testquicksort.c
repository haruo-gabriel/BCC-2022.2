
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* compiling
gcc -Wall -ansi -pedantic -O0 -g *.c -o a
*/

#define MAXWORD 12

void printWords(char **words, int nwords);
char **copyWords (char **words, int nwords);
void freeWords (char **words, int nwords);

void troca (int *indexes, int i, int j);
int particiona (char **v, int *indexes, int ini, int fim);
void quickSort (char **v, int *indexes, int ini, int fim);
char **remontaWords (char **original, int *indexes, int nwords);


int main(){
    /*Inicialização*/
    char **words;
    int nwords=0, i=0;   
    /*char buffer[MAXWORD];*/

    char **words_quick;
    int *indexes_quick;

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

    printf("After quick sort\n");
    words_quick = copyWords(words, nwords);
    indexes_quick = malloc(nwords * sizeof(int));
    for (i = 0; i < nwords; i++){
        indexes_quick[i] = i;
    }
	quickSort(words_quick, indexes_quick, 0, nwords-1);
    words_quick = remontaWords(words_quick, indexes_quick, nwords);
    printWords(words_quick, nwords);
    freeWords(words_quick, nwords);
    free(indexes_quick);


    freeWords(words, nwords);

    return 0;
}



/*Imprime todas as strings em um array de strings*/
void printWords(char **words, int nwords){
    int i;
    for (i = 0; i < nwords; i++){
        printf("word[%d] = %s\n", i, words[i]);
    }
    printf("\n");
}

/*Copia um array de strings para outros endereços de memória*/
char **copyWords (char **words, int nwords){
	int i;
	char **wordscpy;
	wordscpy = malloc(nwords * sizeof(char *));

	for(i = 0; i < nwords; i++){
		wordscpy[i] = malloc(MAXWORD * sizeof(char));
		strcpy(wordscpy[i], words[i]);
	}

	return wordscpy;
}

/*Dá free em um array de strings, alocados dinamicamente*/
void freeWords (char **words, int nwords){
	int i;
	for (i = 0; i < nwords; i++){
		free(words[i]);
	}
	free(words);
}



/* quick sort com ordenação indireta */
void troca (int *indexes, int i, int j){
    int aux;
    aux = indexes[i];
    indexes[i] = indexes[j];
    indexes[j] = aux;
}


int particiona (char **v, int *indexes, int ini, int fim) {
	int i, j;
    char *x;

	i = ini;
	j = fim+1;
    x = v[indexes[ini]];

    /* separa os elementos maiores e menores que o pivo */
	while(1){
		while(strcmp(v[indexes[++i]], x) < 0){
			if (i == fim)
	            break;
        }

		while(strcmp(v[indexes[--j]], x) > 0)
			if (j == ini)
            	break;
		if (i >= j)
			break;
		troca(indexes, i, j);
	}

    /* coloca o pivo no lugar certo */
	troca(indexes, ini, j);
    
	return j;
}

void quickSort (char **v, int *indexes, int ini, int fim) {
	int x;

	if (ini < fim){
		x = particiona(v, indexes, ini, fim);
		quickSort(v, indexes, ini, x - 1);
		quickSort(v, indexes, x + 1, fim);
	}
}

char **remontaWords (char **original, int *indexes, int nwords){
    int i;
    char **ordenado;

    ordenado = malloc(nwords * sizeof(char *));
    for (i = 0; i < nwords; i++)
        ordenado[i] = malloc(MAXWORD * sizeof(char));

    for (i = 0; i < nwords; i++)
        strcpy(ordenado[i], original[indexes[i]]);

    for (i = 0; i < nwords; i++)
		free(original[i]);
	free(original);

    return ordenado;
}