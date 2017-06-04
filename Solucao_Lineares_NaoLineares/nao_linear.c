#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#include<locale.h>

#define IMAX 5000

/* Método que limpa buffer do teclado no linux */
void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

float funcao1(float x, float y){			/* Fun��o respons�vel pelo c�lculo da fun��o f(xy)*/
	float f;
	f=-pow(x,2) - 4*pow(y,2) + 4;
	return f;
}

float funcao2(float x, float y){			/* Fun��o respons�vel pelo calculo da fun��o g(xy)*/
	float g;
	g=pow(x,2) - pow(y,2) + 1;
	return g;
}

float dfdx(float x){					/* Derivada parcial da fun��o f(x) em rela��o � x */
	float fx;
	fx=-2*x;
	return fx;
}

float dfdy(float y){					/* Derivada parcial da fun��o f(y) em rela��o � y */
	float fy;
	fy=-8*y;
	return fy;
}

float dgdx(float x){					/* Derivada parcial da fun��o g(x) em rela��o � x */
	float gx;
	gx=2*x;
	return gx;
}

float dgdy(float y){					/* Derivada parcial da fun��o g(y) em rela��o � x */
	float gy;
	gy=-2*y;
	return gy;
}

float jacobiano(float x, float y){			/* Fun��o  respons�vel pelo c�lculo do fator jacobiano*/
	float jac;
		
	jac= (dfdx(x)*dgdy(y)) - (dgdx(x)*dfdy(y)); 

	if(jac==0){
		printf("Nao converge \n\n");
	}
	return jac;
}

float detx(float x, float y){				/* C�lculo parcial de X(n+1), sem o fator X(n) e o fator Jacobiando*/
	float detx,i,j;
	
	detx=funcao1(x,y)*dgdy(y)-funcao2(x,y)*dfdy(y);
	return detx;
}

float dety(float x, float y){				/* C�lculo parcial de Y(n+1), sem o fator Y(n) e o fator jacobiano */
    float dety;
	
	dety=dfdx(x)*funcao2(x,y)-dgdx(x)*funcao1(x,y);
	return dety;
}

metodo_nao_linear(){						// Função principal
	
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
	
	v1[0]=x;
	v2[0]=y;

	
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
		   	scanf("%d", iteracao);
	
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
main(){
	metodo_nao_linear();
}
