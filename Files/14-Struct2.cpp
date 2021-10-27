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
    exemplo f;

    printf("Carga e Exibicao do Struct E\n");

    e.a = 10;
    e.x = 3.75;
    e.y = 12.518;
    e.c = 'p';

    printf(" e.a = %d\n", e.a);
    printf(" e.x = %.2f\n", e.x);
    printf(" e.y = %.3lf\n", e.y);
    printf(" e.c = %c\n", e.c);

    printf("\nCarga e Exibicao do Struct F com os mesmos dados do struct E\n");

    printf(" Antes da atribuicao\n");
    printf(" f.a = %d\n", f.a);
    printf(" f.x = %.2f\n", f.x);
    printf(" f.y = %.3lf\n", f.y);
    printf(" f.c = %c\n", f.c);

    f = e;
    printf(" Depois da atribuicao\n");
    printf(" f.a = %d\n", f.a);
    printf(" f.x = %.2f\n", f.x);
    printf(" f.y = %.3lf\n", f.y);
    printf(" f.c = %c\n", f.c);

    printf("\nFim do Programa\n");
    system("pause");
    return 0;
}