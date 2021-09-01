#include<stdio.h>
#include<stdlib.h>

int main()
{
	int A, B;
	
	for (A = 0, B = 100; A <= B; A++, B--)
	{
		printf("A = %d\nB = %d\n", A,B);
	}
	
	printf("\nFim do Programa\n");
	system("pause");
}