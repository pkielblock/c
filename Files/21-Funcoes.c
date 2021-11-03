#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int soma(int a, int b)
{
    int r;
    r = a + b;
    return r;
}

int main()
{
    int x, y, res;
    srand(time(NULL));
    
    x = rand() % 1000;
    y = rand() % 1000;

    res = soma(x, y);
    
    printf("%d + %d = %d", x, y, res);

    return 0;
}