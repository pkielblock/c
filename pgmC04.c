#include<stdio.h>
#include<stdlib.h>

int main() {
  int A, B, RM;
  int Soma, Subt, Mult, DiviI;
  double DiviR;

  printf("Digite A: ");
  scanf("%d", &A);
  printf("Digite B: ");
  scanf("%d", &B);

  printf("Resultados:\n");
  Soma = A + B;
  printf("  soma            = %d\n", Soma);
  Subt = A - B;
  printf("  subtracao       = %d\n", Subt);
  Mult = A * B;
  printf("  multiplicacao   = %d\n", Mult);
  DiviI = A / B;
  printf("  divisao inteira = %d\n", DiviI);
  DiviR = double(A) / B;     // o typecast double(A) é necessário nesta linha para que o resultado produzido seja um número real
  printf("  divisao real    = %lf\n", DiviR);

  printf("\nResultados mistos p/ A = %d e B = %d:\n", A, B);
  RM = 2 * A + B;
  printf("2 * A + B = %d\n", RM);
  RM = 2 * (A + B);
  printf("2 * (A + B) = %d\n", RM);
  RM = 0.5 * A + 0.5 * B;
  printf("0.5 * A + 0.5 * B = %d este eh o resultado inteiro\n", RM);
  printf("  o resultado com decimais seria = %lf\n", 0.5 * double(A) + 0.5 * double(B));
  RM = 2 + A * B;
  printf("2 + A * B = %d\n", RM);
  RM = (2 + A) * B;
  printf("(2 + A) * B = %d\n", RM);

  printf("\n\nFim do programa\n\n");
  system("pause");
}



