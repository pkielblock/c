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
    int i;
    srand(time(NULL));
    exemplo v[10];

    for (i = 0; i < 10; i++)
    {
        v[i].a = rand() % 100 + 1;
        v[i].x = (rand() % 1000 + 1.0) / (rand() % 100 + 1);
        v[i].y = (rand() % 10000 + 1.0) / (rand() % 2500 + 1);
        v[i].c = rand() % 26 + 65;
    }
    
    printf("\nExibicao do vetor de struct V\n");
    for (i = 0; i < 10; i++)
    {
        printf(" Elemento %d do vetor V: \n", i);
        printf(" v[%d].a = %d\n", i, v[i].a);
        printf(" v[%d].x = %.2f\n", i, v[i].x);
        printf(" v[%d].y = %.2lf\n", i, v[i].y);
        printf(" v[%d].c = %c\n", i, v[i].c);
        printf("\n");
    }
    
    printf("\nFim do Programa\n");
    system("pause");
    return 0;
}