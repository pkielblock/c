#include <stdio.h>

int buscaVetor (int *vet, int tam, int valor);

int main()
{
	int length = 5;
	int array[length] = {1,2,3,4,5};
	int value;
	
	printf("Digite o Valor: ");
	scanf("%d", &value);
	
	printf("%d", buscaVetor(array, length, value));
}

int buscaVetor (int *vet, int tam, int valor)
{	
	if(valor == vet[tam]){
		return tam;
	} else if (tam == 0) {
		return -1;
	}
	valor = buscaVetor (vet, tam-1, valor);
}

