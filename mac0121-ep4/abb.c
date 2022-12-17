#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "abb.h"

noABB *insereABB (no *raiz, char *palavra, int linha){
    int i;

    if (raiz == NULL){ /* se a palavra ainda não existe na ABB */
        raiz = malloc (sizeof(no));

        raiz->chave = malloc(strlen(palavra) + 1);
        strcpy(raiz->chave, palavra);

        raiz->dir = raiz->esq = NULL;

        raiz->info->linha = linha;
        raiz->info->cont = 1;
        raiz->info->prox = NULL;

        return raiz;
    }

    /* se a palavra já existe na ABB */
    if (strcmp(palavra, raiz->chave) == 0)
        raiz->info = insereLinhas(raiz->info, linha);
    else if (strcmp(palavra, raiz->chave) < 0)
        raiz->esq = insereABB(raiz->esq, palavra);
    else /*else if (strcmp(palavra, raiz->chave) > 0)*/
        raiz->dir = insereABB(raiz->dir, palavra);

    return raiz;
}


noIND insereLinhas (noIND *info, int linha){
    if (info == NULL){ /* se a linha ainda não existe no index da palavra */
        info = malloc(sizeof(noIND));
        info->linha = linha;
        info->cont = 1; 
        info->prox = NULL;
        return info;
    }
    
    if (info->linha == linha){ /* se a linha já existe no index da palavra */
       info->cont++; 
       return info;
    }
    else
        return insereLinhas(info->prox, linha);
}


noABB *buscaABB (no *raiz, char *palavra){
    if (raiz == NULL || strcmp(raiz->chave, palavra) == 0)
        return raiz;
    if (strcmp(palavra, raiz->chave) < 0)
        return busca(raiz->esq, palavra);
    /* else if (strcmp(palavra, raiz->chave) > 0) */
    return busca(raiz->dir, palavra);
}


void destroi (no *raiz){
    if (raiz != NULL){
        destroi(raiz->esq);
        destroi(raiz->dir);
        free(raiz);
    }
}


/* arrumar para as especificações do enunciado */
void preordem (no *raiz) {
    noIND *aux = NULL;

    if (raiz != NULL){
        printf("%s: ", raiz->chave);
        while (aux != NULL){
            printf("%d ", raiz->info->linha);
            if (raiz->info->cont > 1)
                printf("(%d) ", raiz->info->cont);
            aux = raiz->info->prox;
        }
        prinf("\n");
        preordem (raiz->esq);
        preordem (raiz->dir);
    }
}