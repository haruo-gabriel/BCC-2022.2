#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

#define MAXWORD 11
#define NWORDS 250

int comparacoes = 0;
int trocas = 0;

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

void writeWords (char **words ,int nwords){
	int i;
    char buf[0x100];
	FILE *sortedwords;

    sortedwords = fopen(buf, "w");
    if (sortedwords == NULL){
        printf("error while opening write file. aborting now.\n");
    }

    snprintf(buf, sizeof(buf), "../worddata/sortedwords%d.txt", NWORDS);
	fprintf(sortedwords, "%d\n", nwords);

	for (i = 0; i < nwords; i++){
		if (i == nwords - 1)
			fprintf(sortedwords, "%s", words[i]);
		else
			fprintf(sortedwords, "%s\n", words[i]);
	}

	fclose(sortedwords);
}

void trocaIndices (int *indexes, int i, int j){
    int aux;
    aux = indexes[i];
    indexes[i] = indexes[j];
    indexes[j] = aux;
	trocas++;
}



/*INSERTION SORT*/
void insertionSort (char **words, int nwords) {
    int i, j;
    char *chave = malloc(MAXWORD * sizeof(char));

    for(i = 1; i < nwords; i++){
    	chave = words[i];
		j = i - 1;

		while (j >= 0 && strcmp(words[j], chave) > 0) {
			comparacoes++;
			words[j+1] = words[j];
			trocas++;
			j = j - 1;
     	}
		comparacoes++;
    	
		words[j+1] = chave;
    }
}





/*MERGE SORT*/
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
    for(i = 0; i < n2; i++){
        B[i] = malloc(MAXWORD * sizeof(char));
	}
	for (i = 0; i < n2; i++){
		strcpy(B[i], v[q+1+i]);
	}

	/* mesclando os vetores auxiliares */
	i = 0, j = 0; k = p;
	while (i < n1 && j < n2) {
		comparacoes++;       
		if (strcmp(A[i], B[j]) <= 0){
			strcpy(v[k], A[i++]);
		}
		else{
			strcpy(v[k], B[j++]);
			trocas++;
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

void mergeSort (int ini, int fim, char **v) {
	int meio;
  
	if (ini < fim) {                 
    	meio = (ini + fim)/2;         
    	mergeSort(ini, meio, v); 
   		mergeSort(meio+1, fim, v);
    	merge(ini, meio, fim, v);
  	}
}





/*QUICK SORT com ordenação indireta*/
int particiona (char **v, int *indexes, int ini, int fim) {
	int i, j;
    char *x;

	i = ini;
	j = fim+1;
    x = v[indexes[ini]];

    /* separa os elementos maiores e menores que o pivo */
	while(1){
		while(strcmp(v[indexes[++i]], x) < 0){
			comparacoes++;
			if (i == fim)
	            break;
        }
		comparacoes++;

		while(strcmp(v[indexes[--j]], x) > 0){
			comparacoes++;
			if (j == ini)
            	break;
		}
		comparacoes++;

		if (i >= j)
			break;

		trocaIndices(indexes, i, j);
	}

    /* coloca o pivo no lugar certo */
	trocaIndices(indexes, ini, j);
    
	return j;
}

void quickSort (char **v, int *indexes, int ini, int fim) {
	int meio;

	if (ini < fim){
		meio = particiona(v, indexes, ini, fim);
		quickSort(v, indexes, ini, meio - 1);
		quickSort(v, indexes, meio + 1, fim);
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





/*HEAP SORT com ordenação indireta*/
void heapSort (char **v, int *indexes, int n){
    int i;

    /*transforma vetor em max heap*/
    for (i = n/2 - 1; i >= 0; i--)
        heapfica (v, indexes, n, i);

    /*ordena*/
    for (i = n - 1; i >= 0; i--){
        trocaIndices(indexes, 0, i);
        heapfica(v, indexes, i, 0);
    }
}

void heapfica (char **v, int *indexes, int n, int i){
    int maior = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;
    
	comparacoes++;
    if (esq < n && strcmp(v[indexes[esq]], v[indexes[maior]]) > 0){
        maior = esq;
	}
    
	comparacoes++;
    if (dir < n && strcmp(v[indexes[dir]], v[indexes[maior]]) > 0){
        maior = dir;
	}

	comparacoes++;
    if (maior != i){
        trocaIndices(indexes, i, maior);
        heapfica(v, indexes, n, maior);
    }
}
