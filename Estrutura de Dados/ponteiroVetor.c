#include <stdio.h>

int main() {
  int i;
  
  int vet[] = {1, 200, 3, -4, 50};
  printf("&vet=%u\n", vet);

  int *pv;
  printf("pv=%u\n", pv);

  pv = vet;
  printf("pv=%u\n", pv);

  printf("Vetor\n");
  for (i = 0; i < 5; i++) {
    printf("%d ", *pv++);
  }
  printf("\n");

  printf("Vetor de Novo\n");
  for (i = 0, pv = vet; i < 5; i++) {
    printf("%d ", *pv++);
  }
  printf("\n");
  printf("pv=%u\n", pv);
}