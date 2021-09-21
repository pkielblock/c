#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, *pX, **ppX;

    //Inicializando variavel com 0
    x = 0;

    printf("Valor de X = [%d]\n", x);
    printf("Endereco de X = [%d]\n", &x);

    //Atribuindo os endereços para os ponteiros.
    pX = &x; //pX aponta para X
    ppX = &pX; //ppX aponta para pX

    //Pegando conteudo apontado por pX que no caso é a variavel X com valor 0. 
    //e somando 10. X = 10
    *pX = *pX + 10;
    printf("\nValor de X = [%d]\n", x);
    printf("Endereco apontado por pX = [%d]\n", pX); //pX acessa o valor de pX, que no caso é o endereco de X. [pX = &x;]
    printf("Valor de X apontada pelo pX = [%d]\n", *pX); //*pX acessa o conteudo da variavel para qual está apontando.
    printf("Endereco de memoria de pX = [%d]\n", &pX); //&pX acessa o endereco de pX.
    

    **ppX = **ppX + 10; //Modificando o valor, somando mais 10. X = 20.
    printf("\nValor de X = [%d]\n", x);
    printf("Endereco apontado por ppX = [%d]\n", ppX); //ppX acessa o valor de ppX, que no caso é o endereco de X. [pX = &x;]
    printf("Valor de X apontada pelo ppX = [%d]\n", **ppX); //**ppX acessa o conteudo da variavel para qual está apontando.
    printf("Endereco de memoria de ppX = [%d]\n", &ppX); //&ppX acessa o endereco de ppX.

    printf("\nFim Do Programa\n");
    system("pause");
    return 0;
}