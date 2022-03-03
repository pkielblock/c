#include <stdio.h>
#include <stdlib.h>
struct aluno{
	int RA;
	float nota;
};
typedef struct aluno Aluno;

int main(){
	Aluno P[3];
	int i;
	for(i=0;i<3;i++){
		P[i].RA=200+i;
		P[i].nota=7.0+i;
	}
	system("cls");
	printf("Matricula    Nota\n");
	for(i=0;i<3;i++) {
		printf("%9d - %5.2f\n", P[i].RA, P[i].nota);
	}
}