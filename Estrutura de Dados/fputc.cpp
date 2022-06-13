#include <stdio.h>
int main()
{
	FILE *arq;
	char frase[]="Fatec SaoCaetano do Sul!";
	arq=fopen("saida2.txt","wt");
	for(int i=0; frase[i]!='\0'; i++)
		fputc(frase[i],arq);//grava 1 caractere por vez
	fclose(arq);
	return 0;
}
