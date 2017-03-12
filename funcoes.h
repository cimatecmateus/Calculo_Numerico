#ifndef _FUNCOES_H
#define _FUNCOES_H

#include <math.h>

char funcao[] = "xlog(x) - 1";

/* Método que retorna o valor da função analisada para um dado ponto */
float f(float x){    
      float func = x * log10(x) - 1;
      return func;
}      

/* Método que retorna o valor da derivada da função analisada para um dado ponto */
float fLinha(float x){
      float deriva = log10(x) + 1;
      return deriva;
}

#endif