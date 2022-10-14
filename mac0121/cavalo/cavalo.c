/* 

Faça uma função 

void cavalo (int n, int l, int c); 

que verifica se, partindo da posição (l,c) de um tabuleiro nxn, 
é possível, com n^2 - 1 pulos, cobrir todas as posições do 
tabuleiro. Neste caso, imprime a sequência de pulos.  

*/
#include <stdio.h>
#include <stdlib.h> 
#include "pilha.h"
#include "matriz.h"



cavalo proximo (cavalo atual) {
  cavalo prox;

  /* temos 8 movimentos posicoes, o 1, 2, 3, ..., 8 ,
     correspondendo a essas posicoes nos vetores abaixo */
  int plinha[9] = {0, -2, -1, 1, 2,  2,  1, -1, -2};
  int pcoluna[9] = {0,  1,  2, 2, 1, -1, -2, -2, -1};

  prox.lin = atual.lin + plinha[atual.mov];
  prox.col = atual.col + pcoluna[atual.mov];
  prox.mov = 1;
  return prox; 
} 

int puloValido (int ** tab, int n, cavalo x) {
  cavalo prox = proximo(x);
  if (prox.lin >= 0 && prox.col >= 0 &&
      prox.lin < n && prox.col < n &&
      tab[prox.lin][prox.col] == 0)
    return 1;
  return 0;
} 

void passeioCavalo (int n, int lin, int col) {
  pilha *posicoes = cria (n * n);
  cavalo atual; 
  int **tab = alocaMatriz (n, n);
  int i, j, ok, npulos;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      tab[i][j] = 0;

  atual.lin = lin;
  atual.col = col;
  atual.mov = 1;
  npulos = 0;

  while (npulos < n * n - 1) {
    ok = 0;
    while (!ok && atual.mov <= 8){
      if (puloValido (tab, n, atual))
	ok = 1;
      else
	atual.mov++;
    } 
    if (ok) {
      npulos++;
      empilha (posicoes, atual);
      tab[atual.lin][atual.col] = npulos;
      atual = proximo(atual);
    }
    else { /* backtrack */
      if (pilhaVazia (posicoes)) {
	printf("Não tem passeio do cavalo :-(\n");
	liberaMatriz (tab, n);
	destroi (posicoes);
	return;
      }
      atual = desempilha (posicoes);
      tab[atual.lin][atual.col] = 0;
      atual.mov++;
      npulos--;
    }
  }
  npulos++;
  tab[atual.lin][atual.col] = npulos; 
  
  imprimeMatriz (tab, n, n);
  liberaMatriz (tab, n);
  destroi (posicoes); 
} 

int main(int argc, char *argv[]) {
  int l, c, n;
  n = atoi(argv[1]);
  l = atoi(argv[2]);
  c = atoi(argv[3]);
   
  passeioCavalo(n, l, c); 
  return 0;
} 
   
