#include<stdio.h>
#include<stdlib.h>
int main(){
	int a, b, r;
	
	printf("Digite o Inteiro A: ");
	scanf("%d", &a);
	printf("Digite o Inteiro B: ");
	scanf("%d", &b);
	
	r = ((3*a)+(2*b))/(a+b);
	
	printf("R: %d", r);
	return 0;
	
	printf("\n\nFim do programa\n\n");
	system("pause");
}
