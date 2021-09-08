#include<stdio.h>
int main(){

    int n, i, qtdePos = 0, qtdeNeg = 0;
    double x, soma = 0, media;

    do
    {
        scanf("%d", &n);
    } while (n <= 0);
    
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &x);

        if (x > 0)
        {
            soma += x;
            qtdePos++;
        }
        else
        {
            qtdeNeg++;
        }
        
    }

    if (qtdePos > 0)
    {
        media = soma / qtdePos;
    }
    else
    {
        media = 0;
    }
    
    printf("Soma dos Numeros Positivos Digitados: %.2lf\n", soma);
    printf("Media dos Numeros Positivos Digitados: %.2lf\n", media);
    printf("Numeros Negativos Digitados: %.2lf", qtdeNeg);
    return 0;
}