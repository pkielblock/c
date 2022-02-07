#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n, *array, i;

    i = 0;

    printf("Digite o Tamanho do Vetor: ");
    scanf("%d", &n);

    srand(time(NULL));
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

    free(array);
    printf("\nFim Do Programa\n");
    system("pause");
    return 0;
}