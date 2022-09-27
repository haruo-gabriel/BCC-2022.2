#include <stdio.h>
#include <stdlib.h>

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

void imprimeMatriz (int **a, int m, int n) {
    int i,j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++) printf("+---");
        printf("+\n");
        for (j = 0; j <n; j++)
          if(a[i][j] != 0) printf("|%3d", a[i][j]);
            else printf("|   ");
        printf("|\n");
    }
    for (j = 0; j < n; j++) printf("+---");
    printf("+\n");
}
