#include <stdio.h>
#include <stdlib.h>

int ** alocaMatriz (int lin, int col) {
  int ** mat = malloc (lin * sizeof(int *));
  int i;
  for (i = 0; i < lin; i++)
    mat[i] = malloc (col * sizeof(int));
  return (mat);
}

char ** alocaMatrizChar (int lin, int col) {
  char ** mat = malloc (lin * sizeof(char *));
  int i;
  for (i = 0; i < lin; i++)
    mat[i] = malloc (col * sizeof(char));
  return (mat);
}

void liberaMatriz (int ** mat, int lin){
  int i;
  for (i = 0; i < lin; i++)
    free(mat[i]);
  free (mat);
}

void liberaMatrizChar (char ** mat, int lin){
  int i;
  for (i = 0; i < lin; i++)
    free(mat[i]);
  free (mat);
}

void imprimeMatriz (int **a, int m, int n) {
    int i,j;
    for (i = 0; i < m; i++){
      for (j = 0; j < n; j++)
        printf("+---");
      printf("+\n");
      for (j = 0; j <n; j++)
        if(a[i][j] != 0) printf("|%3d", a[i][j]);
        else printf("|   ");
      printf("|\n");
    }
    for (j = 0; j < n; j++)
      printf("+---");
    printf("+\n");
}

void imprimeMatrizChar (char **a, int m, int n) {
  int i,j;
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++){
      printf("%c", m[i][j]);
    }
    printf("\n");
  }
}

/*
void leMatriz (int **matriz, int linhas, int colunas){
  int i, j;  
  for (i = 0; i < linhas; i++)
    for (j = 0; j < colunas; j++)
      scanf("%d", &matriz[i][j]);  
}
*/

void leMatriz (char **matriz, int linhas, int colunas){
  int i, j, aux;  
  for (i = 0; i < linhas; i++)
    for (j = 0; j < colunas; j++){
      scanf("%d", &aux);
      if (aux == 0)
        matriz[i][j] = '0';
      else
        matriz[i][j]; = '*';
    }
}

/* Transfere os -1's da matriz numerica para a matriz de caracteres como *'s
s */
void transfereMatrizMatrizChar(int **matriz, char **matrizChar, int m, int n){
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++){
      if (matriz[i][j] == -1)
        matrizChar[i][j] = '*';
      else
        matrizChar[i][j] = '0'; 
    }
}