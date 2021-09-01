#include<stdio.h>
#include<stdlib.h>

int main()
{
	int cont;
	
	printf("Digite Valor Inicial: ");
	scanf("%d", &cont);
	
	do
	{
		printf("%d\n", cont);
		cont++;
	} while (cont <  20);
	
	printf("\nFim do Programa\n");
	system("pause");
}
