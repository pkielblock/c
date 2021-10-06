#include<stdio.h>
#include<stdlib.h>

int main() {
  int N, i, j;
  
  printf("Digite N: ");
  scanf("%d", &N);  
  while ( N%2 != 0 || N < 6 || N > 32 ) {
    printf("O numero %d é invalido\n\n", N);
    printf("Digite N: ");
    scanf("%d", &N);  
  }
  
  // linha 1
  printf(" ");
  for (i = 0; i < N - 2; i++)
    printf("*");
  printf("\n");
  // linha 2
  for (i = 0; i < N; i++)
    printf("*");
  printf("\n");

  // linhas de 3 até N-2
  for (j = 3; j <= N-2; j++) {
    printf("**");
    for (i = 2; i < N-2; i++)
      printf(" ");
    printf("**\n");
  }
  
  // linha N-1
  for (i = 0; i < N; i++)
    printf("*");
  printf("\n");
  // linha N
  printf(" ");
  for (i = 0; i < N - 2; i++)
    printf("*");
  printf("\n");
  
  printf("\n\nFim do programa");
  return 0;
}









