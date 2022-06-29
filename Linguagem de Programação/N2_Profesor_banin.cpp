#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Struct para receber o arquivo produtos e suas subs rotinas
struct Arquivos_de_Produtos{
	int codProd;
	char categoria;
	double Qtde_estoque;
	double preco_do_Produto;
	double lucro_do_produto;
};
//Struct para receber o arquivo produto e suas subs rotinas
struct Arquivos_das_vendas{
	int ano;
	int mes;
	int dia;
	int cod_das_Vendas;
	double qtd;
	double precos_das_Vendas;
	double total_das_vendas;
	double lucratividade_das_vendas;
	double media_das_vendas;
	double contribuicao_das_vendas;
};
//Void de exibição das informacoes e resultados de calculos
void Exibindo_Total_por_Dia(Arquivos_das_vendas *pV, int pTam, FILE *TOTVENDAS);
void Exibindo_Total_Total_de_Prododutos(Arquivos_das_vendas *pV, int pTam, FILE *TOTVENDAS);
//int´s para separar e ordenar por data e codigo
int data_ja_existe(int pDia, int pMes, int pAno, Arquivos_das_vendas *pV, int pTam);
int cod_ja_existe(int pCod, Arquivos_das_vendas *pV, int pTam);

int main(void){
	//variaveis globais separadas por "//"
	int TamA=0;
	int i;
	int Qtde_Geral_Vendida=0;
	int tamanho_Total_da_Data;
	int posicao, posicao2;
	//
	double Total_Geral_de_vendas=0;
	double media_dos_Produto;
	double media_dos_Dias_Uteis;
	double Media_da_lucratividade;
	//
	bool Trocou;
	//
	Arquivos_de_Produtos ler;
	Arquivos_de_Produtos *Produto_entrando;
	//
	Arquivos_das_vendas ler2;
	Arquivos_das_vendas *vendas_totais_por_Datas;
	Arquivos_das_vendas *Entrada_das_Venda;
	//
	Produto_entrando = NULL;
	Entrada_das_Venda = NULL;
	//
	FILE *TOTVENDAS;
	FILE *arq_para_Produto;
	FILE *arq_de_Venda; 
	
	//nomes dos integrantes
	printf("Raphael dos santos freitas\n");
	printf("isaque gabriel");
	
	//abrindo arquivo Produtos.txt
	arq_para_Produto = fopen("PRODUTOS.txt", "r");
	if (arq_para_Produto == NULL)
	{
		printf ("Erro 01 nao foi possivel abrir arquivo PRODUTOS\n");
	}
	//separando o  arquivo produto em sua respectivas partes
	while (fscanf(arq_para_Produto, "%d;%c;%lf;%lf;%lf;", &ler.codProd, &ler.categoria, &ler.Qtde_estoque, &ler.preco_do_Produto, &ler.lucro_do_produto) != EOF) {
		TamA++;
		Produto_entrando = (Arquivos_de_Produtos *)realloc(Produto_entrando, sizeof(Arquivos_de_Produtos) * TamA);
		Produto_entrando[TamA-1] = ler;
		
	}
	//fechando arquivo
	fclose(arq_para_Produto);
	
	TamA=0;
	//abrindo arquivo vendas
	arq_de_Venda = fopen("vendas.txt", "r");
	if (arq_de_Venda == NULL)
	{
		printf ("Erro 02 nao foi possivel abrir arquivo VENDAS\n");
	}
		
    //separando o arquivo vendas em suas respectivas partes
	while (fscanf(arq_de_Venda, "%d;%d;%d;%d;%lf;%lf;", &ler2.ano, &ler2.mes, &ler2.dia, &ler2.cod_das_Vendas, &ler2.qtd, &ler2.precos_das_Vendas) != EOF){
		ler2.total_das_vendas = ler2.precos_das_Vendas * ler2.qtd;
		Total_Geral_de_vendas = Total_Geral_de_vendas + (ler2.precos_das_Vendas*ler2.qtd);
		Qtde_Geral_Vendida = Qtde_Geral_Vendida + ler2.qtd;
		TamA++;
		Entrada_das_Venda = (Arquivos_das_vendas *)realloc(Entrada_das_Venda, sizeof(Arquivos_das_vendas) * TamA);
		Entrada_das_Venda[TamA-1]=ler2;
	
	}
	fclose(arq_de_Venda);
	
	//calculando a media dos produtos
	media_dos_Produto = Total_Geral_de_vendas/Qtde_Geral_Vendida;
	
	// processando a primeira parte do projeto
	tamanho_Total_da_Data = 0;
	vendas_totais_por_Datas = NULL;
	for (i=0; i<TamA; i++){
		posicao = data_ja_existe(Entrada_das_Venda[i].dia, Entrada_das_Venda[i].mes, Entrada_das_Venda[i].ano, vendas_totais_por_Datas, tamanho_Total_da_Data);
		if (posicao>=0){
			vendas_totais_por_Datas[posicao].total_das_vendas = vendas_totais_por_Datas[posicao].total_das_vendas + Entrada_das_Venda[i].total_das_vendas;
			vendas_totais_por_Datas[posicao].qtd = vendas_totais_por_Datas[posicao].qtd + Entrada_das_Venda[i].qtd;
		}
		else {
			tamanho_Total_da_Data++;
			vendas_totais_por_Datas = (Arquivos_das_vendas *)realloc(vendas_totais_por_Datas, sizeof(Arquivos_das_vendas) * tamanho_Total_da_Data);
			vendas_totais_por_Datas[tamanho_Total_da_Data-1].dia = Entrada_das_Venda[i].dia;
			vendas_totais_por_Datas[tamanho_Total_da_Data-1].mes = Entrada_das_Venda[i].mes;
			vendas_totais_por_Datas[tamanho_Total_da_Data-1].ano = Entrada_das_Venda[i].ano;
			vendas_totais_por_Datas[tamanho_Total_da_Data-1].total_das_vendas = Entrada_das_Venda[i].total_das_vendas;
		}
	}
	
	// Abrindo ou criando arquivo para ser gravado as informações
	TOTVENDAS = fopen("TOTVENDAS.TXT", "w");
	
	Exibindo_Total_por_Dia (vendas_totais_por_Datas, tamanho_Total_da_Data, TOTVENDAS);
	
	// processando a segunda parte do projeto
	tamanho_Total_da_Data = 0;
	vendas_totais_por_Datas = NULL;
	for (i=0; i<TamA; i++){
		posicao2 = cod_ja_existe(Entrada_das_Venda[i].cod_das_Vendas, vendas_totais_por_Datas, tamanho_Total_da_Data);
		if (posicao2>=0){
			vendas_totais_por_Datas[posicao2].total_das_vendas = vendas_totais_por_Datas[posicao2].total_das_vendas + Entrada_das_Venda[i].total_das_vendas;
			vendas_totais_por_Datas[posicao2].qtd = vendas_totais_por_Datas[posicao2].qtd + Entrada_das_Venda[i].qtd;
		}
		else {
			tamanho_Total_da_Data++;
			vendas_totais_por_Datas = (Arquivos_das_vendas *)realloc(vendas_totais_por_Datas, sizeof(Arquivos_das_vendas) * tamanho_Total_da_Data);
			vendas_totais_por_Datas[tamanho_Total_da_Data-1].cod_das_Vendas = Entrada_das_Venda[i].cod_das_Vendas;
			vendas_totais_por_Datas[tamanho_Total_da_Data-1].total_das_vendas = Entrada_das_Venda[i].total_das_vendas;
		}
	}
	//calculando a media por dia ultil
	media_dos_Dias_Uteis = Total_Geral_de_vendas/tamanho_Total_da_Data;
	
	//ordenando por data 
	do {
		Trocou = false;
		for (i=0; i<tamanho_Total_da_Data-1; i++){
			if (vendas_totais_por_Datas[i].cod_das_Vendas>vendas_totais_por_Datas[i+1].cod_das_Vendas){
				ler2 = vendas_totais_por_Datas[i];
				vendas_totais_por_Datas[i] = vendas_totais_por_Datas[i+1];
				vendas_totais_por_Datas[i+1] = ler2;
				Trocou = true;
			}
		}
	} while (Trocou);
	
	//calculando a lucratividade e a media
	for (i=0; i<tamanho_Total_da_Data; i++){
		vendas_totais_por_Datas[i].media_das_vendas = vendas_totais_por_Datas[i].total_das_vendas/vendas_totais_por_Datas[i].qtd;
		vendas_totais_por_Datas[i].lucratividade_das_vendas = (vendas_totais_por_Datas[i].media_das_vendas/Produto_entrando[i].preco_do_Produto-1)*100;
		Media_da_lucratividade = Media_da_lucratividade + Produto_entrando[i].lucro_do_produto*vendas_totais_por_Datas[i].qtd;
	}
	Media_da_lucratividade= Media_da_lucratividade/Qtde_Geral_Vendida;
		
	Exibindo_Total_Total_de_Prododutos (vendas_totais_por_Datas, tamanho_Total_da_Data, TOTVENDAS);
	
	// processando a teceira parte do projeto
	fprintf (TOTVENDAS, "\nTOTAL E ESTATISTICAS DO PERIODO\n");
	fprintf (TOTVENDAS, "Total Geral de Vendas (R$)        %.2lf\n", Total_Geral_de_vendas);
	fprintf (TOTVENDAS, "Quantidade de produtos vendidos   %d\n", Qtde_Geral_Vendida);
	fprintf (TOTVENDAS, "Media de Vendas por dia util (R$) %.2lf\n", media_dos_Dias_Uteis);
	fprintf (TOTVENDAS, "Media de Vendas por produto (R$)  %.2lf\n", media_dos_Produto);
	fprintf (TOTVENDAS, "Lucratividade Media               %.1lf%%\n", Media_da_lucratividade);
	
	// processando a quarta parte do projeto
	fprintf (TOTVENDAS, "\nPRODUTOS MAIS LUCRATIVOS\n");
	fprintf (TOTVENDAS, "Lucratividade media = %.1lf%%\n\n", Media_da_lucratividade);
	fprintf (TOTVENDAS, "Prod.     Lucrat.\n");
	for (i=0; i<tamanho_Total_da_Data; i++){
		if (vendas_totais_por_Datas[i].media_das_vendas > Media_da_lucratividade){
		fprintf (TOTVENDAS, "%d %8.1lf%%\n", vendas_totais_por_Datas[i].cod_das_Vendas, vendas_totais_por_Datas[i].media_das_vendas);
		}
	}
	
	// processando a quinta parte do projeto
	for (i=0; i<tamanho_Total_da_Data; i++){
		vendas_totais_por_Datas[i].contribuicao_das_vendas = (vendas_totais_por_Datas[i].total_das_vendas/Total_Geral_de_vendas)*100;
	}
	//ordenando por contribuição
	do {
		Trocou = false;
		for (i=0; i<tamanho_Total_da_Data-1; i++){
			if (vendas_totais_por_Datas[i].total_das_vendas < vendas_totais_por_Datas[i+1].total_das_vendas){
				ler2 = vendas_totais_por_Datas[i];
				vendas_totais_por_Datas[i] = vendas_totais_por_Datas[i+1];
				vendas_totais_por_Datas[i+1] = ler2;
				Trocou = true;
			}
		}
	} while (Trocou);
	
	fprintf (TOTVENDAS, "\nCONTRIBUIÇAO DE CADA PRODUTO\n");
	fprintf (TOTVENDAS, "Prod.      VlrTot      Contrib.\n");
	for (i=0; i<tamanho_Total_da_Data; i++){
		fprintf (TOTVENDAS, "%d %11.2lf %11.1lf%%\n", vendas_totais_por_Datas[i].cod_das_Vendas, vendas_totais_por_Datas[i].total_das_vendas, vendas_totais_por_Datas[i].contribuicao_das_vendas);
	}
	
	//Liberando toda memoria que foi alocada
	free(Entrada_das_Venda);
	free(Produto_entrando);
	fclose(TOTVENDAS);
}

    //olhando se ja existe a cetegoria por cod
