#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main(){
	double r;
	float area, volume, pi;
	
	printf("Digite o Valor de R: ");
	scanf("%lf", &r);
	
	pi = 3.14;
	area = pi*(pow(r, 2));
	volume = ((4*pi)*(pow(r, 3)))/3;
	
	printf("\n Area: %.3lf", area);
	printf("\n Volume: %.3lf", volume);
	
	printf("\n\nFim do programa\n\n");
	system("pause");
	
}
