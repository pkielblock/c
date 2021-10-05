#include <stdio.h>
#include <stdlib.h>
int main() 
{
    float n1, n2, n3;

    printf("Digite o Valor 1: ");
    scanf("%f", &n1);

    printf("Digite o Valor 2: ");
    scanf("%f", &n2);

    printf("Digite o Valor 3: ");
    scanf("%f", &n3);

    if(n1 + n2 > n3 && n1 + n3 > n2 && n2 + n3 > n1)
    {
        printf("Formam um Triangulo");
        
        if(n1 == n2 && n1 == n3)
        {
            printf("\nEquilatero");
        }
        else
        {
            if(n1 == n2 || n1 == n3 || n2 == n1)
            {
                printf("\nIsosceles");
            }
            else
            {
                printf("\nEscaleno");
            }
        }
    }
    else
    {
        printf("Nao formam um Triangulo");
    }

    printf("\n\nFim do programa\n\n");
	system("pause");

}