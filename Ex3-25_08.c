#include<stdio.h>
#include<stdlib.h>

int main()
{
	int valor;

    printf("Digite o Valor: ");
    scanf("%d", &valor);

    while (valor != 0)
    {
        if (valor > 0)
        {
            printf("Positivo\n");
        }
        else if (valor < 0)
        {
            printf("Negativo\n");
        }

        printf("Digite o Valor: ");
        scanf("%d", &valor);
    } 

	printf("\n\nFim do Programa\n\n");
	system("pause");
}