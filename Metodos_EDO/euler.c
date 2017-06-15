#include <stdio.h> // Declaração de biblioteca
#include "derivada.h"
#include "euler.h"

#define MAX_ITERACOES 1000

float euler(float x0, float y0, float h, float xAlvo){ 

	// Declaração das variáveis
	float x, yi; 
	int i = 1;

	// Valores iniciais
	x = x0; 
	yi = y0;
	
	while(x <= xAlvo && i <= MAX_ITERACOES){ 						// Condicao de parada
		yi = yi + (h * fLinha(x, yi));  	// Estima yi+1 
		printf("\ny%d = %.4f", i, yi); 	// Entrada em tela o valor de yi
		x += h;
		i++;
	}

	return yi;

}