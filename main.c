#include <stdio.h>
#include "metodosIntegracao.h"
#include "metodosRaizes.h"
#include "metodosLinearesNaoLineares.h"

/* Método que limpa buffer do teclado no linux */
static void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

int main(){

    char opMetodo;
    system("clear");

    printf("---------------------------------------------------------------------------------------------------");
    printf("\n");
    printf("-----------------------> Bem vindo(a) a calculadora de métodos numéricos <-----------------------");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------");

    printf("\n\n\nEscolha qual método deseja utilizar:\n");

    printf("1 - Zeros reais de funções;\n");
    printf("2 - Solução de sistemas lineares e não lineares;\n");
    printf("3 - Métodos de integração;");
    printf("4 - Métodos de EDOs.");

    printf("\n\nDigite o número correspondente ao método desejado: ");
    scanf("%c", &opMetodo);
    printf("\n");
    flush_in();

    switch(opMetodo){
        case '1':
            metodosRaizes();
            break;
        case '2':
            metodosLinearesNaoLineares();
            break;
        case '3':
            metodosIntegracao();
            break;
        case '4':
            metodosEDO();
        default:
            printf("\nOpção inválida!");
    }
}