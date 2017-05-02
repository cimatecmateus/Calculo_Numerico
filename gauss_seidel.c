#include<stdio.h>
#include<math.h>
//#include<malloc.h>

double **matrizPrincipal, *termIndependente, *vetorSolucao, *vetorTolerancia, *vetSolucaoAnt;
int i, j, n;
int iteracoesMax = 100;


void aloc_var(int m, int n);        //Aloca memória para a matriz mxn
void gauss_Seidel(int m, int n);    //Executa método Gauss-Seidel
double somat(int i, int n);         //Multiplica linha i da matriz principal com o vetor solução
void flush_in();

int main()
{
    //void gauss_Seidel(), aloc_var();
    int s, m, n;
    s = 0;
    while(s == 0)
    {
        system("clear");
        printf("Resolução de Sistema - Gauss-Seidel \n");
        printf("\nForneça a quantidade de linhas da matriz principal: m = ");
        scanf("%d", &m);
        printf("\nForneça a quantidade de colunas da matriz principal: n = ");
        scanf("%d", &n);
        aloc_var(m,n);      //Aloca espaço da memória de acordo com o tamamnho a matriz especificada pelo usuário
        gauss_Seidel(m,n);  //Soluciona sistema especificado
        printf("\nDeseja sair do programa? (1-Sim, 0-Não)");
        printf("\nResposta: ");
        scanf("%d", &s);
    }
}

void gauss_Seidel(int m, int n)
{
    //double somat();
    int qtdIteracoes;
    double maior, tolerancia;
    char respUsuario;
    printf("\nDefina a matriz dos coeficientes %dx%d\n", m, n); 

    for(i=0; i<= m-1; i++)
    {
        for(j=0; j<=n-1; j++)
        {
            printf("\na[%d,%d]=  ",i+1,j+1);
            scanf("%lf",&matrizPrincipal[i][j]);
        }
    }

    printf("\nDefina o vetor dos termos independentes:\n");
    for(i=0; i<=m-1; i++)
    {
        printf("\nb[%d]=  ",i+1);
        scanf("%lf",&termIndependente[i]);
    }

    printf("\nDefina o vetor do chute inicial:\n");
    for(i=0; i<=n-1; i++)
    {
        printf("\nx[%d]=  ",i+1);
        scanf("%lf",&vetorSolucao[i]);
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
            scanf("%d", &iteracoesMax);
            qtdIteracoes = 0;
            while (qtdIteracoes < iteracoesMax)         //Enquanto a quantidade de iterações for menor a especificada pelo usuário
            {
                for(i=0; i<=n-1; i++)
                {
                    vetorSolucao[i] = (termIndependente[i] - somat(i,n) + matrizPrincipal[i][i]*vetorSolucao[i])/matrizPrincipal[i][i];
                }
                qtdIteracoes++;
            }
            break;

        case '2':
                printf("\nDefina a tolerancia: ");
                scanf("%lf", &tolerancia);

                do         //Enquanto a quantidade de iterações for menor a especificada pelo usuário
                {
                    for(i=0; i<=n-1; i++)
                    {
                        /* Calcula solução do sistema */
                        vetorSolucao[i] = (termIndependente[i] - somat(i,n) + matrizPrincipal[i][i]*vetorSolucao[i])/matrizPrincipal[i][i];
                        
                        vetorTolerancia[i] = fabs(vetorSolucao[i] - vetSolucaoAnt[i]);
                        //printf("\nvetorTolerancia = %f", vetorTolerancia[i]);
                        vetSolucaoAnt[i] = vetorSolucao[i];
                    }

                    maior = vetorTolerancia[0];
                    for(i=0; i<n-2; i++){
                        if(vetorTolerancia[i+1] > maior)
                            maior = vetorTolerancia[i+1];
                    }
                    //printf("\nMaior = %f", maior);
                }while (maior > tolerancia);
                break;
    }

    if(respUsuario == '1' || respUsuario == '2'){
        printf("\nA solução do sistema é: \n");
        printf("X = %f\n", vetorSolucao[0]);
        printf("Y = %f\n", vetorSolucao[1]);
        printf("Z = %f\n", vetorSolucao[2]);
    }
    else
        printf("\n\nOpção inválida!!!\n");
}

double somat(int i, int n)
{
    double soma;
    soma = 0.0;
    for(j=0; j<=n-1; j++)
    {
        soma = soma + matrizPrincipal[i][j]*vetorSolucao[j];        //Multiplica linha i da matriz principal com vetor solução
    }
    return soma;
}

void aloc_var(int m, int n)
{
    matrizPrincipal = (double **) malloc((m+1)*sizeof(double *));
    termIndependente = (double *) malloc((m+1)*sizeof(double));
    vetorSolucao = (double *) malloc((n+1)*sizeof(double));
    vetSolucaoAnt = (double *) malloc((n+1)*sizeof(double));
    vetorTolerancia = (double *) malloc((n+1)*sizeof(double));
    for(i = 0;i < n+1;i++)
    {
        matrizPrincipal[i]=(double *)malloc((n+1)*sizeof(double));
    }
}

/* Método que limpa buffer do teclado no linux */
void flush_in() { 
  int ch;
  while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}
