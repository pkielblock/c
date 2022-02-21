#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int RA;
	float nota;
} Aluno;

int main(){
	Aluno *P, *PA;
	P=(Aluno*)malloc(sizeof(Aluno)*3);//espaço para 3 alunos
	PA=P;//PA ponteiro auxiliar 
	int i;
	for(i=0;i<3;i++){
		P->RA=200+i;
		P->nota=7.0+i;
		P++;
	}
	system("cls");
	printf("Matricula    Nota\n");
	//restara o ponteiro para a posição inicial 
	for(P=PA,i=0;i<3;i++,P++)
	   printf("%9d - %5.2f\n", P->RA, P->nota);
	   //printf("%9d - %5.2f\n", (*P).RA, (*P).nota);
}
