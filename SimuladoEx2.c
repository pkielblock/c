#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n , i = 0;

    do
    {
        printf("Entrada: N = ");
        scanf("%d", &n);

        if (n % 2 != 0 || n < 6 || n > 32)
        {
            printf("O numero %d e invalido\n", n);
        }
    } while (n % 2 != 0 || n < 6 || n > 32);
    

    printf("Saida\n");


    //Cima 1
    for (i = 0; i < n - 3; i++)
    {
        printf(" ");

        for (i = 0; i < n - 2; i++)
        {
            printf("*");
        }
    }

    printf("\n");

    //Cima 2
    for (i = 0; i < n; i++)
    {
        printf("*");
    }
    
    printf("\n");

    //Nao consegui fazer o Meio
    
    //Baixo 1
    for (i = 0; i < n; i++)
    {
        printf("*");
    }
    
    printf("\n");

    //Baixo 2
    for (i = 0; i < n - 3; i++)
    {
        printf(" ");

        for (i = 0; i < n - 2; i++)
        {
            printf("*");
        }
    }

    //printf("\n\nFim Do Programa\n\n");
    //system("pause");
    return 0;
}