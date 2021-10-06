#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int min, max, i = 0, cont = 0, somaPrimos = 0, contPrimos = 0, resto;
    double raiz;

    printf("Pedro Henrique Sampaio Kielblock\n");
    printf("1680482112029\n");
    printf("Henrique Ernandes Rebelo\n");
    printf("1680482112038\n");
    printf("Questao 3\n");

    do
    {
        printf("Min: ");
        scanf("%d", &min);
    } while (min <= 1);
    
    do
    {
        printf("Max: ");
        scanf("%d", &max);
    } while (max <= min);

    for (i = min; i <= max; i++)
    {
        if (i == 2)
        {
            printf("%d\n", i);
            contPrimos++;
            somaPrimos += i;
        }
        else if (i % 2 == 0)
        {   
            
        }
        else
        {
            raiz = sqrt(i);
            cont = 3;
            while (cont <= raiz && resto != 0)
            {
                resto = i % cont;
                cont = cont + 2;
            }
            if (resto == 0)
            {

            }
            else
            {
                printf("%d\n", i);
                contPrimos++;
                somaPrimos += i;
            }
        }
    }
    
    printf("Quantidade de primos no intervalo[%d, %d] = %d\n", min, max, contPrimos);
    printf("Soma dos primos no intervalo[%d, %d] = %d", min, max, somaPrimos);

    printf("\n\nFim do Programa\n\n");
    system("pause");
    return 0;
}