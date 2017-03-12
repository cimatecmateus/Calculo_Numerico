#include <stdlib.h>
#include <stdio.h>
#include <math.h>


#define JMAX 4000000 /*definido o número máximo de iterações.*/

/* Método que retorna o valor da função analisada para um dado ponto */
float funcao(float x){    
      float func = pow(x,2) + x - 6;
      return func;
}      

/* Método que retorna o valor da derivada da função analisada para um dado ponto */
float derivaf(float x){
      float deriva = 2*x + 1;
      return deriva;
} 

/* Método que limpa buffer do teclado no linux */
void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

void aguardaUsuario(){
  printf("\nPressione enter para continuar continuar...");
  flush_in();
  getchar();
}      

/* Função que através do método de Newton-Raphson
retorna a raíz da função desejada.
Recebe como parâmetros um valor chute de raiz e o erro 
absoluto epsilon (erroAbs) */
float rtnewt(float x1, float tolerancia, char opTolerancia) {

  int j;
  float df, dx, f ,rtn;
  float xAnt;
  float delta;

  rtn = x1; //Valor inicial de chute

  for (j=1;j<=JMAX;j++) {
    f = funcao(rtn);  
    dx = funcao(rtn) / derivaf(rtn);
    xAnt = rtn;
    rtn -= dx;
    delta = (rtn - xAnt) / rtn;

    printf("Para iteracao %d temos x = %f e f(x) = %f dx = %f \n", j, rtn, f, fabs(delta));

    if (fabs(dx)>10000){ 
      printf("\nNão converge.\n");
      return 0.0;
    }

    if(opTolerancia == 'e' || opTolerancia == 'E'){
      if (fabs(f) < tolerancia) 
        return rtn; /*convergencia. */
    }
    else{
      if(fabs(delta) < tolerancia)
        return rtn;
    }

  }

  printf("\nNúmero de iterações excedeu o limite\n");
  return 0.0;  /* Nunca chegue aqui*/

}


main(){

  system("clear");

  float x1, xacc, x;
  char resposta;      

  printf("Insira o valor inicial: ");
  scanf("%f",&x1);
  flush_in();
  printf("\nCritério de convergência Epsilon ou Delta?\n");
  printf("Resposta (E/D): ");
  scanf("%c", &resposta);

  if(resposta == 'e' || resposta == 'E' || resposta == 'd' || resposta == 'D'){
    printf("\nEspecifique o critério de convergência: ");
    scanf("%f",&xacc);
  }
  else{
    printf("\nResposta invalida!\n");
    aguardaUsuario();
    return 0;
  }
 
  x = rtnewt(x1,xacc, resposta);
  printf("\nO valor de x e: %f\n",x);
         

}
