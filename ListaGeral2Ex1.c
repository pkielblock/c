#include <stdio.h>
#include <stdlib.h>

void exibeVetor(double *pV, int tamV)
{
    int i;
    for (i = 0; i < tamV; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%.2lf", pV[i]);
    }
    printf("\n\n");
}

int main(void)
{
    int n, i, tamNeg, tamPos;
    double *a, *neg, *pos;

    do
    {
        printf("Digite o Valor de N [1 | 50]: ");
        scanf("%d", &n);
    } while (n < 1 && n > 50);
    
    i = 0;
    a = (double *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("Digite o Valor do Vetor[%d]: ", i);
        scanf("%lf", &a[i]);
    }
    
    neg = NULL;
    pos = NULL;
    tamNeg = 0;
    tamPos = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            tamNeg++;
            neg = (double *)(realloc(neg, tamNeg * sizeof(int)));
            neg[tamNeg - 1] = a[i];
        }
        else
        {
            tamPos++;
            pos = (double *)(realloc(pos, tamPos * sizeof(int)));
            pos[tamPos - 1] = a[i];
        }
    }

    printf("O Vetor Neg tem %d Elementos", tamNeg);
    exibeVetor(neg, tamNeg);
    printf("O Vetor Pos tem %d Elementos", tamPos);
    exibeVetor(pos, tamPos);
    
    free(a);
    free(neg);
    free(pos);
}