#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	
	int i, tam;
	tam = rand() % 30 + 1;
	printf("Tamanho: %d\n", tam);
	int vet[tam];
	for(i=0; i<tam; i++){
		vet[i] = rand() % 30 + 1;
		printf("%d\t", vet[i]);
	}
	printf("\n\n");
	system("pause");
}
