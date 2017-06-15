#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "naoLinear.h" 
//#include<locale.h>

#define IMAX 5000

/* Método que limpa buffer do teclado no linux */
void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

/* Função respons�vel pelo cálculo da Função f(xy)*/
float funcao1(float x, float y){			
	float f;
	f=-pow(x,2) - 4*pow(y,2) + 4;
	return f;
}

/* Função respons�vel pelo calculo da Função g(xy)*/
float funcao2(float x, float y){			
	float g;
	g=pow(x,2) - pow(y,2) + 1;
	return g;
}

/* Derivada parcial da Função f(x) em rela��o � x */
float dfdx(float x){					
	float fx;
	fx=-2*x;
	return fx;
}

/* Derivada parcial da Função f(y) em rela��o � y */
float dfdy(float y){					
	float fy;
	fy=-8*y;
	return fy;
}

/* Derivada parcial da Função g(x) em rela��o � x */
float dgdx(float x){					
	float gx;
	gx=2*x;
	return gx;
}

/* Derivada parcial da Função g(y) em rela��o � x */
float dgdy(float y){					
	float gy;
	gy=-2*y;
	return gy;
}

/* Função  respons�vel pelo cálculo do fator jacobiano*/
float jacobiano(float x, float y){			
	float jac;
		
	jac= (dfdx(x)*dgdy(y)) - (dgdx(x)*dfdy(y)); 

	if(jac==0){
		printf("Nao converge \n\n");
	}
	return jac;
}

/* cálculo parcial de X(n+1), sem o fator X(n) e o fator Jacobiando*/
float detx(float x, float y){				
	float detx,i,j;
	
	detx=funcao1(x,y)*dgdy(y)-funcao2(x,y)*dfdy(y);
	return detx;
}

/* cálculo parcial de Y(n+1), sem o fator Y(n) e o fator jacobiano */
float dety(float x, float y){				
    float dety;
	
	dety=dfdx(x)*funcao2(x,y)-dgdx(x)*funcao1(x,y);
	return dety;
}

void metodoNaoLinear(){
		
	system("clear");
	int i, iteracao, sem = 0; 
	char escolha;
	float x,y,e,ex,ey,djx,djy;
	float v1[10000],v2[10000];
	printf("Insira valores iniciais para:\n");
	printf("Xo = ");
	scanf("%f",&x);
	printf("Yo = ");
	scanf("%f",&y);
	flush_in();	
	printf("\nDigite o critério de convergência:\n1)Tolerância;\n2)Quantidade de iterações.\nResposta: ");
	scanf("%c",&escolha);
	
	v1[0] = x;
	v2[0] = y;

	
  switch(escolha){ 
  		case '1':
		  	flush_in();   
			printf("\nDigite o valor da tolerancia: ");
			scanf("%f", &e);
			i = 0;
			while(sem == 0){

				djx=detx(x,y)/jacobiano(x,y);
				x-=djx;
				v1[i]=x;
				
				djy=dety(x,y)/jacobiano(x,y);
				y-=djy;
				v2[i]=y;
						
				printf("\nIteracao nº %d:  X = %f   Y = %f",i,x,y);
				
				ex=v1[i]-v1[i-1];
				ey=v2[i]-v2[i-1];
				
				if((fabs(ex)<e) && (fabs(ey)<e)){
					printf("\n\nSolução do Sistema:\nX = %f \nY = %f \n\n",v1[i],v2[i]);
					sem = 1;
					//system("pause");
				}
				i++;
			}
			break;

	 case '2':
	 		//flush_in();
		   	printf("\nDigite o numero de iteracoes\n");
		   	scanf("%d", &iteracao);
	
			for(i=0; i<iteracao; i++){

					djx=detx(x,y)/jacobiano(x,y);
					x-=djx;
					v1[i]=x;
					
					djy=dety(x,y)/jacobiano(x,y);
					y-=djy;
					v2[i]=y;
					
				printf("\n %d iteracao:  X = %.2f   Y = %.2f",i,x,y);
			
			}
			printf("\n\n\t%d iteracoes\t \n Resposta:\n X=%.2f \n Y=%.2f \n\n",i,v1[i],v2[i]);
			break;
	}
}
