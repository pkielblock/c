#include<stdio.h>
int main(void)
{
    int array[10] = {}, i;

    for (i = 0;i <= 9;i++)
    {
        printf("Digite o Valor: ");
        scanf("%d", &array[i]);
        if (array[i] == 0)
        {
            printf("Você Digitou 0, Saindo Do Programa.");
            return 0;
        } 
    }

    for (i = 0;i <= 9;i++)
    {
        printf("Array[%d] = %d\n", i, array[i]);
    }

    return 0;
}