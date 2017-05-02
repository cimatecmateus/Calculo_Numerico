#ifndef _BISEC_H
#define _BISEC_H

#include "funcoes.h"

#define JMAX 4000000 //Número máximo de iterações

/* Função que através do método de bisseção
retorna a raíz da função desejada.
Recebe como parâmetros o intervalo (x1 e x2) no qual supõe-se
está contida raíz a ser determinada e o erro 
absoluto delta (erroAbs) */
float metodoBiseccao(float a, float b, float tolerancia, char opTolerancia){
  int j;
  float dx,func,fMedia,xMedio,rtb;

    printf("\n");

    func = f(a);
    
    rtb = func < 0.0 ? (dx = b - a, a) : (dx = a - b, b);    //Desvio condicional que define o ponto de referência para o inicio das iteracoes  

    for (j = 1; j <= JMAX; j++){    //Inicio das iteracoes
      xMedio = rtb + (dx *= 0.5);   //Ponto medio                         
      fMedia = f(xMedio);           //Imagem do ponto medio             
      printf("Para iteração %d temos x = %f | f(x) =% f | Delta = %f\n", j, xMedio, fMedia, dx);
      if (fMedia <= 0.0)            //Se a imagem do onto medio for negativa, o ponto de referencia assume seu valor
        rtb = xMedio;

      switch(opTolerancia){
        case 'e':case 'E':
          if(fabs(fMedia) < tolerancia) //Se o erro absoluto for menor ou igual ao desejado
            return xMedio;
          break;
        case 'd':case 'D':
          if (fabs(dx) < tolerancia)    //Se o erro absoluto for menor ou igual ao desejado 
            return xMedio; 
          break;
      }
    }

    printf("\núumero máximo de iterações atingido e raíz não encontrada\n");
    return 0.0;                                  
}

#endif