int cod_ja_existe(int pCod, Arquivos_das_vendas *pV, int pTam){
	int i;
	
	if (pV == NULL)
		return -1;
	else {
		for (i=0; i<pTam; i++){
			if (pCod == pV[i].cod_das_Vendas )
				return i;
		}
		return -1;
	}
}

    //olhando se ja existe a cetegoria por dia
int data_ja_existe(int pDia, int pMes, int pAno, Arquivos_das_vendas *pV, int pTam){
	int i;
	
	if (pV == NULL)
		return -1;
	else {
		for (i=0; i<pTam; i++){
			if (pDia == pV[i].dia && pMes == pV[i].mes && pAno == pV[i].ano)
				return i;
		}
		return -1;
	}
}


//exibindo por vendas
void Exibindo_Total_Total_de_Prododutos(Arquivos_das_vendas *pV, int pTam, FILE *TOTVENDAS){
	int i;
	fprintf (TOTVENDAS, "\nTOTAIS DE VENDAS POR PRODUTO\n");
	fprintf (TOTVENDAS, "Prod.     VlrTot     Qtde      Pc Medio     Lucrat.\n");
	for (i=0; i<pTam; i++){
		fprintf (TOTVENDAS, "%d %10.2lf %8.0lf %13.2lf %9.1lf%%\n", pV[i].cod_das_Vendas, pV[i].total_das_vendas, pV[i].qtd, pV[i].media_das_vendas, pV[i].lucratividade_das_vendas);
	}
	
}
      //exibindo por dia
