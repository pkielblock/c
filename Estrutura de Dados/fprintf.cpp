#include <stdio.h>

int main()
{
	
	FILE *fp;
	char frase[] = "Fatec Sao Caetano";
	fp=fopen("saida.txt","wt");
	for(inti=0; frase[i]!='\0';i++){
		fprintf(fp,"%c", frase[i]);
	}
	fclose(fp);
	printf("Arquivo gravado\n");
	return 0;
}
