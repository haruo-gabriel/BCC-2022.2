# Skip Lists

- Estrutura de dados ordenada e probabilística
- Generalização das listas ligadas

## Estrutura geral
Lista ligada convencional (cada célula tem um ponteiro para o próximo elemento).
Diff: Há células que possuem mais de um ponteiro, com o objetivo de "pular" elementos da lista e fazer uma busca mais rápida.

## Probabilidades
> Qual a lógica para decidir quais células tem mais ponteiros?
- n nós tem pelo menos 1 ponteiro
- n/t nós tem pelo menos 2 ponteiros
- n/t^2 nós tem pelo menos 3 ponteiros
...
Generalização: a probabilidade de um nó ter j+1 ponteiros é 1/t^j
