#include <stdio.h>
#include <stdlib.h>

int main(){

    int nv, cod, qv, i = 0;
    double precoVarejo = 0.0, precoAtacado = 0.0, totalVarejo = 0.0, totalAtacado = 0.0, total = 0.0;

    printf("Pedro Henrique Sampaio Kielblock\n");
    printf("1680482112029\n");
    printf("Henrique Ernandes Rebelo\n");
    printf("1680482112038\n");

    do
    {
        printf("Vendas Realizadas: ");
        scanf("%d", &nv);
    } while (nv <= 0);

    for (i = 0; i < nv; i++)
    {
        printf("Venda %d ", i + 1);
        scanf("%d %d", &cod, &qv);

        if (cod == 16 && qv < 50)
        {
            precoVarejo = 14.35;
            totalVarejo += precoVarejo * qv;

        }
        else if (cod == 16 && qv >= 50)
        {
            precoAtacado = 12.93;
            totalAtacado += precoAtacado * qv;
        }
        else if (cod == 23 && qv < 100)
        {
            precoVarejo = 35.12;
            totalVarejo += precoVarejo * qv;
        }
        else if (cod == 23 && qv >= 100)
        {
            precoAtacado = 29.85;
            totalAtacado += precoAtacado * qv;
        }
        else if (cod == 27 && qv < 70)
        {
            precoVarejo = 19.35;
            totalVarejo += precoVarejo * qv;
        }
        else if (cod == 27 && qv >= 70)
        {
            precoAtacado = 16.76;
            totalAtacado += precoAtacado * qv;
        }
        else if (cod == 34 && qv < 40)
        {
            precoVarejo = 63.40;
            totalVarejo += precoVarejo * qv;
        }
        else if (cod == 34 && qv >= 40)
        {
            precoAtacado = 58.25;
            totalAtacado += precoAtacado * qv;
        }
        else{
            printf("Codigo Invalido");
        }
        
        total = (totalVarejo + totalAtacado);
        
    }

    printf("Total de Vendas do Grupo Varejo: R$ %.2lf\n", totalVarejo);
    printf("Total de Vendas do Grupo Atacado: R$ %.2lf\n", totalAtacado);
    printf("Vendas Totais: R$ %.2lf\n", total);

    printf("\n\nFim do Programa\n\n");
    system("pause");
    return 0;
}