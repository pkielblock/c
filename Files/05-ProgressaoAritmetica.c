#include<stdio.h>
#include<stdlib.h>

int main()
{
	int p1, r, qtde, i, a;
	
	printf("Digite P1: ");
	scanf("%d", &p1);

	do {
		printf("Digite a Razao (> 0): ");
		scanf("%d", &r);
		if (r == 0)
		{
			printf("\nR nao pode ser 0\n");
		}
	} while (r == 0);
	
	do {
		printf("Digite a Quantidade(> 1): ");
		scanf("%d", &qtde);
		if (qtde <= 1)
		{
			printf("\nQuantidade precisa ser maior que 1\n");
		}
	} while (qtde <= 1);

	printf("PA: ");

	a = p1;

	for(i = 0; i < qtde; i++)
	{
		printf("%d ", a);

		a = a + r;
	}

	printf("\nFim do Programa\n");
	system("pause");
}