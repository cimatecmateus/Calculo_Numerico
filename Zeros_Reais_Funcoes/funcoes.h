#ifndef _FUNCOES_H
#define _FUNCOES_H

#include <math.h>

char funcao[] = "20.20x⁴ - 10.24x³ + 18.36x² - 11.68x - 11.32";

/* Método que retorna o valor da função analisada para um dado ponto */
float f(float x){    
      float func = 20.20 * pow(x, 4) - 10.24 * pow(x, 3) + 18.36 * pow(x, 2) - 11.68 * x - 11.32;
      return func;
}      

/* Método que retorna o valor da derivada da função analisada para um dado ponto */
float fLinha(float x){
      float deriva = 80.8 * pow(x, 3) - 30.72 * pow(x, 2) + 36.72 * x - 11.68;
      return deriva;
}

#endif