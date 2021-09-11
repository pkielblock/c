#include<stdio.h>
int main(void)
{
    int array[15] = {17, 4, 53, 38, 22, 40, 25, 16, 31, 64, 45, 32, 20, 12, 29};
    int a = 0, i = 0;

    do
    {
        printf("Digite o Valor: ");
        scanf("%d", &a);

        for (i = 0; i <= 14; i++)
        {
            if (a == array[i])
            {
                printf("O Valor digitado esta no Array na posicao [%d]\n", i);
            }
        }
        
    } while (a > 0);

    return 0;
}