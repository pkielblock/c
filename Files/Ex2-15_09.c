#include<stdio.h>
#define tamMax 10
int main(void)
{
    int array[tamMax], i, x, tamEfetivo;

    i = 0;
    tamEfetivo = 0;

    printf("Digite o Valor: ");
    scanf("%d", &x);

    while (tamEfetivo < tamMax && x != 0)
    {   
        array[i] = x;
        tamEfetivo++;
        if (tamEfetivo < tamMax)
        {
            printf("Digite o Valor: ");
            scanf("%d", &x);
        }
        else
        {
            printf("Vetor Totalmente Preenchido\n");
        }
    }

    for (i = 0; i < tamEfetivo; i++)
    {
        printf("Array[%d] = %d\n", i, array[i]);
    }

    return 0;
}