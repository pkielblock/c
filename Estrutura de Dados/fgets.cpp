#include <stdio.h>

int main()
{
	char frase[81];
	FILE *arq;
	arq = fopen("entrada.txt", "rt");
	
	if (arq == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		return 1;
	}
	
	while(fgets(frase, 80, arq) != NULL)
	{
		printf("%s", frase);
	}
	fclose(arq);
	return 0;
}
