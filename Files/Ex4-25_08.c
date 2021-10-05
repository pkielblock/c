#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x, qtde, soma, ctrlMaior, ctrlMenor;
    double media;

    soma = 0;
    qtde = 0;

    printf("Digite o Valor: ");
    scanf("%d", &x);

    ctrlMenor = x;
    ctrlMaior = x;

    while (x > 0)
    {
        qtde++;
        soma = soma + x;

        if (x < ctrlMenor)
        {
            ctrlMenor = x;
        }
        if (x > ctrlMaior)
        {
            ctrlMaior = x;
        }

        printf("Digite o Valor: ");
        scanf("%d", &x);

    } 

    if (qtde > 0)
    {
        printf("Menor Valor = %d\n", ctrlMenor);
        printf("Maior Valor = %d\n", ctrlMaior);
        printf("Quantidade = %d\n", qtde);
        printf("Soma =  %d\n", soma);
        media = double(soma) / qtde;
        printf("Media = %.3lf\n", media);
    }
    else
    {
        printf("Não foram digitados numeros positivos.");
    }

	printf("\n\nFim do Programa\n\n");
	system("pause");
}