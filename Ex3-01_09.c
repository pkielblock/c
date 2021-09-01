#include<stdio.h>
int main(){

    int n, i;
    double x, menor, maior ;

    printf("Digite o Valor de N: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Digite o Valor de X: ");
        scanf("%lf", &x);
        
        if (i == 0 || x < menor)
        {
            menor = x;
        }
        if (i == 0 ||x > maior)
        {
            maior = x;
        }
    }
    
    printf("Menor: %.1lf\n", menor);
    printf("Maior: %.1lf\n", maior);
    

    return 0;
}