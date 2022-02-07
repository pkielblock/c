#include<stdio.h>
#include<stdlib.h>

//Basicamente printando a tabela ascii atravez de um for. Mostrando que um char pode ser representado por um int.


int main()
{
    unsigned char a;

    for (a = 32; a <= 254; a++)
    {
        printf("Print de A como Inteiro: %d | Como caracter: %c\n", a, a);
    }

    printf("\nFim do Programa\n");
    return 0;
}