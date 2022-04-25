#include <stdio.h>

int soma(int a, int b);

int main()
{
	int n1, n2;
	printf("Digite N1: ");
	scanf("%d", &n1);
	printf("Digite N2: ");
	scanf("%d", &n2);
	
	printf("%d", soma(n1, n2));
}

int soma(int a, int b)
{
	int result;
	
	if(a == b){
		return a;
	}
	result = a + soma(a+1, b);
	return result;
}
