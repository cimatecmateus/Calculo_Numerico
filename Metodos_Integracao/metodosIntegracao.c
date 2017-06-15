#include <stdio.h>
#include "metodosIntegracao.h"
#include "trapezio.h"
#include "primeiraRegraSimpson.h"
#include "segundaRegraSimpson.h"

/* Método que limpa buffer do teclado no linux */
static void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void metodosIntegracao(){

    char opMetodo;              //Armazena a opção de método digitada pelo usuário
    char respUsuario;           //Armazena opção de continuação do programa
    float resultado;            //Armazena o resultado da integração numérica
    float limInferior;          //Armazena o limite inferior digitado pelo usuário
    float limSuperior;          //Armazena o limite superior digitada pelo usuário
    unsigned int numPartes;     //Armazena o número de partes especificado pelo usuário
    extern char yString[];      //Armazena string que descreve a função

    respUsuario = 's';

    do{
        system("clear");
        //flush_in();

        printf("Escolha uma dos três métodos de integração:\n");

        printf("1 - Método dos Trapézios;\n");
        printf("2 - Primeira Regra de Simpson;\n");
        printf("3 - Segunda Regra de Simpson.");

        printf("\n\nDigite o número correpondente ao método desejado: ");
        scanf("%c", &opMetodo);
        printf("\n");
        flush_in();

        if(opMetodo != '1' && opMetodo != '2' && opMetodo != '3'){
            printf("\nOpção inválida!\n");
        }
        else{
            printf("Digite o limite superior de integração: ");
            scanf("%f", &limInferior);

            printf("Digite o limite superior de integração: ");
            scanf("%f", &limSuperior);

            printf("Digite o número de partes: ");
            scanf("%d", &numPartes);
        }

        switch(opMetodo){
            case '1':
                resultado = metodoTrapezio(limInferior, limSuperior, numPartes);
                break;
            case '2':
                resultado = primeiraRegraSimpson(limInferior, limSuperior, numPartes);
                break;
            case '3':
                resultado = segundaRegraSimpson(limInferior, limSuperior, numPartes);
                break;
        }

        if(resultado != -1.0){      //Se nenhum erro encontrado pelas funções
            printf("\nA integral de %s de %.4f até %.4f é igual a %.4f\n", yString, limInferior, limSuperior, resultado);
        }
        else{
            printf("\nErro!\n");
        }

        flush_in();
        printf("\nDeseja executar o programa novamente?\n");
        printf("Resposta (S/N): ");
        scanf("%c", &respUsuario);
        flush_in();

    }while(respUsuario == 's' || respUsuario == 'S');


}