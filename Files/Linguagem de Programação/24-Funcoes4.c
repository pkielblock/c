#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void altera(int *a, int *b)
{
    printf("\n... Inicio da Funcao altera()\n");

    *a = - *a; // a notacao *a == a[0]
    *b = - *b;

    printf("... a = %d  b = %d\n", *a, *b); // *a == conteudo do endereco a
    
    printf("... Fim da Funcao altera()\n");
}

int main()
{
    int x, y;

    printf("Digite X: ");
    scanf("%d", &x);
    printf("Digite Y: ");
    scanf("%d", &y);

    printf("\nValores Lidos\n");
    printf(" X = %d\n", x);
    printf(" Y = %d\n", y);

    altera(&x, &y);
    
    printf("\nValores Alterados\n");
    printf(" X = %d\n", x);
    printf(" Y = %d\n", y);

    printf("\nNeste programa a passagem de parametros foi por referencia.");
    printf("\nEste modo passa o endereco das variaves x, y e as alteracoes...");
    printf("\n...feitas em a e b refletem nas variaves originais.");

    return 0;
}