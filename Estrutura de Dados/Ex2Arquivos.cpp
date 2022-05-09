#include <stdio.h>
#include <string.h>
int main()
{
	FILE *arq;
	char palavra[20];
	int bola, total = 0;
	
	arq = fopen("palavras.dat", "r");
	
	if (arq == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		return 1;
	}
	
	while (fscanf(arq, "%s", &palavra) == 1)
	{
		total++;
		if(strcmp("bola", palavra) == 0)
		{
			bola++;
		}
	}
	
	fclose(arq);
	printf("Total de Palavras: %d\n", total);
	printf("Palavras iguais a bola: %d", bola);
}
