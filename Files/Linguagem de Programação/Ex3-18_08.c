#include <stdio.h>
#include <stdlib.h>
int main()
{
    double peso;
    char categoria[12];

    printf("Digite o peso do lutador: ");
    scanf("%lf", &peso);

    if (peso < 65)
    {
        char categoria[] = "Pena";
        printf("Este lutador pesa %.1lf kg e se enquadra na categoria %s.", peso, categoria);
    }
    else if (peso >= 65 && peso < 72)
    {
        char categoria[] = "Leve";
        printf("Este lutador pesa %.1lf kg e se enquadra na categoria %s.", peso, categoria);
    }
    else if (peso >= 72 && peso < 79)
    {
        char categoria[] = "Ligeiro";
        printf("Este lutador pesa %.1lf kg e se enquadra na categoria %s.", peso, categoria);
    }
    else if (peso >= 79 && peso < 86)
    {
        char categoria[] = "Meio medio";
        printf("Este lutador pesa %.1lf kg e se enquadra na categoria %s.", peso, categoria);
    }
    else if (peso >= 86 && peso < 93)
    {
        char categoria[] = "Medio";
        printf("Este lutador pesa %.1lf kg e se enquadra na categoria %s.", peso, categoria);
    }
    else if (peso >= 93 && peso < 100)
    {
        char categoria[] = "Meio pesado";
        printf("Este lutador pesa %.1lf kg e se enquadra na categoria %s.", peso, categoria);
    }
    else if (peso >= 100)
    {
        char categoria[] = "Pesado";
        printf("Este lutador pesa %.1lf kg e se enquadra na categoria %s.", peso, categoria);
    }
    else
    {
        printf("Erro, Digite um Numero Valido");
    }
    
	printf("\n\nFim do programa\n\n");
	system("pause");

}
