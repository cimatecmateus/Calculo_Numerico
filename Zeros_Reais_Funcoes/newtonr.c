#ifndef _NEWRAPH_H
#define _NEWRAPH_H

#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

#define JMAX 4000000 /*definido o número máximo de iterações.*/
   

/* Função que através do método de Newton-Raphson
retorna a raíz da função desejada.
Recebe como parâmetros um valor chute de raiz e o erro 
absoluto epsilon (erroAbs) */
float metodoNewRaph(float x1, float tolerancia, char opTolerancia) {

  int j;
  float df, dx, func ,rtn;
  float xAnt;
  float delta;

  rtn = x1; //Valor inicial de chute

  for (j=1;j<=JMAX;j++) {
    func = f(rtn);  
    dx = f(rtn) / fLinha(rtn);
    xAnt = rtn;
    rtn -= dx;
    delta = (rtn - xAnt) / rtn;

    printf("Para iteracao %d temos x = %f e f(x) = %f dx = %f \n", j, rtn, f, fabs(delta));

    if (fabs(dx)>10000){ 
      printf("\nNão converge.\n");
      return 0.0;
    }

    if(opTolerancia == 'e' || opTolerancia == 'E'){
      if (fabs(func) < tolerancia) 
        return rtn; /*convergencia. */
    }
    else{
      if(fabs(delta) < tolerancia)
        return rtn;
    }

  }

  printf("\nNúmero de iterações excedeu o limite\n");
  return 0.0;  /* Nunca chegue aqui*/

}

#endif

