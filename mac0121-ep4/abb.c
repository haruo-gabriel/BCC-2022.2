#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "abb.h"

noABB *insereABB (noABB *raiz, char *palavra, int linha){
    /* se a palavra ainda não existe na ABB */
    if (raiz == NULL){ 
        raiz = malloc (sizeof(noABB));

        raiz->chave = malloc(strlen(palavra) + 1);
        strcpy(raiz->chave, palavra);

        raiz->dir = raiz->esq = NULL;

        raiz->info = malloc(sizeof(noIND));
        raiz->info->linha = linha;
        raiz->info->cont = 1;
        raiz->info->esq = raiz->info->dir = NULL;

        return raiz;
    }

    /* se a palavra já existe na ABB */
    if (strcmp(palavra, raiz->chave) == 0)
        raiz->info = insereLinhas(raiz->info, linha);
    else if (strcmp(palavra, raiz->chave) < 0)
        raiz->esq = insereABB(raiz->esq, palavra, linha);
    else /*else if (strcmp(palavra, raiz->chave) > 0)*/
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
    if (info->linha == linha){ 
       info->cont++; 
       return info;
    }
    else if (info->linha < linha)
        return insereLinhas(info->esq, linha);
    else
        return insereLinhas(info->dir, linha);
}


noABB *buscaABB (noABB *raiz, char *palavra){
    if (raiz == NULL || strcmp(raiz->chave, palavra) == 0)
        return raiz;
    if (strcmp(palavra, raiz->chave) < 0)
        return buscaABB(raiz->esq, palavra);
    /* else if (strcmp(palavra, raiz->chave) > 0) */
    return buscaABB(raiz->dir, palavra);
}


void preordemABB (noABB *raiz) {
    if (raiz != NULL){
        printf("%s: ", raiz->chave);
        preordemIND(raiz->info);
        printf("\n");
        preordemABB(raiz->esq);
        preordemABB(raiz->dir);
    }
}


void preordemIND (noIND *raiz) {
    if (raiz != NULL){
        printf("%d ", raiz->linha);
        if (raiz->cont > 1)
            printf("(%d) ", raiz->cont);
        preordemIND(raiz->esq);
        preordemIND(raiz->dir);
    }
}

void destroi (noABB *raiz){
    if (raiz != NULL){
        destroi(raiz->esq);
        destroi(raiz->dir);

        free(raiz->info->esq);
        free(raiz->info->dir);
        free(raiz->info);
        free(raiz);
    }
}

