#include<stdio.h>
#include<stdlib.h>
int main(){
	float valorHora, calcNormal, calcExtra, salarioBruto;
	int horasNormais, horasExtras;
	
	printf("Digite o Valor Hora: ");
	scanf("%f", &valorHora);
	printf("Digite as Horas Normais Trabalhadas: ");
	scanf("%d", &horasNormais);
	printf("Digite as Horas Extras Trabalhadas: ");
	scanf("%d", &horasExtras);
	
	calcNormal = (valorHora*horasNormais);
	calcExtra = (valorHora*2)*horasExtras;
	
	salarioBruto = calcNormal+calcExtra;
	
	printf("\nSalario Bruto: %.1f", salarioBruto);
	return 0;
	
	printf("\n\nFim do programa\n\n");
	system("pause");
	
}
