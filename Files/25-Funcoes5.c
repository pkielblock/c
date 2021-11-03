#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibeVetor(int *pV, int pTamV);
void alteraVetor(int *pV, int pTamV, int valor);
int *geraVetor(int tamV, int limite);

int main()
{
    int tamV;
    int *v;

    srand(time(NULL));
    printf("Digite TamV: ");
    scanf("%d", &tamV);

    v = geraVetor(tamV, 1000);
    
    printf("Vetor Original Gerado\n");
    exibeVetor(v, tamV);

    printf("Vetor Alterado Somando 100 a Cada Elemento\n");
    alteraVetor(v, tamV, 100);
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

void alteraVetor(int *pV, int pTamV, int valor)
{
    int i;
    for (i = 0; i < pTamV; i++)
    {
        pV[i] = pV[i] + valor;
    }
}

int *geraVetor(int tamV, int limite)
{
    int *gerado;
    int i;
    gerado = (int *)malloc(sizeof(int) * tamV);

    for (i = 0; i < tamV; i++)
    {
        gerado[i] = rand() % limite;
    }

    return gerado;
}