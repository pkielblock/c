#include<stdio.h>
#include<stdlib.h>

int main()
{
	int valor, somaP, somaN;

    valor = 1;
    somaP = 0;
    somaN = 0;

    while (valor != 0)
    {
        printf("Digite os Valores: ");
        scanf("%d", &valor);

        if (valor >= 0)
        {
            somaP = somaP + valor;
        }
        else
        {
            somaN = somaN + valor;
        }
    } 

    printf("Soma dos Positivos: %d\n", somaP);
    printf("Soma dos Negativos: %d\n", somaN);

	printf("\n\nFim do Programa\n\n");
	system("pause");
}