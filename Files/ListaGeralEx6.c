#include<stdio.h>
int main(){

    int n, i, qtdePos = 0;
    double x, soma = 0, media;

    FILE *arq;
    arq = fopen("ListaGeralEx6.txt", "w");

    do
    {
        scanf("%d", &n);
    } while (n <= 0);
    
    fprintf(arq, "N = %d\n\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%lf", &x);
        fprintf(arq, "X = %.2lf\n", x);

        if (x > 0)
        {
            soma += x;
            qtdePos++;
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

    fprintf(arq, "\nResultados\n");
    printf("Soma dos Numeros Positivos Digitados: %.2lf\n", soma);
    printf("Media dos Numeros Positivos Digitados: %.2lf\n", media);
    fprintf(arq, "Soma dos Numeros Positivos Digitados: %.2lf\n", soma);
    fprintf(arq, "Media dos Numeros Positivos Digitados: %.2lf\n", media);
    
    fclose(arq);
    return 0;
}