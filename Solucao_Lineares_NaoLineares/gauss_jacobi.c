#include<stdio.h>
#include<math.h>

void flush_in();

int main(){
    char respUsuario;
    int i,j, dimMatriz,iteracoesMax, qtdIteracoes = 0;
    float vetorSolucao[10],vetSolucaoAnt[10], vetorTolerancia[10], matrizPrincipal[10][10],termIndependente[10],c[10], tolerancia, maior;

    printf("\nDefina a dimensão da matriz: ");
    scanf("%d",&dimMatriz);

    printf("\nDefina a matriz dos coeficientes:\n");
        for(i=0;i<dimMatriz;i++){
            for(j=0;j<dimMatriz;j++){
                printf("a[%d,%d]=  ",i+1,j+1);
                scanf("%f",&matrizPrincipal[i][j]);
            }
    }

    printf("\nDefina o vetor dos termos independentes:\n");
    for(i=0;i<dimMatriz;i++){
        printf("b[%d]=  ",i+1);
        scanf("%f",&termIndependente[i]);
    }

    printf("\nDefina o vetor do chute inicial:\n");
    for(i=0;i<dimMatriz;i++){
        printf("x[%d]=  ",i+1);
        scanf("%f",&vetorSolucao[i]);
        vetSolucaoAnt[i] = vetorSolucao[i];
    }

    flush_in();
    printf("\nDefina a opção de convergência: ");
    printf("\n1)Quantidade iteracoes;");
    printf("\n2)Tolerancia.");
    printf("\nResposta: ");
    scanf("%c", &respUsuario);

    switch(respUsuario){
        case '1':
            printf("\nDefina o número de iterações: ");
            scanf("%d",&iteracoesMax);

            while(qtdIteracoes <= iteracoesMax ){       //Enquanto número máximo de iterações não alcançado
                for(i=0;i<dimMatriz;i++){
                    c[i]=termIndependente[i];
                    for(j=0;j<dimMatriz;j++) {
                        if(i!=j) {
                            c[i]=c[i]-matrizPrincipal[i][j]*vetorSolucao[j];

                        }
                    }
                }
                /* Calcula a solução parcial do sistema */
                for(i=0;i<dimMatriz;i++) {
                    vetorSolucao[i]=c[i]/matrizPrincipal[i][i];
                }
                qtdIteracoes++;
            }
            break;
        case '2':
            printf("\nDefina a tolerancia: ");
            scanf("%f", &tolerancia);

            do         //Enquanto a quantidade de iterações for menor a especificada pelo usuário
            {
                for(i=0;i<dimMatriz;i++){
                    c[i]=termIndependente[i];
                    for(j=0;j<dimMatriz;j++) {
                        if(i!=j) {
                            c[i]=c[i]-matrizPrincipal[i][j]*vetorSolucao[j];

                        }
                    }
                }
                /* Calcula a solução parcial do sistema */
                for(i=0;i<dimMatriz;i++) {
                    vetorSolucao[i]=c[i]/matrizPrincipal[i][i];
                    vetorTolerancia[i] = fabs(vetorSolucao[i] - vetSolucaoAnt[i]);
                    vetSolucaoAnt[i] = vetorSolucao[i];
                }

                maior = vetorTolerancia[0];
                for(i=0; i<dimMatriz; i++){
                    if(vetorTolerancia[i+1] > maior)
                        maior = vetorTolerancia[i+1];
                }
            }while (maior > tolerancia);
            break;
    }


        printf("\n\nA solução do sistema é: \n");
        printf("\nX = %f", vetorSolucao[0]);
        printf("\nY = %f", vetorSolucao[1]);
        printf("\nZ = %f\n", vetorSolucao[2]);
}

/* Método que limpa buffer do teclado no linux */
void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}