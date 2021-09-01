#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
	
    printf("Digite um Numero Inteiro: ");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        printf("\nPar");
    }
    else if (n % 2 != 0)
    {
        printf("\nImpar");
    }
    else
    {
        printf("Erro, Digite um Numero Valido");
    }

    printf("\n\nFim do programa\n\n");
    system("pause");
}
