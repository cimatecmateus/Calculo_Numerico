#include <stdio.h>
#include "rungeKutta4.h"
#include "rungeKutta2.h"
#include "euler.h"

/* Método que limpa buffer do teclado no linux */
static void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void metodosEDO(){

    char opMetodo;              //Armazena a opção de método digitada pelo usuário
    char respUsuario;           //Armazena opção de continuação do programa
    float x0, y0, h, xAlvo;
    float resultado;
    char funcao[] = "x + 2xy";

    do{
        system("clear");
        //flush_in();

        printf("Escolha uma dos três métodos de integração:\n");

        printf("1 - Euler;\n");
        printf("2 - Runge-Kutta 2ª ordem;\n");
        printf("3 - RUnge-Kutta 4ª ordem.");

        printf("\n\nDigite o número correpondente ao método desejado: ");
        scanf("%c", &opMetodo);
        printf("\n");
        flush_in();

            // Entrada em teclado das vari�veis e condi��es de contorno
        printf("Digite os parâmetros de resolucao:");
        printf("\nx0: ");
        scanf("%f", &x0);
        printf("y0: ");
        scanf("%f", &y0);
        printf("h: ");
        scanf("%f", &h);
        printf("y(?): ");
        scanf("%f", &xAlvo);

        switch(opMetodo){
            case '1':
                resultado = euler(x0, y0, h, xAlvo);
                break;
            case '2':
                resultado = rungeKutta2(x0, y0, h, xAlvo);
                break;
            case '3':
                resultado = rungeKutta4(x0, y0, h, xAlvo);
                break;
            default:
                printf("\nOpção inválida!\n");
        }

        printf("\n\nA primitiva de %s no ponto %.4f e igual a %.4f", funcao, xAlvo, resultado); // Sa�da em tela do Resultado final.

        flush_in();
        printf("\n\nDeseja executar o programa novamente?\n");
        printf("Resposta (S/N): ");
        scanf("%c", &respUsuario);
        flush_in();

}while(respUsuario == 's' || respUsuario == 'S');


}