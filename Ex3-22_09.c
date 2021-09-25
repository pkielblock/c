#include <stdio.h>
#include <stdlib.h>

//No Ideia Why Isn't Working.

int main(void)
{
    int min, max, *array, i = 0, a = 0;

    do
    {
        printf("Digite o Valor Min [>= 1]: ");
        scanf("%d", &min);
    } while (min < 1);

    do
    {
        printf("Digite o Valor Max [> Max]: ");
        scanf("%d", &max);
    } while (max <= min);

    printf("Digite o Valor de A: ");
    scanf("%d", &a);

    array = (int *)(malloc((max - min) * sizeof(int)));

    if (array == NULL)
    {
        printf("\nErro de alocacao de memoria\n");
        system("pause");
        exit(1);
    }

    for (i = min; i < max; i++)
    {   

        array[i] = i;
        
    }

    for ( i = min; i < max; i++)
    {
        if (i % a == 0)
        {
            printf("Valor armazenado no indice [%d] = %d\n", i, array[i]);
        }
    }
    
    free(array);
    printf("\nFim Do Programa\n");
    system("pause");
    return 0;
}