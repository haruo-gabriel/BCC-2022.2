int ** alocaMatriz (int lin, int col);
char **alocaMatrizChar (int lin, int col);
void liberaMatriz (int ** mat, int lin);
void imprimeMatriz (int **a, int m, int n);
void imprimeMatrizChar (char **a, int m, int n);
/*void leMatriz (int **matriz, int linhas, int colunas);*/
void leMatriz (char **matriz, int linhas, int colunas);
void transfereMatrizMatrizChar(int **matriz, char **matrizChar, int m, int n);