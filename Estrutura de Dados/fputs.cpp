#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char frase[]="Programa��o em Linguagem C ";
	char endline='\n';
	fp=fopen("saida3.txt","wt");
	fputs(frase,fp);
	fputc(endline,fp);//grava o caractere de  pula linha
	fputs(frase,fp);
	fclose(fp);
	return 0;
}
