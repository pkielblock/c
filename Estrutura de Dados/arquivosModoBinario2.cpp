#include <stdio.h>
#include <stdlib.h>
//uso do fseek

int main()
{
	FILE *fp;
	int num[20];
	int vet[5];
	for(int i=0;i<20;i++)
		num[i]=i;
	fp=fopen("vetBin.bin","wb");
	fwrite(num, sizeof(int),20,fp);//gravacao em binario
	fclose(fp);
	fp=fopen("vetBin.bin","rb");
	fseek(fp,-5*sizeof(int),SEEK_END); //SEEK_CUR ou SEEK_SET
	fread(vet, sizeof(int),5,fp);//leitura de binario
	printf("\nVetor resultante\n");
	for(int i=0;i<5;i++)
		printf("%d\t",vet[i]);
	printf("\n\n");
	fclose(fp);
	return 0;
}
