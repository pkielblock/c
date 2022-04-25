#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void buscaRepetidos(int v[], int valor, int tam);

int main()
{
	srand(time(NULL));
	
	int i, tam, valor;
	tam = rand() % 10 + 1;
	printf("Tamanho: %d\n", tam);
	int vet[tam];
	for(i=0; i<tam; i++){
		vet[i] = rand() % 10 + 1;
		printf("%d\t", vet[i]);
	}
	printf("\nDigite o Valor a Ser Buscado: ");
	scanf("%d", &valor);
	
	buscaRepetidos(vet, valor, tam);
	
	printf("\n\n");
	system("pause");
}

void buscaRepetidos(int v[], int valor, int tam)
{
	int i, achou = 0;
	
	for (i = 0; i < tam; i++)
	{
		if(valor == v[i])
		{
			printf("\nValor %d achado na posicao %d\n", valor, i);
			achou = 1;
		}
	}
	if(!achou)
	{
		printf("Valor nao encontrado");
	}
}
