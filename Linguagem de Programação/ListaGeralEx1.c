#include<stdio.h>
int main (){

    double peso;
    int destino;

    FILE *arq;
    arq = fopen("ListaGeralEx1.txt", "w");

    do
    {
        printf("[1 - Urbano/ 2 - Fora da Cidade]: ");
        scanf("%d", &destino);
    } while (destino >= 3 || destino <= 0);
    
    printf("Digite o Peso: ");
    scanf("%lf", &peso);

    if (destino == 1)
    {
        if (peso <= 10)
        {
            printf("Moto\n");
            fprintf(arq, "Moto\n");
        }
        else if(peso <= 600)
        {
            printf("Utilitario\n");
            fprintf(arq, "Utilitario\n");
        }
        else if(peso <= 3000)
        {
            printf("VUC\n");
            fprintf(arq, "VUC\n");
        }
        else if(peso <= 6000)
        {
            printf("Caminhao\n");
            fprintf(arq, "Caminhao\n");
        }
        else if(peso <= 12000)
        {
            printf("Caminhao Trucado\n");
            fprintf(arq, "Caminhao Trucado\n");
        }
        else if(peso <= 45000)
        {
            printf("{erro} – transp. urbano nao permitido\n");
            fprintf(arq, "{erro} – transp. urbano nao permitido\n");
        }
        else
        {
            printf("O peso e muito grande para um unico veiculo\n");
            fprintf(arq, "O peso e muito grande para um unico veiculo\n");
        }
    }
    else
    {
        if (peso <= 10)
        {
            printf("Correios\n");
            fprintf(arq, "Correios\n");
        }
        else if(peso <= 3000)
        {
            printf("Transportadora\n");
            fprintf(arq, "Transportadora\n");
        }
        else if(peso <= 6000)
        {
            printf("Caminhao\n");
            fprintf(arq, "Caminhao\n");
        }
        else if(peso <= 12000)
        {
            printf("Caminhao Trucado\n");
            fprintf(arq, "Caminhao Trucado\n");
        }
        else if(peso <= 45000)
        {
            printf("Carreta articulada\n");
            fprintf(arq, "Carreta articulada\n");
        }
        else
        {
            printf("O peso e muito grande para um unico veiculo\n");
            fprintf(arq, "O peso e muito grande para um unico veiculo\n");
        }
    }

    fclose(arq);
    return 0;
}