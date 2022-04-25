#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	
	float a;
	int b;
	int c;
	
	//0 - 9
	b = rand() % 10;
	
	//1 - 10
	c = rand() % 10 + 1;
	
	//Float
	a = rand() % 101 * 0.1;
	
	printf("%.2lf\n", a);
	printf("%d\n", b);
	printf("%d\n", c);
}
