#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

#define MAXWORD 12


int comparacoes_insertion = 0;
int trocas_insertion = 0;

int comparacoes_merge = 0;
int trocas_merge = 0;

int comparacoes_quick = 0;
int trocas_quick = 0;

int comparacoes_heap = 0;
int trocas_heap = 0;

/*Imprime todas as strings em um array de strings*/
void printWords(char **words, int nwords){
    int i;
    for (i = 0; i < nwords; i++){
        printf("Word[%d] = %s\n", i, words[i]);
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

/*insertion sort*/
void insertionSort (char **A, int n) {
    int i, j;
    char *chave = malloc(12 * sizeof(char));

    for(i = 1; i < n; i++){
    	strcpy(chave, A[i]);
		j = i - 1;

		while (j >= 0 && strcmp(A[j], chave) > 0) {
			comparacoes_insertion++;
			strcpy(A[j+1], A[j]);
			trocas_insertion++;
			j = j - 1;
     	}
		comparacoes_insertion++;
    	
		strcpy(A[j+1], chave);
		trocas_insertion++;
    }

	free(chave);

    printf("comparações: %d\n", comparacoes_insertion);
    printf("trocas: %d\n", trocas_insertion);
}





/* merge sort */
/* A função recebe vetores crescentes v[p, ... ,q]  e v[q+1, ... ,r] e rearranja v[p, ... ,r] em ordem crescente */
void merge (int p, int q, int r, char **v){
	char **A, **B;                     
	int i, j, k, n1 = q - p + 1, n2 = r - q;

	/* montando os vetores auxiliares */
	A = malloc (n1 * sizeof(char *));
    for(i = 0; i < n1; i++){
        A[i] = malloc(MAXWORD * sizeof(char));
	}
	for (i = 0; i < n1; i++){
		strcpy(A[i], v[p+i]);
    }

	B = malloc (n2 * sizeof(char *));    
    for(i = 0; i < n1; i++){
        B[i] = malloc(MAXWORD * sizeof(char));
	}
	for (i = 0; i < n2; i++){
		strcpy(B[i], v[q+1+i]);
	}

	/* mesclando os vetores auxiliares */
	i = 0, j = 0; k = p;
	while (i < n1 && j < n2) {
		comparacoes_merge++;       
		if (strcmp(A[i], B[j]) <= 0){
			strcpy(v[k], A[i++]);
			trocas_merge++;
		}
		else{
			strcpy(v[k], B[j++]);
			trocas_merge++;
		}
		k++;
	}

	/* adição final dos elementos que sobraram nos vetores auxiliares */
	while (i < n1)
		strcpy(v[k++], A[i++]);
      
	while (j < n2)
		strcpy(v[k++], B[j++]);

	/* free */
	for (i = 0; i < n1; i++)
		free(A[i]);
	free(A);

	for (i = 0; i < n2; i++)
		free(B[i]);
	free(B);
}


/* A função mergesort rearranja o vetor v[p..r] em ordem crescente. */
void mergeSort (int p, int r, char **v) {
	int q;
  
	if (p < r) {                 
    	q = (p + r)/2;         
    	mergeSort(p, q, v);       
   		mergeSort(q+1, r, v);       
    	merge(p, q, r, v);    
  	}

}




/* quick sort*/
void troca (char **v, int i, int j){
	char *aux = malloc(MAXWORD * sizeof(char));
	strcpy(aux, v[j]);
	strcpy(v[j], v[i]);
	strcpy(v[i], aux);
    free(aux);
}


int particiona (char **v, int ini, int fim) {
	int i, j;
    char *x;

	i = ini;
	j = fim+1;
    x = v[ini];

    /* separa os elementos maiores e menores que o pivo */
	while(1){
		while(strcmp(v[++i], x) < 0)
			if (i == fim)
	            break;
		while(strcmp(v[--j], x) > 0)
			if (j == ini)
            	break;
		if (i >= j)
			break;
		troca(v, i, j);
	}

    /* coloca o pivo no lugar certo */
	troca(v, ini, j);
    
	return j;
}

void quickSort (char **v, int ini, int fim) {
	int x;

	if (ini < fim){
		x = particiona(v, ini, fim);
		quickSort(v, ini, x - 1);
		quickSort(v, x + 1, fim);
	}
}