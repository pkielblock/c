#include<stdio.h>
#include<stdlib.h>

int main() {
  double A, B, C;
  printf("Digite A (numero real): ");
  scanf("%lf", &A);
  printf("O conteudo de A vale: %.3lf\n", A);  // exibe o conteudo de A com 3 casas decimais
  B = A + 10;
  printf("O conteudo de B vale: %.3lf\n", B);
  C = A * 2;
  printf("O conteudo de C vale: %.3lf\n", C);
  printf("\n\nFim do programa\n\n");
  system("pause");
}



