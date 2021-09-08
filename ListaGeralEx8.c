#include<stdio.h>
int main(){

    int codigo, qtde, totalQtde = 0;
    double precoUnitario, totalValor = 0;

    scanf("%d", &codigo);

    while (codigo != 0)
    {
        precoUnitario = 0;

        if (codigo == 12)
        {
            precoUnitario = 12.90;
        }
        else if (codigo == 16)
        {
            precoUnitario = 14.30;
        }
        else if (codigo == 23)
        {
            precoUnitario = 19.90;
        }
        else if (codigo == 25)
        {
            precoUnitario = 23.50;
        }
        else if (codigo == 28)
        {
            precoUnitario = 25.50;
        }
        else
        {
            printf("Codigo Invalido, Digite Outro Codigo Valido\n");
        }
        
        if(precoUnitario > 0)
        {
            do
            {
                scanf("%d", &qtde);
                if (qtde <= 0)
                {
                    printf("Qtde Invalida, Digite uma Valida\n");
                }
                
            } while (qtde <= 0);
        }

        totalValor += qtde * precoUnitario;
        totalQtde += qtde;

        scanf("%d", &codigo);
    }
    
    printf("Qtde de Lanches Vendidos: %d\n", totalQtde);
    printf("Valor total arrecadado: %.2lf\n", totalValor);
    
    return 0;
}