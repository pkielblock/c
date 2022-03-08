#include <stdio.h>
#include <stdlib.h>

/*Este programa testa o uso de ponteiros */
main() {

  float x = 3, *px;
  int a = 1, *pa, *pb;

  pa = &a;
  px = (float *)malloc(sizeof(float));
  *px = x;
  *pa = 2.5;

  printf("\n*pa=%d - a=%d\n", *pa, a);

  x = a;
  pb = pa;
  *pb = 6;

  printf("\n*px=%f - x=%f\n", *px, x);
  printf("\nx=%f - a=%d\n", x, a);
  printf("\n*pa=%d - *pb=%d   - a=%d\n", *pa, *pb, a);

}
