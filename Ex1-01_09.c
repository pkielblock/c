#include<stdio.h>
int main (){

    double peso;
    int destino;

    printf("[1 - Urbano/ 2 - Fora da Cidade]: ");
    scanf("%d", &destino);
    printf("Digite o Peso: ");
    scanf("%lf", &peso);

    if (destino == 1)
    {
        if (peso <= 10)
        {
            printf("Moto\n");
        }
        else if(peso <= 600)
        {
            printf("Utilitario\n");
        }
        else if(peso <= 3000)
        {
            printf("VUC\n");
        }
        else if(peso <= 6000)
        {
            printf("Caminhao\n");
        }
        else if(peso <= 12000)
        {
            printf("Caminhao Trucado\n");
        }
        else if(peso <= 45000)
        {
            printf("{erro} – transp. urbano nao permitido\n");
        }
        else
        {
            printf("O peso e muito grande para um unico veiculo\n");
        }
    }
    else
    {
        if (peso <= 10)
        {
            printf("Correios\n");
        }
        else if(peso <= 600)
        {
            printf("Transportadora\n");
        }
        else if(peso <= 3000)
        {
            printf("Transportadora\n");
        }
        else if(peso <= 6000)
        {
            printf("Caminhao\n");
        }
        else if(peso <= 12000)
        {
            printf("Caminhao Trucado\n");
        }
        else if(peso <= 45000)
        {
            printf("Carreta articulada\n");
        }
        else
        {
            printf("O peso e muito grande para um unico veiculo\n");
        }
    }

    return 0;
}