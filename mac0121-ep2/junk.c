int cruzada(){
    for (i = 0; i < m; i++){
	    for (j = 0; j < n; j++){
            if (!valido(matriz[i][j]))
        }
    }
}

/* Percorrendo a matriz linha a linha */
for (i = 0; i < m; i++){
	for (j = 0; j < n; j++){
		if (matriz[i][j] == 0){ /* Procedimento para o primeiro caso de matriz[i][j] == 0 */
			if (j < n - 1 && matriz[i][j+1] == 0){
				tamanhoLinha = contaTamanhoLinha(matriz, n, i, j);
				
				encaixaPalavraLinha(tamanhoLinha);

				for (l = j; l < j + tamanhoLinha; l++){
					contaTamanhoColuna()
					encaixaPalavraColuna()
					procuraPalavra()
				}

			}
			else if (i < m - 1 && matriz[i+1][j] == 0){
				tamanhoColuna = contaTamanhoColuna(matriz, m, i, j);
			}
		}
	}
}


/* Conta o espaco disponivel na linha ate um -1 ou ate a linha acabar */
int contaTamanhoLinha(int **matriz, int colunas, int linhaAtual, int colunaAtual){
    int j, tamanho;
    
    tamanho = 0;

    for (j = colunaAtual; j < colunas; j++)
        if (matriz[linhaAtual][j] != -1){
            tamanho++;
			break;
		}

	return tamanho;
}

/* Procura uma palavra com um tamanho especifico */
palavra procuraPalavra(int tamanhoLivre, vocab voc, int nPalavras){
	palavra *p;

	/* Buscando em vocab alguma palavra com tamanho especifico */
	for (i = 0; i < nPalavras; i++ ){
		if (voc->v[0]->)
			return palavra;
	}
}

/* Muda os valores das celulas da matriz que serao ocupadas pela palavra
e atualiza a posicao da palavra */
void encaixaPalavraColuna(int **matriz){

	p = procuraPalavra(tamanhoLivre, )

	for (i = linhaAtual; i < linhaAtual + tamanhoLinha; i++){
	}

}

/* Conta o espaco disponivel na coluna ate um -1 ou ate a coluna acabar */
int contaTamanhoColuna(int **matriz, int linhas, int linhaAtual, int colunaAtual){
    int i, tamanho;
    
    tamanho = 0;

    for (i = linhaAtual; i < linhas; i++)
        if (matriz[i][colunaAtual] != -1){
            tamanho++;
			break
		}

	return tamanho;
}