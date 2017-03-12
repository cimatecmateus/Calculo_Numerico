#ifndef _CORDAS_H
#define _CORDAS_H

#include "funcoes.h"

#define MAXIT 30 /*numero m�ximo de itera��es */
     
float metodoCordas(float a, float b, float tolerancia){

  int j;
  float fa, fb, xFixo, xProximo, xAtual, imagemFixa, imagemAtual;

    if(fa > 0){
      xFixo = a;
      xAtual = b;
      imagemFixa = fa;
    }
    else{
      xFixo = b;
      xAtual = a;
      imagemFixa = fb;
    }

    for(j = 1; j < MAXIT; j++){
      xProximo = xAtual - (f(xAtual)/(f(xAtual) - imagemFixa))*(xAtual - xFixo);
      xAtual = xProximo;
      imagemAtual = f(xAtual);
      printf("Para iteração %d x = %f e f(x) = %f\n", j, xAtual, imagemAtual);
      if(fabs(imagemAtual) < tolerancia || imagemAtual == 0.0)
        return xAtual;
    }
    
    return 0.0;
 
}

#endif
