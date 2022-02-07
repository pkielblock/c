#include<stdio.h>
#include<stdlib.h>
int main(){
	int a, b, c, d, soma;
	float media;
	
	printf("Digite a o Numero A: ");
	scanf("%d", &a);
	printf("Digite a o Numero B: ");
	scanf("%d", &b);
	printf("Digite a o Numero C: ");
	scanf("%d", &c);
	printf("Digite a o Numero D: ");
	scanf("%d", &d);
	
	soma = (a+b+c+d);
	media = (soma)/4;
	
	printf("\nSoma dos Numeros: %d", soma);
	printf("\nMedia dos Numeros: %.1f", media);
	return 0;
	
	printf("\n\nFim do programa\n\n");
	system("pause");
	
}
