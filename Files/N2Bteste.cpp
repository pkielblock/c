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
    double tota,mediaVenda, totalProd[16], qntdProd[16], pcMedio, tot, qnt, dia = 1;
    int Tam, diaAtual = 0, mesAtual = 0, vendasDia = 1, i, mes;

    arqProdutos = fopen("produtos.txt", "r");
    arqVendas = fopen("vendas.txt", "r");
    arqSaida = fopen("totvendas.txt", "w");
    
    Dados = NULL;
    Dados = (TDados *)realloc(Dados, sizeof(TDados) * 4);
   	Prods = NULL;
    
    for(mes = 0; mes < 13 ;mes++){
    	while (fscanf(arqVendas, "%d;%d;%d;%d;%lf;%lf;", &Arquivo.ano, &Arquivo.mes, &Arquivo.dia, &Arquivo.produtos, &Arquivo.qntdVendida, &Arquivo.precoVenda) != EOF)  {
    		Prods = (TProdutos *)realloc(Prods, sizeof(TProdutos) * Tam);
    		if(Arquivo.mes != (mes + 1)){
    			mes++;
			}else{
				if(Arquivo.dia == dia)
				{
					tot += Arquivo.precoVenda;
					qnt += Arquivo.qntdVendida;	
				}
				else if(dia + 1 == Arquivo.dia)
				{
					printf("%d   %.2lf    %lf \n", Arquivo.dia - 1, qnt, tot);
					dia++;
					tot = 0;
					qnt = 0;
					tot += Arquivo.precoVenda;
					qnt += Arquivo.qntdVendida;
				}
			}
		}
	}
    
	
	// SEGUNDA PARTE***********
	printf("\n\n\n");
	
	
	    Tam = 0;
    while (fscanf(arqProdutos, "%d;%c;%lf;%lf;%lf;", &ArquivoProds.codigo, &ArquivoProds.ctrlEstoque, &ArquivoProds.qtdEstoque, &ArquivoProds.custoUnitario, &ArquivoProds.margemLucro) != EOF)  
    {
      Tam++;
      Prods = (TProdutos *)realloc(Prods, sizeof(TProdutos) * Tam);
      Prods[Tam-1] = ArquivoProds;
    }
    printf("Prod.   VlrTotal   Qntde   PcMedio  Lucrat.\n");
    for(i = 0; i < Tam; i++){
    	while (fscanf(arqVendas, "%d;%d;%d;%d;%lf;%lf;", &Arquivo.ano, &Arquivo.mes, &Arquivo.dia, &Arquivo.produtos, &Arquivo.qntdVendida, &Arquivo.precoVenda) != EOF) {
    		if(Prods[i].codigo ==  Arquivo.produtos){
    			totalProd[i] += Arquivo.precoVenda;
    			qntdProd[i] += Arquivo.qntdVendida;
			}
		}
		rewind(arqVendas);
		pcMedio = totalProd[i] / qntdProd[i];
		printf("%d   %.2lf   %.lf   %.2lf   %.1lf\n", Prods[i].codigo, totalProd[i], qntdProd[i], pcMedio, (pcMedio / Prods[i].custoUnitario - 1)  * 100 );
	}
	

    fclose(arqProdutos);
    fclose(arqVendas);
    fclose(arqSaida);
    free(Dados);
	free(Prods);
    printf("\n\nFim do Programa\n\n");
    return 0;
}
