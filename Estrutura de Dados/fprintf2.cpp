#include <stdio.h>//grava 3 frases, uma por vez no arquivo tipo texto
int main()
{ 
	FILE *fp;
	char frase[41];
	fp=fopen("saida.txt","wt");
	for(inti=0; i<3;i++){
		printf("Digite uma frase:  ");
		gets(frase);  
		fflush(stdin);
		fprintf(fp,"%s\n", frase);//grava e pula linha
	}
	fclose(fp);
	printf("Arquivo gravado\n");
	return 0;
}
