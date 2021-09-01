#include<stdio.h>
#include<stdlib.h>

int main()
{
	int p, r, n, i, soma;

	printf("Digite P: ");
	scanf("%d", &p);

	printf("Digite R: ");
	scanf("%d", &r);

	printf("Digite N: ");
	scanf("%d", &n);
	
	soma = 0;
	printf("\nTermos da PG\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", p);
		soma = soma + p;
		p = p * r;
	}

	printf("\nSoma dos Termos = %d", soma);

	printf("\n\nFim do Programa\n\n");
	system("pause");
}