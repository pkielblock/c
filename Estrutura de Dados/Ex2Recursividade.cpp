#include <stdio.h>

double jurosCompostos(double valor, double taxa, int meses);

int main()
{
	double value, tax;
	int months;
	printf("Digite o Valor: ");
	scanf("%lf", &value);
	printf("Digite a Taxa: ");
	scanf("%lf", &tax);
	printf("Digite os Meses: ");
	scanf("%d", &months);
	
	printf("%.0lf", jurosCompostos(value, tax, months));
}

double jurosCompostos(double valor, double taxa, int meses)
{
	double result;
	
	result = valor;
	if(meses == 0){
		return result;
	}
	result = jurosCompostos(valor += valor * (taxa / 100), taxa, meses-1);
}

