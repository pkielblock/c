#include <stdio.h>

int main(){
	int vet[4]={1,2,3,4};
	int i;
	printf("Endereco do &vet=%u\n",vet);
	int *pv;//ponteiro do tipo inteiro

	pv=vet; //pv=&vet[0]
	printf("Endereco contido em pv=%u\n",pv);
	printf("Vetor\n");
	for(i=0; i<4; i++, pv++)
	   printf("%d - %d\n",*pv, pv);
	printf("\n");
	/*
	for(i=0;i<4;i++)
	   printf("%d - %d\n",pv[i], &pv[i]);
	printf("\n");
	*/
	printf("Endereco contido em pv=%u\n",pv);
}
