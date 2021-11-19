#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct TDados {
    double precoVenda;
    double qntdVendida;
    int dia;
    int mes;
    int ano;
    int produtos;
    int codigos;
};

struct TProdutos {
    int codigo;
    char ctrlEstoque;
    double qtdEstoque;
    double custoUnitario;
    double margemLucro; 
};

int main ()
{
    TDados *Dados, Arquivo;
    TProdutos ArquivoProds, *Prods, Produtos;
    FILE *arqProdutos, *arqVendas, *arqSaida;
    double qntd[12][31];
    double total[12][31];
    int diasMes[12][31];
    int *produtos;
    double mediaVenda, totalProd[16], qntdProd[16], pcMedio;
    int Tam, diaAtual = 0, mesAtual = 0, vendasDia = 1, i, j, mes;
    int cont, qtdeGeral;
	double totGeral, medDia, medVendas;

    arqProdutos = fopen("produtos.txt", "r");
    arqVendas = fopen("vendas.txt", "r");
    arqSaida = fopen("totvendas.txt", "w");

    printf("Pedro Henrique Sampaio Kielblock\n");
    printf("Guilherme Germano Peres\n");
    printf("Henrique Ernandes Rebelo\n");
    printf("Maria Eduarda\n\n");
    fprintf(arqSaida, "Pedro Henrique Sampaio Kielblock\n");
    fprintf(arqSaida, "Guilherme Germano Peres\n");
    fprintf(arqSaida, "Henrique Ernandes Rebelo\n");
    fprintf(arqSaida, "Maria Eduarda\n\n");
    
    Dados = NULL;
    Dados = (TDados *)realloc(Dados, sizeof(TDados) * 4);
   	Prods = NULL;
    
    while (fscanf(arqVendas, "%d;%d;%d;%d;%lf;%lf;", &Arquivo.ano, &Arquivo.mes, &Arquivo.dia, &Arquivo.produtos, &Arquivo.qntdVendida, &Arquivo.precoVenda) != EOF)  
    {
		qntd[Arquivo.mes - 1][Arquivo.dia - 1] += Arquivo.qntdVendida;
		total[Arquivo.mes - 1][Arquivo.dia - 1] += Arquivo.precoVenda;
		if (diaAtual == Arquivo.dia)
        {
        	diasMes[Arquivo.mes - 1][Arquivo.dia - 1]++;
        }
        else {
        	diaAtual++;
        	diasMes[Arquivo.mes - 1][Arquivo.dia - 1]++;
		}
	}

    printf(" Dia  		Total     Media/Dia\n");
    fprintf(arqSaida, " Dia  		Total     Media/Dia\n");
	for ( i=0; i<12; i++ )
    {
    	for ( j=0; j<31; j++ )
    	{
    		mediaVenda = qntd[ i ][ j ] / diasMes[ i ][ j ];
      		printf (" %d/%d/%d     %.2lf      %.2lf\n", j + 1, i + 1, Arquivo.ano, qntd[ i ][ j ], mediaVenda);
            fprintf (arqSaida, " %d/%d/%d     %.2lf      %.2lf\n", j + 1, i + 1, Arquivo.ano, qntd[ i ][ j ], mediaVenda);
    	}
	}
    
	
	// SEGUNDA PARTE***********
	printf("\n\n\n");
	fprintf(arqSaida, "\n\n\n");
	
	Tam = 0;
    while (fscanf(arqProdutos, "%d;%c;%lf;%lf;%lf;", &ArquivoProds.codigo, &ArquivoProds.ctrlEstoque, &ArquivoProds.qtdEstoque, &ArquivoProds.custoUnitario, &ArquivoProds.margemLucro) != EOF)  
    {
      Tam++;
      Prods = (TProdutos *)realloc(Prods, sizeof(TProdutos) * Tam);
      Prods[Tam-1] = ArquivoProds;
    }
    printf("Prod.   VlrTotal   Qntde   PcMedio  Lucrat.\n");
    fprintf(arqSaida, "Prod.   VlrTotal   Qntde   PcMedio  Lucrat.\n");
    for(i = 0; i < Tam; i++)
	{
    	while (fscanf(arqVendas, "%d;%d;%d;%d;%lf;%lf;", &Arquivo.ano, &Arquivo.mes, &Arquivo.dia, &Arquivo.produtos, &Arquivo.qntdVendida, &Arquivo.precoVenda) != EOF) 
		{
    		if(Prods[i].codigo ==  Arquivo.produtos)
			{
    			totalProd[i] += Arquivo.precoVenda;
    			qntdProd[i] += Arquivo.qntdVendida;
			}
		}
		rewind(arqVendas);
		pcMedio = totalProd[i] / qntdProd[i];
		printf("%d   %.2lf   %.lf   %.2lf   %.1lf\n", Prods[i].codigo, totalProd[i], qntdProd[i], pcMedio, (pcMedio / Prods[i].custoUnitario - 1)  * 100 );
        fprintf(arqSaida, "%d   %.2lf   %.lf   %.2lf   %.1lf\n", Prods[i].codigo, totalProd[i], qntdProd[i], pcMedio, (pcMedio / Prods[i].custoUnitario - 1)  * 100 );
	}
	
	
	//PARTE 3!!!
	while (fscanf(arqVendas, "%d;%d;%d;%d;%lf;%lf;", &Arquivo.ano, &Arquivo.mes, &Arquivo.dia, &Arquivo.produtos, &Arquivo.qntdVendida, &Arquivo.precoVenda) != EOF)  
	{
    	cont++;
		totGeral += Arquivo.precoVenda;
		qtdeGeral += Arquivo.qntdVendida;
		medDia = totGeral / cont;
		medVendas = totGeral / qtdeGeral;
	}
	printf("\n\n\n");
	printf("Total Geral de Vendas (R$) %.2lf\nQuantidade de produtos vendidos %d\nMedia de Vendas por dia util (R$) %.2lf\nMedia de Vendas por produto (R$) %.2lf\n", totGeral, qtdeGeral, medDia, medVendas);
    fprintf(arqSaida, "Total Geral de Vendas (R$) %.2lf\nQuantidade de produtos vendidos %d\nMedia de Vendas por dia u0til (R$) %.2lf\nMedia de Vendas por produto (R$) %.2lf\n", totGeral, qtdeGeral, medDia, medVendas);
	
	
    fclose(arqProdutos);
    fclose(arqVendas);
    fclose(arqSaida);
    free(Dados);
	free(Prods);

    printf("\n\nFim do Programa\n\n");
    return 0;
}

