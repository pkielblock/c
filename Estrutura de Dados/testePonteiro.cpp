#include <stdio.h>
#include <stdlib.h>

/*Este programa testa o uso de ponteiros */
main() {

  float x = 3, *px;
  int a = 1, *pa, *pb;

  pa = &a;
  //	px=pa;//[Error] cannot convert 'int*' to 'float*' in assignment
  //	pa=&x;//[Error] cannot convert 'float*' to 'int' in assignment
  px = (float *)malloc(sizeof(float));
  *px = x;
  *pa = 2.5;
  //	pa=10;//[Error] invalid convertion from 'int' to 'int*'
  //	px=0.75;//[Error] cannot convert double to 'float*' assignment
  printf("\n*pa=%d - a=%d\n", *pa, a);
  x = a;
  pb = pa;
  *pb = 6;
  printf("\n*px=%f - x=%f\n", *px, x);

  printf("\nx=%f - a=%d\n", x, a);
  printf("\n*pa=%d - *pb=%d   - a=%d\n", *pa, *pb, a);
}
