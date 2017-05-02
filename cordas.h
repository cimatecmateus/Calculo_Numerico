#ifndef _CORDAS_H
#define _CORDAS_H

#include "funcoes.h"

#define MAXIT 1000 //Número máximo de iterações
     
float metodoCordas(float a, float b, float tolerancia){

  int j;
  float xFixo, xProximo, xAtual, imagemFixa, imagemAtual;

    if(f(a) > 0){   //Se imagem do ponto a positiva
      xFixo = a;
      xAtual = b;
      imagemFixa = f(a);
    }
    else{         //Se imagem do ponto b positiva
      xFixo = b;
      xAtual = a;
      imagemFixa = f(b);
    }

    printf("\n");

    for(j = 1; j < MAXIT; j++){
      xProximo = xAtual - (f(xAtual)/(f(xAtual) - imagemFixa))*(xAtual - xFixo);    //Calcula próximo valor da iteração
      xAtual = xProximo;
      imagemAtual = f(xAtual);
      printf("Para iteração %d x = %f | f(x) = %f\n", j, xAtual, imagemAtual);
      if(fabs(imagemAtual) < tolerancia || imagemAtual == 0.0)      //Se critério de parada satisfeito, retorne o valor da raiz
        return xAtual;
    }
    printf("\nLimite de iterações excedida!\n");
    return 0.0;
 
}

#endif
