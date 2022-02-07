#include<stdio.h>
#include<stdlib.h>

//Struct - Forma de agregar dados variados em um único elemento.
//Para este uso só irá funcionar se estiver com o compilador de C++, usar extensão .cpp

struct exemplo{
    int a;
    float x;
    double y;
    char c;
};

int main(){

    exemplo e;
    e.a = 10;
    e.x = 3.75;
    e.y = 12.518;
    e.c = 'p';

    printf("e.a = %d\n", e.a);
    printf("e.x = %.2f\n", e.x);
    printf("e.y = %.3lf\n", e.y);
    printf("e.c = %c\n", e.c);

    printf("\n\nFim do Programa\n\n");
    system("pause");
    return 0;
}