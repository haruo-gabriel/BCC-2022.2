
#include <stdio.h>
#include <stdlib.h> 
#include "pilha.h"


int ** alocaMatriz (int lin, int col) {
  int ** mat = malloc (lin * sizeof(int *));
  int i;
  for (i = 0; i < lin; i++)
    mat[i] = malloc (col * sizeof(int));
  return (mat);
}


void liberaMatriz (int ** mat, int lin){
  int i;
  for (i = 0; i < lin; i++) free(mat[i]);
  free (mat);
}


void imprimeMatriz (int **mat, int lin, int col) {
  int i, j;
  for (i = 0; i < lin; i++){
    for (j = 0; j < col; j++)
      if (mat[i][j] == 1)
	printf("R");
      else
	printf(" ");
    printf("\n");
  }
  printf("\n");
}


int posicaoLivre (int **mat, int n, int lin, int col){
  int livre = 1, i, j;
  for (i = 0; i < n; i++)
    if (mat[i][col] == 1)
      livre = 0;
  /* verifica as diagonais */
  for (i = 0; i < lin; i++){
    j = (col - lin) + i;
    if (j >= 0 && mat[i][j] == 1)
      livre = 0;
    j = (col + lin) - i;
    if (j < n && mat[i][j] == 1)
      livre = 0;
  }
  return livre;
} 


void nRainhas (int n, int flag) {
  pilha * pos = cria();
  int ** tab = alocaMatriz (n, n);
  int total, valido, rainha, col, i, j, ok;
  total = 0;
  
  /* Inicializa o tabuleiro */
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      tab[i][j] = 0;
    }
  }
  
  rainha = 0;
  col = 0;
  valido = 0;
  ok = 1;
  
  while (ok) {
    valido = 0;
    
    while (col < n && rainha < n){
      if (posicaoLivre (tab, n, rainha, col)) {
        empilha (pos, col);
        tab[rainha][col] = 1;
        rainha++;
        col = 0;
        valido = 1;
      }
      else
	      col++;
    }

    /* se configuracao nao eh valida */
    if (!valido){
      /* se ja testou todas as configuracoes possiveis */
      if (pilhaVazia (pos)) 
	      break;
      else {
        rainha--;
        col = desempilha(pos);
        tab[rainha][col] = 0;
        col++;
      }
    }
   
    if (rainha == n) {
      if (flag)
	      imprimeMatriz (tab, n, n);
      rainha--;
      col = desempilha(pos);
      tab[rainha][col] = 0;
      col++;
      total++;
    }
  }

  destroi (pos);
  liberaMatriz (tab, n);
  printf("total = %d\n",total);
  
} 

int main() {
  int n, flag;
  printf ("Digite n e flag de impressao: ");
  scanf ("%d %d", &n, &flag);
  nRainhas (n, flag);
  return (0);
} 
  
