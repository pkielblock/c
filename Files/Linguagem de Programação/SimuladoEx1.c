#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int min, max, random, resp, palpite = 1, *respostas, i = 0, cont = 0;

    printf("Pedro Henrique Sampaio Kielblock\n");
    printf("Questao 2\n");
    
    while(max < (min + 100))
    {
        printf("Digite o MIN: ");
        scanf("%d", &min);
        printf("Digite o MAX: ");
        scanf("%d", &max);
    }

    srand(time(NULL));
    random = rand() % max + min;

    respostas = NULL;

    do
    {
        printf("Palpite %d: ", palpite);
        scanf("%d", &resp);

        if (resp < random)
        {
            palpite++;
            printf("Voce Digitou um Numero Menor\n");
            respostas = (int *)realloc(respostas, palpite * sizeof(int));
            respostas[cont] = resp;
            cont++;
        }
        else if (resp > random)
        {
            palpite++;
            printf("Voce Digitou um Numero Maior\n");
            respostas = (int *)realloc(respostas, palpite * sizeof(int));
            respostas[cont] = resp;
            cont++;
        }
        
    } while (resp != random);

    cont++;
    respostas[cont - 1] = resp;

    printf("Voce acertou\n");
    printf("Foram %d palpites para voce acertar\n", palpite);
    printf("e seus palpites foram: \n");

    for (i = 0; i < cont; i++)
    {
        printf (" %d", respostas[i]);
    }

    free(respostas);
    
    printf("\n\nFim Do Programa\n\n");
    system("pause");
    return 0;
}