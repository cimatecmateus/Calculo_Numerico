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
    
    rtb = func < 0.0 ? (dx=b-a,a) : (dx=a-b,b);    //Desvio condicional que define o ponto de referência para o inicio das iteracoes  

    for (j = 1; j <= JMAX; j++){    //Inicio das iteracoes
      xMedio = rtb + (dx *= 0.5);   //Ponto medio                         
      fMedia = f(xMedio);      //Imagem do ponto medio             
      printf("Para iteracao %d temos x=%f e fx=%f dx=%f\n", j, xMedio, fMedia, dx);
      if (fMedia <= 0.0)    //Se a imagem do ponto medio for negativa, o ponto de referencia assume seu valor
        rtb = xMedio;

      switch(opTolerancia){
        case 'e':'E';
          if(fabs(fMedia) < tolerancia)
            return xMedio;
          break;
        case 'd':'D';
          if (fabs(dx) < tolerancia)    //Se o erro absoluto for menor ou igual ao desejado ou a imagem do ponto medio igual a zero, raiz encontrada! 
            return xMedio; 
          break;
      }
    }

    printf("\nNumero maximo de iteracoes atingido e raiz nao encontrada\n");
    return 0.0;                                  
}

#endif

