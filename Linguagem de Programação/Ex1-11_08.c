#include<stdio.h>
#include<stdlib.h>
int main (){
	float base,altura,area;
	printf("Digite a Base do Triangulo: ");
	scanf("%f", &base);
	printf("Digite a Altura do Triangulo: ");
	scanf("%f", &altura);
	
	area = (base*altura)/2;
	
	printf("\nArea do triangulo=%.1f\n",area);
	return 0;
	
	printf("\n\nFim do programa\n\n");
	system("pause");
}
