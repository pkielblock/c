#include<stdio.h>
#define tam 5

int main()
{
    int a[tam] = {19, 23, 29, 31, 37};
    int i;

    printf("Ordem Direta\n");
    for (i = 0; i < tam; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nOrdem Inversa\n");
    for (i = tam - 1; i >= 0; i--)
    {
        printf("%d ", a[i]);
    }

    return 0;
}