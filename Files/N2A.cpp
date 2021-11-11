#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

struct TDados {
    int codigo;
    char ctrlEstoque;
    double qtdEstoque;
    double custoUnitario;
    double margemLucro; 
    int anoVenda;
    int mesVenda;
    int diaVenda;
    int qtdeVendasDias;
};

void gerarVendas(TDados *pV, TDados arch, int qntdVendas, FILE *arq);

int main ()
{
    TDados *Dados;
    TDados Arquivo;
    int Tam, i, mes, ano, qtdeVendasDias, linhasFinal;
    FILE *arqEnt, *arqSai;

    srand(time(NULL));
    
    arqEnt = fopen("produtos.txt", "r");
    arqSai = fopen("saida.txt", "w");

    printf("Pedro Henrique Sampaio Kielblock\n");
    printf("Henrique Ernandes Rebelo\n");
    printf("Guilherme Peres Germano\n");
  
    do
    {
      printf("Digite o Mes: ");
      scanf("%d", &mes);
      Arquivo.mesVenda = mes;
    } while (mes < 1 || mes > 12);

    do
    {
      printf("Digite o Ano: ");
      scanf("%d", &ano);
      Arquivo.anoVenda = ano;
    } while (ano < 2016);

    do
    {
      printf("Digite a Quantidade de Vendas Realizadas: ");
      scanf("%d", &qtdeVendasDias);
      Arquivo.qtdeVendasDias = qtdeVendasDias;
    } while (qtdeVendasDias <= 0);

    linhasFinal = qtdeVendasDias * 30;

    Dados = NULL;
    Tam = 0;
    while (fscanf(arqEnt, "%d;%c;%lf;%lf;%lf;", &Arquivo.codigo, &Arquivo.ctrlEstoque, &Arquivo.qtdEstoque, &Arquivo.custoUnitario, &Arquivo.margemLucro) != EOF)  
    {
      Tam++;
      Dados = (TDados *)realloc(Dados, sizeof(TDados) * Tam);
      Dados[Tam-1] = Arquivo;
    }
    
    gerarVendas(Dados, Arquivo, linhasFinal, arqSai);

	  fclose(arqSai);
    
    free(Dados);

    printf("\n\nFim do Programa\n\n");
    system("pause");
    return 0;
}

void gerarVendas(TDados *pV, TDados arch, int qntdVendas, FILE *arq)
{
  int i;
  int randInt, randInt1, dias;
  char valor[] = "P";
  double randFloat, randFloat1, randFloatDias, vendasDias, margem;

  for(i = 0; i < qntdVendas; i++)
  {
    randFloat = (double)rand() * 1 / (double)RAND_MAX;
    if(randFloat < 0.70)
    {
      randInt = rand() % (15 + 1);
      
      printf("%d;", arch.anoVenda);
      fprintf(arq, "%d;", arch.anoVenda);
      
      if (arch.mesVenda >= 1 && arch.mesVenda <= 9)
      {
        printf("%02d;", arch.mesVenda);
        fprintf(arq, "%02d;", arch.mesVenda);
      }
      else
      {
        printf("%02d;", arch.mesVenda);
        fprintf(arq, "%02d;", arch.mesVenda);
      }

      dias = rand() % (30 - 1) + 1;
	  	printf("%02d;", dias);
      fprintf(arq, "%02d;", dias);

      printf("%d;", pV[randInt].codigo);
      fprintf(arq, "%d;", pV[randInt].codigo);
      
      if (pV[randInt].ctrlEstoque == *valor)
      {
        randFloat1 = (double)rand() * 20 / (double)RAND_MAX;
        printf("%.3lf;", randFloat1);
        fprintf(arq, "%.3lf;", randFloat1);
      }
      else 
      {
        randInt1 = rand() * (20 + 1);
        printf("%.3lf;", randInt1);
        fprintf(arq, "%.3lf;", randInt1);
      }
      
      margem = pV[randInt].custoUnitario * ((pV[randInt].margemLucro / 100) + 1); 
      printf("%.2lf;", margem);
      fprintf(arq, "%.2lf;", margem);
      printf("\n");
      fprintf(arq, "\n");
    }
  }
  printf("Arquivo 'saida.txt' gerado com sucesso.");
}