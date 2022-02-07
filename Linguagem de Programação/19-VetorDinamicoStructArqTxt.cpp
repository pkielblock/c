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
    exemplo *v;
    exemplo aux;
    FILE *arq;

    tamV = 0;
    v = NULL;
    arq = fopen("19VetorDinamicoStructArqTxt.txt", "r"); //Possivel usar o txt do exemplo 20.
    v = (exemplo *)malloc(tamV * sizeof(exemplo));

    while(fscanf(arq, "%d;%f;%lf;%c;", &aux.a, &aux.x, &aux.y, &aux.c) != EOF)
    {
        tamV++;
        v = (exemplo *)realloc(v, tamV * sizeof(exemplo));
        v[tamV - 1] = aux;
    }
    fclose(arq);


    printf("\nExibicao do vetor de struct V\n");
    for (i = 0; i < tamV; i++)
    {
        printf(" Elemento %d do vetor V: \n", i);
        printf(" v[%d].a = %d\n", i, v[i].a);
        printf(" v[%d].x = %.2f\n", i, v[i].x);
        printf(" v[%d].y = %.3lf\n", i, v[i].y);
        printf(" v[%d].c = %c\n", i, v[i].c);
        printf("\n");
    }
    
    free(v);
    printf("\nFim do Programa\n");
    system("pause");
    return 0;
}