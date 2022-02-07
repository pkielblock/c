#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int soma(int a, int b); //Protótipos das funções, depois main, depois as funcões na ordem dos protótipos.

int main()
{
    int x, y;
    srand(time(NULL));
    
    x = 1000;
    y = 1000;
    while (soma(x, y) > 100)
    {
        x = rand() % 1000;
        y = rand() % 1000;
        printf("%4d + %4d = %4d\n", x, y, soma(x, y)); // estao sendo feitas duas chamadas á funcao com os mesmos parametros. Nao costuma ser a melhor ideia do ponto de vista de velocidade de execução.
    }
    
    return 0;
}

int soma(int a, int b)
{
    int r; // a, b, r -> variaveis locais em soma().
    r = a + b;
    return r;
}