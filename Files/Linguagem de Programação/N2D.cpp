#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct Salarios
{
  double salarios;
};

int main()
{
  Salarios arq;
  FILE *salarios, *calculos;
  double salBruto, aliqINSS, valINSS, aliqIR, valIR, salLiquido;


  salarios = fopen("salario.txt", "r");
  calculos = fopen("calculos.txt", "w");
  
  printf("Pedro Henrique Sampaio Kielblock\n");
  printf("Henrique Ernandes Rebelo\n");
  printf("Guilherme Peres Germano\n");
  printf("Maria Eduarda\n");
  printf("\n");

  printf("Bruto		AliqINSS	Val.INSS	Base I.R    AliqIR		Val.IR		Liquido\n");
  fprintf(calculos, "Bruto		AliqINSS	Val.INSS	Base I.R    AliqIR		Val.IR		Liquido\n");
  while(fscanf(salarios, "%lf", &arq.salarios) != EOF)
  {
    salBruto = arq.salarios;
    if (salBruto >= 5839.46)
    {
      aliqINSS = (64234 / salBruto) / 100;
      valINSS = 642.34;
      salLiquido = salBruto - 642.34;
      if (salBruto - valINSS < 1903.98)
      {
        aliqIR = 0;
        valIR = (salBruto - valINSS);
      }
      else if(salBruto - valINSS >= 1903.99 && salBruto - valINSS <= 2826.65)
      {
        aliqIR = 0.75;
        valIR = ((salBruto - valINSS) * aliqIR) - 142.80;
      }
      else if(salBruto - valINSS >= 2826.66 && salBruto - valINSS <= 3751.05)
      {
        aliqIR = 0.15;
        valIR = ((salBruto - valINSS) * aliqIR) - 354.80;
      }
      else if(salBruto - valINSS >= 3751.06 && salBruto - valINSS <= 4664.68)
      {
        aliqIR = 0.225;
        valIR = ((salBruto - valINSS) * aliqIR) - 636.36;
      }
      else
      {
        aliqIR = 0.275;
        valIR = ((salBruto - valINSS) * aliqIR) - 869.36;
      }
      if(valIR <= 10)
	    {
      	      valIR = 0;
	    }
      printf("%.2lf 	%.2lf	 	%.2lf		%.2lf		%.2lf		%.2lf		%.2lf", salBruto, aliqINSS * 100, valINSS, salLiquido, aliqIR * 100, valIR, salLiquido - valIR);
      fprintf(calculos, "%.2lf 	%.2lf	 	%.2lf		%.2lf		%.2lf		%.2lf		%.2lf", salBruto, aliqINSS * 100, valINSS, salLiquido, aliqIR * 100, valIR, salLiquido - valIR);
    }
    else if(salBruto <= 1751.81)
    {
      aliqINSS = 0.08;
      valINSS = salBruto * aliqINSS;
      salLiquido = (salBruto - valINSS);
      if (salBruto - valINSS <= 1903.98)
      {
        aliqIR = 0;
        valIR = 0.00;
      }
      else if(salBruto - valINSS >= 1903.99 && salBruto - valINSS <= 2826.65)
      {
        aliqIR = 0.075;
        valIR = ((salBruto - valINSS) * aliqIR) - 142.80;
      }
      else if(salBruto - valINSS >= 2826,66 && salBruto - valINSS <= 3751.05)
      {
        aliqIR = 0.15;
        valIR = ((salBruto - valINSS) * aliqIR) - 354.80;
      }
      else if(salBruto - valINSS >= 3751.06 && salBruto - valINSS <= 4664.68)
      {
        aliqIR = 0.225;
        valIR = ((salBruto - valINSS) * aliqIR) - 636.36;
      }
      else
      {
        aliqIR = 0.275;
        valIR = ((salBruto - valINSS) * aliqIR) - 869.36;
      }
      if(valIR <= 10)
	  {
            valIR = 0;
	  }
      printf("%.2lf 	%.2lf	 	%.2lf		%.2lf		%.2lf		%.2lf		%.2lf", salBruto, aliqINSS * 100, valINSS, salLiquido, aliqIR * 100, valIR, salLiquido - valIR);
      fprintf(calculos, "%.2lf 	%.2lf	 	%.2lf		%.2lf		%.2lf		%.2lf		%.2lf", salBruto, aliqINSS * 100, valINSS, salLiquido, aliqIR * 100, valIR, salLiquido - valIR);
    }
    else if(salBruto > 1751.81 && salBruto <= 2919.72)
    {
      aliqINSS = 0.09;
      valINSS = salBruto * aliqINSS;
      salLiquido = (salBruto - valINSS);
      if (salBruto - valINSS <= 1903.98)
      {
        aliqIR = 0;
        valIR = 0.00;
      }
      else if(salBruto - valINSS >= 1903.99 && salBruto - valINSS <= 2826.65)
      {
        aliqIR = 0.075;
        valIR = ((salBruto - valINSS) * aliqIR) - 142.80;
      }
      else if(salBruto - valINSS >= 2826.66 && salBruto - valINSS <= 3751.05)
      {
        aliqIR = 0.15;
        valIR = ((salBruto - valINSS) * aliqIR) - 354.80;
      }
      else if(salBruto - valINSS >= 3751.06 && salBruto - valINSS <= 4664.68)
      {
        aliqIR = 0.225;
        valIR = ((salBruto - valINSS) * aliqIR) - 636.36;
      }
      else
      {
        aliqIR = 0.275;
        valIR = ((salBruto - valINSS) * aliqIR) - 869.36;
      }
      if(valIR <= 10)
	  {
      	    valIR = 0;
	  }
      printf("%.2lf 	%.2lf	 	%.2lf		%.2lf		%.2lf		%.2lf		%.2lf", salBruto, aliqINSS * 100, valINSS, salLiquido, aliqIR * 100, valIR, salLiquido - valIR);
      fprintf(calculos, "%.2lf 	%.2lf	 	%.2lf		%.2lf		%.2lf		%.2lf		%.2lf", salBruto, aliqINSS * 100, valINSS, salLiquido, aliqIR * 100, valIR, salLiquido - valIR);
    }
    else if(salBruto > 2919.72 && salBruto <= 5839.45)
    {
      aliqINSS = 0.11;
      valINSS = salBruto * aliqINSS;
      salLiquido = (salBruto - valINSS);
      if (salBruto - valINSS < 1903.98)
      {
        aliqIR = 0;
        valIR = 0.00;
      }
      else if(salBruto - valINSS >= 1903.99 && salBruto - valINSS <= 2826.65)
      {
        aliqIR = 0.075;
        valIR = ((salBruto - valINSS) * aliqIR) - 142.80;
      }
      else if(salBruto - valINSS >= 2826.66 && salBruto - valINSS <= 3751.05)
      {
        aliqIR = 0.15;
        valIR = ((salBruto - valINSS) * aliqIR) - 354.80;
      }
      else if(salBruto - valINSS >= 3751.06 && salBruto - valINSS <= 4664.68)
      {
        aliqIR = 0.225;
        valIR = ((salBruto - valINSS) * aliqIR) - 636.36;
      }
      else
      {
        aliqIR = 0.275;
        valIR = ((salBruto - valINSS) * aliqIR) - 869.36;
      }
      if(valIR <= 10)
	    {
              valIR = 0;
	    }
      printf("%.2lf 	%.2lf	 	%.2lf		%.2lf		%.2lf		%.2lf		%.2lf", salBruto, aliqINSS * 100, valINSS, salLiquido, aliqIR * 100, valIR, salLiquido - valIR);
      fprintf(calculos, "%.2lf 	%.2lf	 	%.2lf		%.2lf		%.2lf		%.2lf		%.2lf", salBruto, aliqINSS * 100, valINSS, salLiquido, aliqIR * 100, valIR, salLiquido - valIR);
    }
    printf("\n");
    fprintf(calculos, "\n");
  }

  fclose(salarios);
  fclose(calculos);
  printf("\n\nFim do Programa\n\n");
  system("pause");
  return 0;
}
