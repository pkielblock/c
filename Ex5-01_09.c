#include<stdio.h>
int main(){

    int n, cont, i, resto;

    scanf("%d", &n);

    cont = 0;

    if (n == 2)
    {
        printf("Primo\n");
    }
    else if (n % 2 == 0)
    {   
        printf("Nao e Primo\n");
    }
    else //Melhorar essa parte do else
    {
        i = 3;
        while (i < n && resto != 0)
        {
            resto = n % i;
            i = i + 2;
        }
        if (resto == 0)
        {
            printf("Nao e Primo\n");
        }
        else
        {
            printf("Primo\n");
        }
    }
    return 0;
}

    
