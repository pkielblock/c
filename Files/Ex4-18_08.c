#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    float A,B,C;
    float delta, x1,x2;
    
    printf("Digite o Coeficiente A: ");
    scanf("%f",&A);

    printf("Digite o Coeficiente B: ");
    scanf("%f",&B);

    printf("Digite o Coeficiente C: ");
    scanf("%f",&C);

    delta = B*B - 4.*A*C;

    if (delta > 0)
    {
        x1 = (-B + sqrt(delta))/(2.*A);
        x2 = (-B - sqrt(delta))/(2.*A);
        printf("A equacao: %.1f X^2 + %.1f X + %.1f", A, B, C);
        printf("As raizes reais sao:\nX' = %.1f\nX'' = %.1f", x1, x2);
    }
    else if (delta == 0)
    {
        x1 = (-B / (2.*A));
        printf("A equacao: %.1f X^2 + %.1f X + %.1f", A, B, C);
        printf("A raiz real e: %.1f", x1);
    }
    else
    {
        printf("Nao existem raizes reais");
    }

	printf("\n\nFim do programa\n\n");
	system("pause");
}
