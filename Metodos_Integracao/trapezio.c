#include <stdio.h>
#include "trapezio.h"
#include "func_integral.h"

/* Função que calcula a integral de uma função pelo método dos trapézios */
float metodoTrapezio(float limInferior, float limSuperior, int numPartes){

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
    else{           //Se limites válidos
        h = (limSuperior - limInferior) / (float)numPartes;        //Calcula a altura dos trapezios
        //printf("\nH = %f", h);
        x = limInferior;                                           //Valor inicial para iteração
        somatorio = 0;
        for(i=0; i <= numPartes; i++){
            if(i == 0 || i == numPartes)        //Se primeiro ou último valor da iteração
                somatorio += y(x) * 1.0;
            else
                somatorio += y(x) * 2.0;
            //printf("\nx = %f", x);
            //printf("\nf(x) = %f", f(x));
            //printf("\nsomatorio = %f\n", somatorio);
            x += h;
        }
        resultado = (somatorio * h) / 2;
        return resultado;
    }
}