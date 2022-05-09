#include <stdio.h>
#include <string.h>
int main()
{
	FILE *arq;
	double num;
	int i = 0;
	arq = fopen("NumBin", "w");
	
	if (arq == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		return 1;
	}

	do {
		printf("Digite um Numero: ");
		scanf("%lf", &num);
		fprintf(arq, "%.2lf", num);
		fprintf(arq, "\n");
		i++;
	} while (i < 10);
	
	fclose(arq);
	arq = fopen("NumBin", "r");
	
	printf("\n\n");
	
	while(fscanf(arq, "%lf", &num) != EOF)
	{
		printf("%.2lf\n", num);
	}
	
	fclose(arq);
}
