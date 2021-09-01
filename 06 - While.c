#include<stdio.h>
#include<stdlib.h>

int main()
{
	int cont;
	
	printf("Digite Valor Inicial: ");
	scanf("%d", &cont);
	
	while (cont <  20)
	{
		printf("%d\n", cont);
		cont++;
	} 
	
	printf("\nFim do Programa\n");
	system("pause");
}
