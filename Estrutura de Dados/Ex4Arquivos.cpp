#include <stdio.h>
#include <string.h>
int main()
{
	FILE *arq;
	double num, saida;
	int i = 0;
	arq = fopen("NumBin.bin", "wb");
	
	if (arq == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n");
		return 1;
	}

	do {
		printf("Digite um Numero: ");
		scanf("%lf", &num);
		fwrite(&num, sizeof(double), 1, arq);
		i++;
	} while (i < 10);
	
	fclose(arq);
	arq = fopen("NumBin.bin", "rb");
	
	printf("\n\n");
	
	while(fread(&saida, sizeof(double), 1, arq) == 1)
	{
		printf("%.2lf\n", saida);
	}
	
	fclose(arq);
}
