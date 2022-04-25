#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void semRepetidos(int v[], int tam);

int main()
{
	srand(time(NULL));
	
	int i, tam;
	tam = 10;
	printf("Tamanho: %d\n", tam);
	int vet[tam];
	
	semRepetidos(vet, tam);
	
	printf("\n\n");
	system("pause");
}

void semRepetidos(int vet[], int tam)
{
	int i, j, valor;
	vet[0] = rand() % 10 + 1;
	for( i = 1; i < tam; i++)
	{
		valor = rand() % 10 + 1;
		for(j = i; j >= 0; j--)
		{
			if(vet[j] == valor)
			{
				j = i;
				valor = rand() % 10 + 1;
			}
		}
		vet[i] = valor;
		printf("%d ", vet[i]);
	}
}
