#include <stdio.h>
#include <stdlib.h>

typedef struct aluno {
  int matricula;
  float nota;
} Aluno;

int main(){
  Aluno *P = malloc(sizeof(Aluno) * 3);

  for(int i = 0; i < 3; i++){
    (*(P + i)).matricula = 200 + i;
    (*(P + i)).nota = 7.0 + i;
  }

  system("clear");
  for(int i = 0; i < 3; i++)
    printf("\nMatricula: %d, Nota= %.lf", (*(P + i)).matricula, (*(P + i)).nota);
  return 0;
}