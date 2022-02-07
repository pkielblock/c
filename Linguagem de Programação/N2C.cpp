#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct produtos
{
  int codigo;
  int qtdInicio;
  int qtdMinima;
};

struct vendas
{
  int codigo;
  int qtd;
  int situacao;
  int canal;
};

int main()
{
  produtos arqProdutos;
  vendas arqVendas;
  FILE *vendas, *produtos, *transfere, *divergencias, *totcanais;
  int qtdVendas, transferencia, necessidade, estoquePos, linha, representantes, website, android, iphone;
  bool existe;
  
  produtos = fopen("c1_produtos.txt", "r");
  vendas = fopen("c1_vendas.txt", "r");
  transfere = fopen("c1_transfere.txt", "w");
  divergencias = fopen("c1_divergencias.txt", "w");
  totcanais = fopen("c1_totcanal.txt", "w");

  printf("Pedro Henrique Sampaio Kielblock\n");
  printf("Henrique Ernandes Rebelo\n");
  printf("Guilherme Peres Germano\n");
  printf("Maria Eduarda\n");

  printf("\nNecessidade de Transferencia Armazem para CO\n\n");
  fprintf(transfere, "Necessidade de Transferencia Armazem para CO\n\n");
  printf("Produto	 QtCO    QtMin   QtVendas    Estq.apos Vendas    Necess. 	Transf. de Arm p/ CO\n");
  fprintf(transfere, "Produto	 QtCO    QtMin   QtVendas    Estq.apos Vendas    Necess. 	Transf. de Arm p/ CO\n");
  
  while (fscanf(produtos, "%d;%d;%d", &arqProdutos.codigo, &arqProdutos.qtdInicio, &arqProdutos.qtdMinima) != EOF)
  { 
    while( fscanf(vendas, "%d;%d;%d;%d", &arqVendas.codigo, &arqVendas.qtd, &arqVendas.situacao, &arqVendas.canal) != EOF)
    {
      if(arqProdutos.codigo == arqVendas.codigo)
      {
      	if(arqVendas.situacao == 100 || arqVendas.situacao == 102)
		{
      		qtdVendas += arqVendas.qtd;
          
          if (arqVendas.canal == 1)
          {
            representantes += arqVendas.qtd;
          }
          else if (arqVendas.canal == 2)
          {
            website += arqVendas.qtd;
          }
          else if (arqVendas.canal == 3)
          {
            android += arqVendas.qtd;
          }
          else if (arqVendas.canal == 4)
          {
            iphone += arqVendas.qtd;
          }
		}
      }
    }

    estoquePos = arqProdutos.qtdInicio - qtdVendas;

    if(estoquePos < arqProdutos.qtdMinima)
    {
    	necessidade = arqProdutos.qtdMinima - estoquePos;
    }
    else 
    {
      necessidade = 0;
    }

    if (necessidade > 1 && necessidade < 10)
    {
      transferencia = 10;
    }
    else
    {
      transferencia = necessidade;
    }

    printf("%d 	 %d 	 %d	  %d 		 %d 		 %d			%d\n", arqProdutos.codigo, arqProdutos.qtdInicio, arqProdutos.qtdMinima, qtdVendas, arqProdutos.qtdInicio - qtdVendas, necessidade, transferencia);
    fprintf(transfere, "%d 	 %d 	 %d	  %d 		 %d 		 %d			%d\n", arqProdutos.codigo, arqProdutos.qtdInicio, arqProdutos.qtdMinima, qtdVendas, arqProdutos.qtdInicio - qtdVendas, necessidade, transferencia);
    qtdVendas = 0;
    rewind(vendas);
  }
  
  printf("\nDivergencias\n\n");
  
  rewind(produtos);
  rewind(vendas);
  
  while(fscanf(vendas, "%d;%d;%d;%d", &arqVendas.codigo, &arqVendas.qtd, &arqVendas.situacao, &arqVendas.canal) != EOF)
    {
    	while (fscanf(produtos, "%d;%d;%d", &arqProdutos.codigo, &arqProdutos.qtdInicio, &arqProdutos.qtdMinima) != EOF)
    	{
    		if(arqVendas.codigo == arqProdutos.codigo)
			{
				existe = true;
			}
		}
		rewind(produtos);
		if(existe == false)
		{
			printf("%d - %d\n", linha, arqVendas.codigo);
			fprintf( divergencias,"%d - %d\n", linha, arqVendas.codigo);
		}
		linha++;
		existe = false;
		
    }
    
    rewind(produtos);
  	rewind(vendas);
    linha = 1;
    while(fscanf(vendas, "%d;%d;%d;%d", &arqVendas.codigo, &arqVendas.qtd, &arqVendas.situacao, &arqVendas.canal) != EOF)
    {
    	linha++;
      if(arqVendas.situacao == 135)
      {
        printf("%d - Venda cancelada\n", linha);
        fprintf( divergencias,"%d - Venda cancelada\n", linha);
      }
    }
    
    rewind(vendas);
    linha = 1;
    while( fscanf(vendas, "%d;%d;%d;%d", &arqVendas.codigo, &arqVendas.qtd, &arqVendas.situacao, &arqVendas.canal) != EOF)
    {
    	linha++;
      if(arqVendas.situacao == 190)
      {
        printf("%d - Venda nao finalizada\n", linha);
        fprintf( divergencias,"%d - Venda cancelada\n", linha);
      }
    }
    
    rewind(vendas);
    linha = 1;
    while( fscanf(vendas, "%d;%d;%d;%d", &arqVendas.codigo, &arqVendas.qtd, &arqVendas.situacao, &arqVendas.canal) != EOF)
    {
    	linha++;
      if(arqVendas.situacao == 999)
      {
        printf("%d - Erro desconhecido. Acionar equipe de TI.\n", linha);
        fprintf( divergencias,"%d - Venda cancelada\n", linha);
      }
    }
    
    printf("\nQuantidades de Vendas por canal\n");
    printf("\nCanal              		   QtVendas\n");
    printf("1 - Representantes      		%d\n", representantes);
    printf("2 - Website             		%d\n", website);
    printf("3 - App movel Android   		%d\n", android);
    printf("4 - App movel iPhone    		%d\n", iphone);


    fprintf(totcanais, "Quantidades de Vendas por canal\n\n");
    fprintf(totcanais, "Canal              		   QtVendas\n");
    fprintf(totcanais, "1 - Representantes      		%d\n", representantes);
    fprintf(totcanais, "2 - Website             		%d\n", website);
    fprintf(totcanais, "3 - App movel Android   		%d\n", android);
    fprintf(totcanais, "4 - App movel iPhone    		%d\n", iphone);

    fclose(produtos);
    fclose(vendas);
    fclose(transfere);
    fclose(divergencias);
    fclose(totcanais);


    printf("\n\nFim do Programa\n\n");
    system("pause");
    return 0;
}