#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "abb.h"

/* Funções de construção das ABB's */
noABB *insereABB (noABB *raiz, char *palavra, int linha){
    /* se a palavra ainda não existe na ABB */
    if (raiz == NULL){ 
        raiz = malloc (sizeof(noABB));

        raiz->chave = malloc(strlen(palavra) + 1);
        strcpy(raiz->chave, palavra);

        raiz->dir = raiz->esq = NULL;

        raiz->info = NULL;
        raiz->info = insereLinhas(raiz->info, linha);

        return raiz;
    }

    /* se a palavra já existe na ABB */
    if (strcmp(palavra, raiz->chave) == 0)
        raiz->info = insereLinhas(raiz->info, linha);
    else if (strcmp(palavra, raiz->chave) < 0)
        raiz->esq = insereABB(raiz->esq, palavra, linha);
    else /*if (strcmp(palavra, raiz->chave) > 0)*/
        raiz->dir = insereABB(raiz->dir, palavra, linha);

    return raiz;
}


noIND *insereLinhas (noIND *info, int linha){
    /* se a linha ainda não existe no index da palavra */
    if (info == NULL){ 
        info = malloc(sizeof(noIND));
        info->linha = linha;
        info->cont = 1; 
        info->dir = info->esq = NULL;
        return info;
    }
    /* se a linha já existe no index da palavra */
    else if (info->linha == linha)
       info->cont++; 
    else if (linha < info->linha)
        info->esq = insereLinhas(info->esq, linha);
    else /*if (linha > info->linha)*/
        info->dir =  insereLinhas(info->dir, linha);
    return info;
}


/* Funções de impressão das ABB's */
void inordemABB (noABB *raiz) {
    if (raiz != NULL){
        inordemABB(raiz->esq);

        printf("%s: ", raiz->chave);
        inordemIND(raiz->info);
        printf("\n");

        inordemABB(raiz->dir);
    }
}

void inordemIND (noIND *info) {
    if (info != NULL){
        inordemIND(info->esq);

        if (info->cont > 1)
            printf("%d(%d) ", info->linha, info->cont);
        else
            printf("%d ", info->linha);

        inordemIND(info->dir);
    }
}


/* Funções desalocação de memória */
void destroiABB (noABB *raiz){
    if (raiz != NULL){
        destroiABB(raiz->esq);
        destroiABB(raiz->dir);

        free(raiz->chave);
        destroiIND(raiz->info);
        free(raiz);
    }
}

void destroiIND (noIND *info){
    if (info != NULL){
        destroiIND(info->esq);
        destroiIND(info->dir);
        free(info);
    }
}