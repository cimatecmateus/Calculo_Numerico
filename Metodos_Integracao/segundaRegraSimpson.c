#include <stdio.h>
#include "segundaRegraSimpson.h"
#include "func_integral.h"

/* Função que calcula a integral de uma função pelo método da segunda regra de Simpson */
float segundaRegraSimpson(float limInferior, float limSuperior, int numPartes){

    float x;            //Armazena valores da abscissa
    float h;            //Armazena altura dos trapézios
    float somatorio;    //Armazena área ponderada dos trapézios 
    float resultado;    //Armazena resultado da integração
    int i;              //Usado para iteração 

    if(limInferior > limSuperior){          //Verifica se limites passados são válidos
        printf("\nLimites Inválidos!");
        printf("\nO limite inferior deve ser menor que o limite superior");
        return -1.0;
    }
    if((numPartes % 3) != 0){               //Verifica se o número de partes é múltiplo de 3
        printf("\nNúmeros de partes inválido!");
        printf("\nO número de partes não é múltiplo de 3");
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
                if((i % 3) == 0)                //Se i múltiplo de 3
                    somatorio += y(x) * 2.0;
                else
                    somatorio += y(x) * 3.0;
            //printf("\nx = %f", x);
            //printf("\nf(x) = %f", f(x))
            //printf("\nsomatorio = %f\n", somatorio);
            x += h;         //Incrementa abscissa
        }
        resultado = (3.0 * somatorio * h) / 8.0;
        return resultado;
    }
}