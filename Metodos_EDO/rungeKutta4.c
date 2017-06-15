#include <stdio.h> // Declara��o da biblioteca
#include "derivada.h"
#include "rungeKutta4.h"

#define MAX_ITERACOES 1000

float rungeKutta4(float x0, float y0, float h, float xAlvo){

    // Declara��o de vari�veis
	float x, yi;
	int i = 0;
	float k1, k2, k3, k4;
	
    // Valores iniciais
	x = x0;
	yi = y0;
	
	printf("\ny%d = %.4f", i, yi);
	i++;
	
	while(x < xAlvo && i < MAX_ITERACOES){ // Condição de parada

		k1 = h * fLinha(x, yi); // Aplica o metodo de Runge-Kutta4
		//printf("\nk1 = %.4f", k1);
		k2 = h * fLinha(x + (h * 0.5), yi + (k1 * 0.5));
		//printf("\nk2 = %.4f", k2);
		k3 = h * fLinha(x + (h * 0.5), yi + (k2 * 0.5));
		//printf("\nk3 = %.4f", k3);
		k4 = h * fLinha(x + h, yi + k3);
		//printf("\nk4 = %.4f", k4);
		yi = yi + (((k1 + (2 * k2) + (2 * k3) + k4)) / 6);
		printf("\ny%d = %.4f", i, yi);
		x += h; // Atualiza��o de Valores
		i++;
	}
	
	return yi;
	
}