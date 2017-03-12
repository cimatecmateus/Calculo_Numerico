#ifndef _FUNCOES_H
#define _FUNCOES_H

#include <math.h>

/* Método que retorna o valor da função analisada para um dado ponto */
float f(float x){    
      float func = pow(x,2) + x - 6;
      return func;
}      

/* Método que retorna o valor da derivada da função analisada para um dado ponto */
float fLinha(float x){
      float deriva = 2*x + 1;
      return deriva;
} 

#endif