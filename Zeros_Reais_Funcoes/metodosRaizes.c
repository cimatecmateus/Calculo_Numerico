#include <stdlib.h>
#include <stdio.h>
#include "metodosRaizes.h"
#include "cordas.h"
#include "bisec.h"
#include "newraph.h"
#include "funcoes.h"

/* Método que limpa buffer do teclado no linux */
static void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

/* Método que recebe como parâmetro um determinado intervalo, e 
retorna 1 se o intervalo é válido ou retorna 0 caso inválido */
int validaIntervalo(float a, float b){
  if (f(a) * f(b) < 0.0 && f(b) > f(a))    //Condição que valida o intervalo passado pelo usuário
    return 1;
  else
    return 0;
  
}

void metodosRaizes(){
    system("clear");    //Limpa a tela do terminal

    float x1, x2, erroAbs, raiz;
    char usuarioResp, opMetodo, opTolerancia;
    extern char funcao[];     //Variável declarada no arquivo funcoes.h

    do{
      system("clear");
      printf("------------------------> Métodos Numéricos para cálculo de raízes de funções reais <------------------------");
      printf("\n\nPossíveis métodos:\n");
      printf("1 - Bissecção;\n");
      printf("2 - Newton-Raphson;\n");
      printf("3 - Cordas.\n");

      printf("\nDigite o número correspondente ao método desejado: ");
      scanf("%c", &opMetodo);
      printf("\n");
      flush_in();

      switch(opMetodo){
        case '1': case '3':     //Caso escolhido Bissecção ou Cordas
            printf("Digite o limite inferior do intervalo: ");
            scanf("%f",&x1);
            printf("Digite o limite superior do intervalo: ");
            scanf("%f",&x2);

            if(!validaIntervalo(x1,x2)){      //Se o intervalo dado não for válido, pare!
              printf("\n----------------> Erro! <----------------");
              printf("\nIntervalo [%f, %f] inválido!\n\n", x1, x2);
              break;
            }

            if(opMetodo == '1'){      //Se método igual bissecção, escolha o tipo de critério de parada
              do{
                printf("Digite o criterio de parada epsilon ou delta (E/D): ");
                flush_in();
                scanf("%c", &opTolerancia);
              }while(opTolerancia != 'e' && opTolerancia != 'E' && opTolerancia != 'd' && opTolerancia != 'D'); //Repete a pergunta caso a resposta esteja errada
            }

            printf("Digite o valor da tolerância: ");
            scanf("%f", &erroAbs);

            if(opMetodo == '1')                                         //Se metodo escolhido igual a bissecção
              raiz = metodoBiseccao(x1, x2, erroAbs, opTolerancia);     //Calcula raíz pelo método da bissecção
            else                                                        //Senão, método escolhido igual a cordas
              raiz = metodoCordas(x1, x2, erroAbs);                     //Calcula raíz pelo método de cordas

            printf("\nA raíz da função %s é: %f\n", funcao, raiz);

            break;

        case '2':     //Caso escolhido cordas
          printf("Digite o valor de chute: ");
          scanf("%f",&x1);

          do{
            printf("Digite o criterio de parada epsilon ou delta (E/D): ");
            flush_in();
            scanf("%c", &opTolerancia);
          }while(opTolerancia != 'e' && opTolerancia != 'E' && opTolerancia != 'd' && opTolerancia != 'D'); //Repete a pergunta caso a resposta esteja errada

          printf("Digite o valor da tolerancia: ");
          scanf("%f", &erroAbs);

          raiz = metodoNewRaph(x1, erroAbs, opTolerancia);      //Calcula raiz pelo método de Newthon-Raphson

          printf("\nA raíz da função %s é: %f\n", funcao, raiz);

          break;

        default:
          printf("\nOpção inválida!\n");
      }

      flush_in();
      printf("\nDeseja executar o programa novamente?\n");
      printf("Resposta (S/N): ");
      scanf("%c", &usuarioResp);
      flush_in();

    }while(usuarioResp == 's' || usuarioResp == 'S');   //Caso a resposta seja sim, repete o programa

    system("clear");

}