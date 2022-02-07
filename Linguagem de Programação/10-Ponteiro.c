#include<stdio.h>
#include<stdlib.h>

int main(void)
{

    //Ponteiro é um tipo de váriavel especial, que armazena o endereço de memoriade uma outra váriavel.
    //São usados por exemplo para retornar mais de um valor dentro de uma função.

	//valor da variavel que sera apontada pelo ponteiro.
    int valor = 27;

    //declarando uma variavel do tipo ponteiro.
    int *ponteiro;


    //atribuindo o endereço da variavel valor ao ponteiro.
    ponteiro = &valor;

    printf("Utilizando Ponteiros\n\n");
    printf("Conteudo da variavel valor: %d\n", valor);
    printf("Endereco da variavel valor: %x\n", &valor);
    printf("Conteudo da varaivavel ponteiro: %x", ponteiro);

    getch();
	printf("\nFim do Programa\n");
	system("pause");
    return 0;
}


