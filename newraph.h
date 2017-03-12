#ifndef _NEWRAPH_H
#define _NEWRAPH_H

#include "funcoes.h"

#define JMAX 4000000 /*definido o número máximo de iterações.*/
   
/* Função que através do método de Newton-Raphson
retorna a raíz da função desejada.
Recebe como parâmetros um valor chute de raiz e o erro 
absoluto epsilon (erroAbs) */
float metodoNewRaph(float x1, float tolerancia, char opTolerancia) {

  int j;
  float dx, imagemAtual, xAtual, xProximo, delta;

  xAtual = x1; //Valor inicial de chute

  printf("\n");

  for (j=1;j<=JMAX;j++) {                     //Início das iterações
    imagemAtual = f(xAtual);
    dx = (imagemAtual/fLinha(xAtual));
    xProximo = xAtual - dx;                   //Calcula o próxima suposta raiz
    delta = (xProximo - xAtual) / xProximo;   //Calculo da tolerancia

    printf("Para iteração %d temos x = %f | f(x) = %f | Tolerância = %f \n", j, xAtual, imagemAtual, fabs(delta));

    if (fabs(dx)>10000){                      //Se a divisao f(x)/f'(x), raiz não converge
      printf("\nNão converge.\n");
      return 0.0;
    }

    /* Define qual será condição de parada */
    if(opTolerancia == 'e' || opTolerancia == 'E'){       //Se epsilon, usar a imagem do ponto atual       
      if (fabs(imagemAtual) < tolerancia) 
        return xAtual;                                    //Retorna valor da raiz para uma  dada tolerancia
    }
    else{                                                 //Senão, tolerancia = (Xk+1 - Xk)/Xk+1
      if(fabs(delta) < tolerancia)
        return xAtual;
    }

    xAtual = xProximo;        //Se condicao de parada não validada, o ponto calculado é inserido novamente na iteração

  }

  printf("\nNúmero de iterações excedeu o limite\n");
  return 0.0;  /* Nunca chegue aqui*/

}

#endif

