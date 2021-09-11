#include<stdio.h>
int main()
{
    double notas[4];
    int i;

    for (i = 0; i <= 3; i++)
    {
        printf("Digite a Nota: ");
        scanf("%lf", &notas[i]);
    }

    for (i = 0; i <= 3; i++)
    {
        printf("Valor da Nota[%d]: %.1lf\n", i, notas[i]);
    }

    return 0;
}