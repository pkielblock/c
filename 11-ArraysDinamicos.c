#include <stdio.h>
#include <stdlib.h>

int main(void)
{   

    //Alocação Dinâmica é uma maneira de alocar memória com o programa em execução.

    int *p; // Criando Ponteiro Para o Vetor.
    int i, quant_elementos;

    printf("Digite a Quantidade de Elementos do Vetor: ");
    scanf("%d", &quant_elementos);

    //Alocando a memória para o vetor de acordo com a quantidade de elementos do vetor.
    p = (int *)(malloc(quant_elementos * sizeof(int)));

    //tratamento de erro - se nao for possivel alocar memoria suficiente 
    //enviar mensagem e sair do programa com exit(1)
    if (p == NULL)
    {
        printf("\nErro de alocacao de memoria\n");
        system("pause");
        exit(1);
    }
    printf("\n");

    //recebendo os dados para o vetor
    for ( i = 0; i < quant_elementos; i++)
    {
        printf("Digite o Numero para o indice [%d]: ", i);
        scanf("%d", &p[i]);
    }
    printf("\n");

    //percorrendo o vetor e mostrando os valores armazenados
    for ( i = 0; i < quant_elementos; i++)
    {
        printf("Valor armazenado no indice [%d] = %d\n", i, p[i]);
    }
    printf("\n");
    
    //Liberando a memoria que foi alocada. free(nomeDoPonteiro);
    free(p);

    printf("\nFim Do Programa\n");
    system("pause");
    return 0;
}