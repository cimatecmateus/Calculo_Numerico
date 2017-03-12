#include <stdlib.h>
#include <stdio.h>
#include "funcoes.h"

#define MAXIT 30 /*numero m�ximo de itera��es */
     

float metodoCordas(float a, float b, float tolerancia){

  int j;//n�mero de itera��es 
  float fa, fb, xFixo, xProximo, xAtual, imagemFixa, imagemAtual;

  fa = f(a);  
  fb = f(b);  

  if (fa * fb >= 0.0){    //Condição que valida o intervalo passado pelo usuário
    printf("\n----------------------------------------------->Erro!<-----------------------------------------------");
    printf("\nA raíz da funcao não esta contida no intervalo [%f, %f]\n", a, b);
    return 0.0;
  }
  else{
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
 
}


main(){
float x1, x2, xacc,x;      

        printf("Digite o limite inferior do intervalo: ");
        scanf("%f",&x1);
        printf("Digite o limite superior do intervalo: ");
        scanf("%f",&x2);
        printf("Determine o criterio para convergencia: ");
        scanf("%f",&xacc);
 
         x = metodoCordas(x1,x2,xacc);
         printf("\nO valor de x e: %f\n",x);
         

}
