#include <stdio.h>
#include <math.h>

int main()
{
    int n = 1, i, j, tronco;

    printf("Henrique Ernandes Rebelo\n");
    printf("1680482112038\n");
    printf("Pedro Henrique Sampaio Kielblock\n");
    printf("1680482112029\n");
    printf("Questao 2\n");

    while(n % 2 == 0 || n < 5 || n > 49){
        printf("N = ");
        scanf("%d",&n);
        if(n % 2 == 0 || n < 5 || n > 49) {
            printf(" O número %d e invalido\n", n);
        }
    }

    for(i = 1; i <= n; i += 2){
            for(j = (n - i) / 2; j > 0; j--){
                    printf(" ");
            }
            for(j = i; j > 0; j--){
                    printf("*");
            }
            for(j = (n - i) / 2; j > 0; j--){
                    printf(" ");
            }
            printf("\n");
    }
    tronco = ceil(n / 2);
    for(i = tronco; i >= 0; i--){
        if( i == 0){
            printf("|");
        }else {
            printf(" ");
        }
    }
    printf("\n");
    for(i = (n - 3) / 2; i > 0; i--){
        printf(" ");
    }
    printf("-");
    printf("-");
    printf("-");
 
    printf("\n\nFim do Programa\n\n");
    system("pause");
    return 0;
}