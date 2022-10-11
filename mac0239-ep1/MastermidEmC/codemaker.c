#include <stdlib.h>

#include "codebreaker.h"
#include "codemaker.h"

struct CODIGO _codigo;

void  cria_CodeMaker(int nslots, int ncolors) {
  _codigo.nslots = nslots;
  _codigo.ncolors= ncolors;
  _codigo.codigo = malloc(nslots*sizeof(int));

  for(int i=0;i<nslots ;i++)
     _codigo.codigo[i]=rand()%ncolors;

  printCodigo(_codigo.codigo, nslots);
  
}

void printCodigo(int c[], int n){
  printf("Código: [ ");
  for( int i = 0; i < n; i++ ) {
    printf("%d ", c[i] );
  }
  printf("]\n");
}

int* codemaker_feedback( int* guess) {
  int* feedback_answer;
  
  feedback_answer = malloc( _codigo.nslots*sizeof(int) );
  
  for( int i=0; i<_codigo.nslots; i++ ) {
    if (guess[i] == _codigo.codigo[i])
      feedback_answer[i] = 1;
    
    else{
      feedback_answer[i] = 0;
      for (int j = 0; j < _codigo.nslots; j++){
        if (guess[j] == _codigo.codigo[j]){
          feedback_answer[i] = 2;
          break;
        }
      }
    }
  }
  //printf("Feedback: ");
  //printCodigo( feedback_answer, _codigo.nslots );
  
  return feedback_answer;
}

void  mata_CodeMaker() {
  free(_codigo.codigo);
}
