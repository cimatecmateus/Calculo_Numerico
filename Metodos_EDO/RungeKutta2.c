#include <stdio.h> // Declara��o da biblioteca
#include "derivada.h"
#include "rungeKutta2.h"

#define MAX_ITERACOES 1000

float rungeKutta2(float x0, float y0, float h, float xAlvo){

	// Declara��o das vari�veis
	float k1, k2;
	float x, yi;
	int i = 0;
	
	// Valores iniciais
	x = x0;
	yi = y0;
	
	printf("\ny%d = %.4f", i, yi);
	i++;
	
	while(x < xAlvo && i < MAX_ITERACOES){ // Condi��o de parada
		
		k1 = fLinha(x, yi); // Aplica a primeira itera��o
		k2 = fLinha(x + h, yi + h*k1);
		yi = yi + (h * 0.5 * (k1 + k2));
		printf("\ny%d = %.4f", i, yi); // Saida em tela do resultado de cada itera��o
		x += h; // Atualiza��o das vari�veis
		i++;
	}

	return yi;
}
	