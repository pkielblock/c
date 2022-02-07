#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;

    printf("Digite um Numero Inteiro: ");
    scanf("%d", &n);

    if (n > 0)
    {
        printf("Positivo");
    }
    else if (n < 0)
    {
        printf("Negativo");
    }
    else if (n == 0)
    {
        printf("Igual a Zero");
    }
    else
    {
        printf("Erro, Digite um Numero Valido");
    }

    printf("\n\nFim do programa\n\n");
    system("pause");
}