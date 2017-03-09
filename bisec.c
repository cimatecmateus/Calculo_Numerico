#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define JMAX 4000000 //Número máximo de iterações

/* Método que retorna o valor da função analisada para um dado ponto */
float funcao(float x){
  float func = pow(x,2) + log(x);
  return func;
}

/* Método que limpa buffer do teclado no linux */
void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}

/* Método que pausa o programa esperandi interação do usuário */
void aguardaUsuario(){
  printf("\nPressione enter para continuar continuar...");
  flush_in();
  getchar();
}      

/* Função que através do método de bisseção
retorna a raíz da função desejada.
Recebe como parâmetros o intervalo (x1 e x2) no qual supõe-se
está contida raíz a ser determinada e o erro 
absoluto delta (erroAbs) */
float rtbis(float x1, float x2, float erroAbs, const char *str){
  int j;
  float dx,f,fMedia,xMedio,rtb;

  /* Calcula a imagem dos valores do intervalo dado */
  f=funcao(x1);      
  fMedia=funcao(x2);
  
  if (f * fMedia >= 0.0){    //Condição que valida o intervalo passado pelo usuário
    printf("\n----------------------------------------------->Erro!<-----------------------------------------------");
    printf("\nA raíz da funcao '%s' não esta contida no intervalo [%f, %f]\n", str, x1, x2);
    return 0.0;
  }
  else{
    printf("\n");
    
    rtb = f < 0.0 ? (dx=x2-x1,x1) : (dx=x1-x2,x2);    //Desvio condicional que define o ponto de referência para o inicio das iteracoes  
    for (j = 1; j <= JMAX; j++){    //Inicio das iteracoes
      xMedio = rtb + (dx *= 0.5);   //Ponto medio                         
      fMedia = funcao(xMedio);      //Imagem do ponto medio             
      printf("Para iteracao %d temos x=%f e fx=%f \n", j, xMedio, fMedia);
      if (fMedia <= 0.0)    //Se a imagem do ponto medio for negativa, o ponto de referencia assume seu valor
        rtb = xMedio;
      if (fabs(dx) < erroAbs || fMedia == 0.0)    //Se o erro absoluto for menor ou igual ao desejado ou a imagem do ponto medio igual a zero, raiz encontrada! 
        return rtb; 
    }
    printf("\nNumero maximo de iteracoes atingido e raiz nao encontrada\n");
    return 0.0;
  }                                    
}

main(){
  float x1, x2, erroAbs,x;
  char expFuncao[50] =  "x² + ln(x)";
  char usuarioResp;

  do{
    system("clear");
    printf("Digite o limite inferior do intervalo: ");
    scanf("%f",&x1);
    printf("Digite o limite superior do intervalo: ");
    scanf("%f",&x2);

    if(x1 >= x2){
      printf("\n----------------------------------------------->Erro!<-----------------------------------------------");
      printf("\nParâmetros inválidos!\n");
      aguardaUsuario();
      usuarioResp = 's';
    }
    else{
      printf("Digite o erro absoluto delta: ");
      scanf("%f",&erroAbs);
    
      x = rtbis(x1,x2,erroAbs, expFuncao);    //Calcula raiz com parâmetros passados pelo usuário

      if(x != 0.0){
        printf("\nA raiz da funcao '%s' contida no intervalo [%f,%f] e: %f\n" , expFuncao, x1, x2, x);
        printf("\nDeseja encontrar outra raiz?\n");
        printf("S/N: ");
        flush_in();
        scanf("%c",&usuarioResp);
      }
      else{
        aguardaUsuario();
        usuarioResp = 's';      
      }
    }
  }while(usuarioResp == 's' || usuarioResp == 'S');

  return 0;

}

