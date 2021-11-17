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
};

int main ()
{
    TDados *Dados, Arquivo;
    FILE *arqProdutos, *arqVendas, *arqSaida;
    double total[12][31];
    int Tam, diaAtual = 0, mesAtual = 0, vendasDia = 0, i, j;

    arqProdutos = fopen("produtos.txt", "r");
    arqVendas = fopen("vendas.txt", "r");
    arqSaida = fopen("totvendas.txt", "w");

    Dados = NULL;
    Dados = (TDados *)realloc(Dados, sizeof(TDados) * 4);

    while (fscanf(arqVendas, "%d;%d;%d;%d;%lf;%lf;", &Arquivo.ano, &Arquivo.mes, &Arquivo.dia, &Arquivo.produtos, &Arquivo.qntdVendida, &Arquivo.precoVenda) != EOF)
    {
        total[Arquivo.mes - 1][Arquivo.dia - 1] += Arquivo.qntdVendida;
    }

    for (i=0; i<12; i++)
    {
        for (j=0; j<31; j++)
        {
            printf ("\nMes[%d] Dia [%d] = %.2lf\n", i + 1, j + 1, total[ i ][ j ]);
            fprintf (arqSaida, "Mes[%d] Dia [%d] = %.2lf\n", i + 1, j + 1, total[ i ][ j ]);
        }
    }

    fclose(arqProdutos);
    fclose(arqVendas);
    fclose(arqSaida);
    free(Dados);

    printf("\n\nFim do Programa\n\n");
    return 0;
}