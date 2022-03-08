#include <stdio.h>
#include <stdlib.h>

/*Este programa mostra a aloca��o de endere�os do compilador DevC++ */
main() {

  int a = 1, b = 2, c = 3, d = 4;

  int *p;

  p = (int *)malloc(sizeof(int));

  *p = 25;

  char nome[15] = "Fatec";

  printf("Alocacao de variaveis\n");

  printf("\na=%d - &a=%u\n", a, &a);

  printf("\nb=%d - &b=%u\n", b, &b);

  printf("\nc=%d - &c=%u\n", c, &c);

  printf("\nd=%d - &d=%u\n\n", d, &d);

  printf("\np=%u - &p=%d   *p=%d\n\n", p, &p, *p);

  printf("\nnome=%s - &nome=%d\n", nome, &nome);

}
