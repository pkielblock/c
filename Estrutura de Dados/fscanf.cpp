#include <stdio.h>

int main ()
{
	int nl = 0;
	char c;
	FILE *arq;
	arq = fopen("entrada.txt", "rt");
	
	if (arq == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		return 1;
	}
	
	while (fscanf(arq, "%c", &c) == 1)
	{
		if (c == '\n')
		{
			nl++;
		}
	}
	fclose(arq);
	printf("Numero de Linhas = %d\n", nl);
	return 0;
}
