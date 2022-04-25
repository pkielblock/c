#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	
	int i, tam;
	//printf("Informe o tamanho do vetor: ");
	//scanf("%d", &tam);
	tam = rand() % 20 + 1;
	printf("Tamanho: %d\n", tam);
	int vet[tam];
	for(i=0; i<tam; i++){
		vet[i] = rand() % 10;
		printf("%d\t", vet[i]);
	}
	printf("\n\n");
	system("pause");
}
