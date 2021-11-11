#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void exibeVetor(int *pV, int pTamV)
{
    int i;
    for (i = 0; i < pTamV; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%6d", pV[i]);
    }
    printf("\n\n");
}


int main()
{
    int v[10] = {132, 67, 14, 74, 93, 58, 42, 86, 33, 102};
    int tamV  = 10;
    int aux, i = 0;
    bool trocou;

    printf("\nVetor nao ordenado");
    exibeVetor(v, tamV);

    do
    {
        trocou = false;
        i = 0;
        while(i < tamV - 1)
        {
            if (v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                trocou = true;
            }
            i = i + 1;
        }
    } while (trocou);

    printf("\nVetor ordenado\n");
    exibeVetor(v, tamV);
    
    return 0;
}