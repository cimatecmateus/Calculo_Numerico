#include <stdio.h>
#include "primeiraRegraSimpson.h"
#include "func_integral.h"

/* Função que calcula a integral de uma função pelo método da primeira regra de Simpson */
float primeiraRegraSimpson(float limInferior, float limSuperior, int numPartes){

    float x;            //Armzena valores da abscissa
    float h;            //Armazena altura dos trapézios
    float somatorio;    //Armzena área ponderada dos trapézios 
    float resultado;    //Armazena resultado da integração
    int i;              //Usado para iteração 

    if(limInferior > limSuperior){          //Verifica se limites passados são válidos
        printf("\nLimites Inválidos!");
        printf("\nO limite inferior deve ser menor que o limite superior");
        return -1.0;
    }
    if((numPartes % 2) != 0){               //Verifica se o número de partes é par
        printf("\nNúmeros de partes inválido!");
        printf("\nO número de partes não é par");
        return -1.0;
    }
    else{           //Se limites válidos
        h = (limSuperior - limInferior) / (float)numPartes;        //Calcula a altura dos trapezios
        //printf("\nH = %f", h);
        x = limInferior;                                           //Valor inicial para iteração
        somatorio = 0;
        for(i=0; i <= numPartes; i++){
            if(i == 0 || i == numPartes)        //Se primeiro ou último valor da iteração
                somatorio += y(x) * 1.0;
            else
                if((i % 2) == 0)                //Se i par
                    somatorio += y(x) * 2.0;
                else
                    somatorio += y(x) * 4.0;
            //printf("\nx = %f", x);
            //printf("\nf(x) = %f", f(x))
            //printf("\nsomatorio = %f\n", somatorio);
            x += h;         //Incrementa abscissa
        }
        resultado = (somatorio * h) / 3;
        return resultado;
    }
}