void Exibindo_Total_por_Dia(Arquivos_das_vendas *pV, int pTam, FILE *TOTVENDAS){
	int i;
	fprintf (TOTVENDAS,"\nRaphael dos santos freitas\n");
	fprintf (TOTVENDAS,"isaque gabriel\n\n");
	fprintf (TOTVENDAS, "\nTOTAIS DE VENDAS POR DIA\n");
	fprintf (TOTVENDAS, "Dia               Total    Media/Dia\n");
	for (i=0; i<pTam; i++){
		if (pV[i].dia / 10 == 0 && pV[i].mes/10==0)
			fprintf (TOTVENDAS, "0%d/0%d/%d %12.2lf %12.2lf\n", pV[i].dia, pV[i].mes, pV[i].ano, pV[i].total_das_vendas, pV[i].total_das_vendas/pV[i].qtd);
		else if (pV[i].dia / 10 == 0 )
			fprintf (TOTVENDAS, "0%d/%d/%d %12.2lf %12.2lf\n", pV[i].dia, pV[i].mes, pV[i].ano, pV[i].total_das_vendas, pV[i].total_das_vendas/pV[i].qtd);
		else if (pV[i].mes/10==0)
			fprintf (TOTVENDAS, "%d/0%d/%d %12.2lf %12.2lf\n", pV[i].dia, pV[i].mes, pV[i].ano, pV[i].total_das_vendas, pV[i].total_das_vendas/pV[i].qtd);
		else 
			fprintf (TOTVENDAS, "%d/%d/%d %12.2lf %12.2lf\n", pV[i].dia, pV[i].mes, pV[i].ano, pV[i].total_das_vendas, pV[i].total_das_vendas/pV[i].qtd);
	}
	
}
