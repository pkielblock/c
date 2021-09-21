#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, *array, i;

    i = 0;

    printf("Digite o Tamanho do Vetor: ");
    scanf("%d", &n);

    array = (int *)(malloc(n * sizeof(int)));

    if (array == NULL)
    {
        printf("\nErro de alocacao de memoria\n");
        system("pause");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }

    for (i = 0; i < n; i++)
    {
        printf("Valor armazenado no indice [%d] = %d\n", i, array[i]);
    }

    printf("\nFim Do Programa\n");
    system("pause");
    return 0;
}