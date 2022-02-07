#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//Struct - Forma de agregar dados variados em um único elemento.
//Para este uso só irá funcionar se estiver com o compilador de C++, usar extensão .cpp

struct exemplo
{
    int a;
    float x;
    double y;
    char c;
};

int main()
{
    int tamV, i;
    srand(time(NULL));
    exemplo *v;
    

    printf("Digite o Tamanho do Vetor de Structs: ");
    scanf("%d", &tamV);

    v = (exemplo *)malloc(tamV * sizeof(exemplo));

    for (i = 0; i < tamV; i++)
    {
        v[i].a = rand() % 100 + 1;
        v[i].x = (rand() % 1000 + 1.0) / (rand() % 100 + 1);
        v[i].y = (rand() % 10000 + 1.0) / (rand() % 2500 + 1);
        v[i].c = rand() % 26 + 65;
    }
    
    printf("\nExibicao do vetor de struct V\n");
    for (i = 0; i < tamV; i++)
    {
        printf(" Elemento %d do vetor V: \n", i);
        printf(" v[%d].a = %d\n", i, v[i].a);
        printf(" v[%d].x = %.2f\n", i, v[i].x);
        printf(" v[%d].y = %.2lf\n", i, v[i].y);
        printf(" v[%d].c = %c\n", i, v[i].c);
        printf("\n");
    }
    
    free(v);
    printf("\nFim do Programa\n");
    system("pause");
    return 0;
}