#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int P; //variavel global, pode ser usada em main() e em funcao1()

int funcao1(int a, int b)
{
    int r;
    double p; //variavel local 
    r = 2 * a + b / 6;
    P = 2.3 + r / 19.0; //vai prevalecer a variavel local
    return (r + P);
}

int main()
{
    int x, y, res; //variaveis locais em main
    srand(time(NULL));
    
    P = 10;
    res = funcao1(P, 2*P);
    printf("P = %d\n", P);
    printf("2*P = %d\n", 2*P);
    printf("Resultado da conta = %d\n", res);
    
    return 0;
}

