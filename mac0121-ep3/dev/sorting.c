#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* insertion sort*/
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





/* merge sort */
/* A função recebe vetores crescentes v[p..q]  e v[q+1..r]
   e rearranja v[p..r] em ordem crescente. */

void  intercala (int p, int q, int r, int v[])  {
  int n1, n2;
  int * A, * B;                     
  int i, j, k;

   
  n1 = q - p + 1;
  n2 = r - q;
  
  A = malloc (n1 * sizeof (int));      
  B = malloc (n2 * sizeof (int));      

  for (i = 0; i < n1; i++)
    A[i] = v[p+i];

  for (i = 0; i < n2; i++)
    B[i] = v[q+1 + i];

  
  i = 0, j = 0;
  k = p;
  while (i < n1 && j < n2) {                
    if (A[i] <= B[j])
      v[k] = A[i++];  
    else
      v[k] = B[j++];
    k++;
  }

  while (i < n1)
    v[k++] = A[i++];         
  while (j < n2)
    v[k++] = B[j++];

  free(A);
  free(B);
}


/* A função mergesort rearranja o vetor 
   v[p..r] em ordem crescente. */

void mergeSort (int p, int r, int v[]) {
  int q;
  
  if (p < r) {                 
    q = (p + r)/2;         
    mergeSort(p, q, v);       
    mergeSort(q+1, r, v);       
    intercala(p, q, r, v);    
  }
  
}




/* quick sort*/

void troca (int v[], int i, int j){
  int aux;
	 aux = v[j];
	 v[j] = v[i];
	 v[i] = aux;
}


int particiona (int v[], int ini, int fim) {
	int i, j, x;

	i = ini;
	j = fim+1;
	x = v[ini];
	while (1){
		while (v[++i] < x)
			if (i == fim)
	break;

		while (v[--j] > x)
			if (j == ini)
	break;

		if (i >= j)
			break;
		troca(v, i, j);
	}
	troca(v, ini, j);
	return j;
}

void quicksort (int v[], int ini, int fim) {
	int x;

	if (ini < fim){
		x = particiona(v, ini, fim);
		quicksort(v, ini, x - 1);
		quicksort(v, x + 1, fim);
	}
}
