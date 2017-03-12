#include <stdlib.h>
#include <stdio.h>
#include "cordas.h"
#include "bisec.h"
#include "newraph.h"
#include "funcoes.h"

/* Método que limpa buffer do teclado no linux */
void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

/* Método que pausa o programa esperandi interação do usuário */
void aguardaUsuario(){
  printf("\nPressione enter para continuar continuar...");
  flush_in();
  getchar();
}

int validaIntervalo(float a, float b){
  if (f(a) * f(b) < 0.0 && f(b) > f(a))    //Condição que valida o intervalo passado pelo usuário
    return 1;
  else
    return 0;
  
}

int main(){
    system("clear");

    float x1, x2, erroAbs, raiz;
    char usuarioResp, opMetodo, opTolerancia;

    printf("------------------------> Metodos Numericos para calculo de raizes de funcoes reais <------------------------>");
    
    printf("\nPossíveis metodos:\n");
    printf("1 - Bisecção;\n");
    printf("2 - Newton-Raphson;\n");
    printf("3 - Cordas.\n");

    printf("\nDigite o numero correspondente ao método desejado: ");
    scanf("%c", &opMetodo);
    printf("\n");
    flush_in();

    switch(opMetodo){
      case '1': '3';
          printf("Digite o limite inferior do intervalo: ");
          scanf("%f",&x1);
          printf("Digite o limite superior do intervalo: ");
          scanf("%f",&x2);

          if(!validaIntervalo(x1,x2)){      //Se o intervalo dado não for válido, pare!
            printf("\n----------------------------------------------->Erro!<-----------------------------------------------");
            printf("\nIntervalo [%f, %f] inválido!", x1, x2);
            return 0;
          }

          printf("Digite o valor da tolerancia: ");
          scanf("%f", &erroAbs);

          if(opMetodo == '1'){      //Se metodo igual bisecção, escola o  tipo de critério de parada
            do{
              printf("Digite o criterio de parada epsilon ou delta (E/D): ");
              flush_in();
              scanf("%c", &opTolerancia);
            }while(opTolerancia != 'e' && opTolerancia != 'E' && opTolerancia != 'd' && opTolerancia != 'D');
          }

          if(opMetodo == '1')
            raiz = metodoBiseccao(x1, x2, erroAbs, opTolerancia);
          else
            raiz = metodoCordas(x1, x2, erroAbs);

          break;

      case '2':
        printf("Digite o valor de chute: ");
        scanf("%f",&x1);

        do{
          printf("Digite o criterio de parada epsilon ou delta (E/D): ");
          flush_in();
          scanf("%c", &opTolerancia);
        }while(opMetodo != 'e' || opMetodo != 'E' || opMetodo != 'd' || opMetodo != 'D');

        printf("Digite o valor da tolerancia: ");
        scanf("%f", &erroAbs);

        raiz = metodoNewRaph(x1, erroAbs, opTolerancia);
        
    }

    printf("\n\nA raiz da funcao é: %f\n", raiz);


}