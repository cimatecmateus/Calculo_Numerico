
#include <stdio.h>
#include "naoLinear.h"
#include "gaussSeidel.h"
#include "gaussJacobi.h"
#include "metodosLinearesNaoLineares.h"

static void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void metodosLinearesNaoLineares(){

    char opMetodo;              //Armazena a opção de método digitada pelo usuário
    char respUsuario;           //Armazena opção de continuação do programa

    respUsuario = 's';

    do{
        system("clear");
        //flush_in();

        printf("Escolha uma dos três métodos de integração:\n");

        printf("1 - Sistema não linear;\n");
        printf("2 - Gauss-Seidel;\n");
        printf("3 - Gauss-Jacobi.");

        printf("\n\nDigite o número correpondente ao método desejado: ");
        scanf("%c", &opMetodo);
        printf("\n");
        flush_in();

        if(opMetodo != '1' && opMetodo != '2' && opMetodo != '3'){
            printf("\nOpção inválida!\n");
        }

        switch(opMetodo){
            case '1':
                metodoNaoLinear();
                break;
            case '2':
                metodoGaussSeidel();
                break;
            case '3':
                metodoGaussJacobi();
                break;
        }

        flush_in();
        printf("\nDeseja executar o programa novamente?\n");
        printf("Resposta (S/N): ");
        scanf("%c", &respUsuario);
        flush_in();

    }while(respUsuario == 's' || respUsuario == 'S');
}