# Como compilar
```C
gcc -Wall -ansi -pedantic -O2 *.c -o a.out
a.out < texto.txt
```

# Esqueleto do programa
1. Criar uma árvore binária de busca
   - A chave é a palavra
   - O conteúdo é o número das linhas em que essa palavra aparece e a quantidade de ocorrências em uma linha
2. Ler as linhas do texto.
3. Atualizar a árvore binária de busca de acordo com os inputs das palavras.
4. Imprimir o índice remissivo.

# Structs implementadas
```C
typedef struct celABB {
    char *chave;
    no *esq;
    no *dir;
    int *linhas;
    int *contLinha;
} noABB;

typedef struct celIND {
    int linha;
    int cont;
    struct celIND prox;
} noIND;
```

implementar uma árvore binária de busca para o índice de cada palavra também?