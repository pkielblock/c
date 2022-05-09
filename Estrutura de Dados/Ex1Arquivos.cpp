#include <stdio.h>

int main()
{
	FILE *arq;
	int soma, total;
	arq = fopen("numeros.txt", "r");
	
	if (arq == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		return 1;
	}
	
	while (fscanf(arq, "%d", &soma) != EOF)
	{
		total += soma;
	}
	
	fclose(arq);
	printf("Soma dos numeros: %d", total);
}
