#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int num;
	char nome[10];
	float nota;
} Aluno;

int main()
{
	FILE *fp;
	Aluno a,b;
	a.num=100;
	strcpy(a.nome, "Maria");
	a.nota=9.5;
	fp=fopen("saidaBin.bin", "wb");
	fwrite(&a, sizeof(Aluno),1,fp); //gravação em binario
	fclose(fp);
	fp=fopen("saidaBin.bin", "rb");
	fread(&b, sizeof(Aluno),1,fp); //Leitura de binário
	printf("\nDados gravados:\nNum: %d, Nome: %s, Nota=%.1f\n\n", b.num, b.nome, b.nota);
	fclose(fp);
	return 0;
}
