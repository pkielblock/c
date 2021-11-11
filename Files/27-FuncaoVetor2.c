#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void exibeVetor(int *pV, int pTamV);
void ordenaVetor(int *pV, int pTamV);

int main()
{
    int v[10] = {132, 67, 14, 74, 93, 58, 42, 86, 33, 102};
    int tamV  = 10;
    int n;

    printf("\nVetor nao ordenado");
    exibeVetor(v, tamV);

    ordenaVetor(v, tamV);

    printf("\nVetor ordenado\n");
    exibeVetor(v, tamV);
    
    return 0;
}

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


void ordenaVetor(int *pV, int pTamV)
{

    int aux, i;
    bool trocou;

    do
    {
        trocou = false;
        i = 0;
        while(i < pTamV - 1)
        {
            if (pV[i] > pV[i+1])
            {
                aux = pV[i];
                pV[i] = pV[i + 1];
                pV[i + 1] = aux;
                trocou = true;
            }
            i = i + 1;
        }
    } while (trocou);
}

