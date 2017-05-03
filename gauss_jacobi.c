#include<stdio.h>
#include<math.h>

int main() {
    int i,j, dimMatriz,iteracoesMax, qtdIteracoes = 0;
    float x[10],a[10][10],b[10],c[10];

    printf("\nDefina a dimensão da matriz: ");
    scanf("%d",&dimMatriz);

    printf("\nDefina o número de iterações: ");
    scanf("%d",&iteracoesMax);

    printf("\nDefina o vetor dos termos independentes: ");
    for(i=0;i<dimMatriz;i++) {
        printf("\nb[%d]=  ",i+1);
        scanf("%f",&b[i]);
    }

    printf("\nDefina a matriz dos coeficientes: ");
    for(i=0;i<dimMatriz;i++){
        x[i]=0;
        for(j=0;j<dimMatriz;j++) {
            printf("\na[%d,%d]=  ",i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
    while(qtdIteracoes <= iteracoesMax ){
        for(i=0;i<dimMatriz;i++) {
            c[i]=b[i];
            for(j=0;j<dimMatriz;j++) {
                if(i!=j) {
                    c[i]=c[i]-a[i][j]*x[j];
                    printf("\nc[%d]=%f", i, c[i]);

                }
            }
        }
        for(i=0;i<dimMatriz;i++) {
            x[i]=c[i]/a[i][i];
            printf("\nx[%d]=%f", i, x[i]);
        }
        qtdIteracoes++;
    }

        printf("\nThe Solution is : \n");
        for(i=0;i<dimMatriz;i++) {
            printf("\nx(%d) = %f\n",i,x[i]);
        }
}