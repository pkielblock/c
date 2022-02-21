#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int matricula;
	char nome[21];
	float nota;
} Aluno;

int main(){
	Aluno *P, *PA;
	P=(Aluno*)malloc(sizeof(Aluno)*3);//espa�o para 3 alunos
	PA=P;//PA ponteiro auxiliar 
	int i;
	for(i=0;i<3;i++,P++){
	   printf("Informe sua matricula: ");
	   scanf("%d",&P->matricula);
	   printf("Informe seu nome: ");
	   fflush(stdin);
	   gets(P->nome);
	   printf("Informe sua nota: ");
	   scanf("%f",&P->nota);
	   printf("\n");
	   
	}
	system("cls");
	printf("Matricula    Nome               Nota\n");
	//restara o ponteiro para a posi��o inicial 
	for(P=PA,i=0;i<3;i++,P++)
	   printf("%9d - % -15s  - %5.2f\n", P->matricula, P->nome, P->nota);
	   //printf("%9d - %5.2f\n", (*P).RA, (*P).nota);
}
