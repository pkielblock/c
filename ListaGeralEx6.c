#include<stdio.h>
int main(){

    int n, i, qtdePos = 0;
    double x, soma = 0, media;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%lf", &x);

        if (x > 0)
        {
            soma += x;
            qtdePos++;
        }
        
    }

    media = soma / qtdePos;

    printf("Soma dos Numeros Positivos Digitados: %.1lf\n", soma);
    printf("Media dos Numeros Positivos Digitados: %.1lf\n", media);
    
    return 0;
}