#include <stdio.h>

int main ()
{
	int cont = 0;
	char palavra[20];
	FILE *arq;
	arq = fopen("entrada.txt", "rt");
	
	if (arq == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		return 1;
	}
	
	while (fscanf(arq, "%s", &palavra) == 1)
	{
		cont++;
	}
	
	fclose(arq);
	printf("Numero de Palavras = %d\n", cont);
	return 0;
}
