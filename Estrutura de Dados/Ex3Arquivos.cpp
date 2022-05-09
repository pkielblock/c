#include <stdio.h>
#include <string.h>
int main()
{
	FILE *arq;
	char palavra[21];
	
	arq = fopen("palavras2.txt", "w");
	
	if (arq == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		return 1;
	}
	
	do {
		printf("Digite uma Palavra: ");
		scanf("%s", &palavra);
		if(strcmp("fim", palavra) != 0)
		{
			fprintf(arq, palavra);
			fprintf(arq, "\n");
		}
	} while(strcmp("fim", palavra) != 0);
	
	fclose(arq);
	return 0;
}
