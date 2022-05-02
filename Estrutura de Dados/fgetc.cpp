#include <stdio.h>

int main ()
{
	int c, nLinhas = 0;
	FILE *arq;
	arq = fopen("entrada.txt", "rt");
	
	if (arq == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		return 1;
	}
	
	while((c = fgetc(arq)) != EOF)
	{
		if(c == '\n')
		{
			nLinhas++;
		}
	}
	fclose(arq);
	
	printf("Numero de linhas = %d\n", nLinhas);
	return 0;
}
