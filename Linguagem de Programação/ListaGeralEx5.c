#include<stdio.h>
#include<math.h>
int main(){

    int n, cont, i, resto, contOp = 0;
    double raiz;

    FILE *arq;
    arq = fopen("ListaGeralEx5.txt", "w");

    scanf("%d", &n);
    fprintf(arq, "N = %d\n", n);

    cont = 0;

    if (n == 2)
    {
        printf("Primo\n");
        fprintf(arq, "Primo\n");
    }
    else if (n % 2 == 0)
    {   
        printf("Nao e Primo\n");
        fprintf(arq, "Nao e Primo\n");
    }
    else
    {
        raiz = sqrt(n);
        i = 3;
        while (i <= raiz && resto != 0)
        {
            resto = n % i;
            i = i + 2;
            contOp++;
        }
        if (resto == 0)
        {
            printf("Nao e Primo\n");
            fprintf(arq, "Nao e Primo\n");
        }
        else
        {
            printf("Primo\n");
            fprintf(arq, "Primo\n");
        }
        printf("Qtde de Operacoes = %d", contOp);
        fprintf(arq, "Qtde de Operacoes = %d", contOp);
    }

    fclose(arq);
    return 0;
}