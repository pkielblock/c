#include <stdio.h>
#include <stdlib.h>
//uso do fseek

int main()
{
	FILE *fp;
	int num[20];
	int vet[5];
	int ultimo = 0;
	
	fp=fopen("vetBin.bin","rb");
	
	if(fp != NULL)
	{
		fseek(fp, -1*sizeof(int), SEEK_END);
		fread(&ultimo, sizeof(int), 1, fp);
		ultimo++;
	} 
	
	fclose(fp);
	
	for(int i=0;i < 20;i++)
	{
		num[i]=i+ultimo;
	}
	
	fp = fopen("vetBin.bin", "a+b");
	fwrite(num, sizeof(int), 20, fp);//gravacao em binario
	fseek(fp,-5*sizeof(int), SEEK_END); //SEEK_CUR ou SEEK_SET
	
	rewind(fp);
	printf("\nVetor resultante\n");
	while(fread(vet, sizeof(int), 5, fp))
	{
		for(int i=0;i<5;i++)
		{
			printf("%d\t",vet[i]);
		}
		printf("\n\n");
	}
	
	fclose(fp);
	return 0;
}
