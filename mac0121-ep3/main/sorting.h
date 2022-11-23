#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 11
#define NWORDS 250

extern int comparacoes;
extern int trocas;

void printWords(char **words, int nwords);
char **copyWords (char **words, int nwords);
void freeWords (char **words, int nwords);
void writeWords (char **words ,int nwords);


void insertionSort (char **A, int n);

void merge (int ini, int meio, int fim, char **v);
void mergeSort (int meio, int fim, char **v);

void trocaQuick (int *indexes, int i, int j);
int particiona (char **v, int *indexes, int ini, int fim);
void quickSort (char **v, int *indexes, int ini, int fim);
char **remontaWords (char **original, int *indexes, int nwords);

void heapSort (char **v, int *indexes, int n);
void heapfica (char **v, int *indexes, int n, int i);
void trocaHeap (int *indexes, int i, int j);