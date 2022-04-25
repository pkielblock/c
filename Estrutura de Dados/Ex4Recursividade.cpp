#include <stdio.h>

void buscaLista (Lista *l, int valor);
Lista* lista_insere(Lista* ls, int dado);

typedef struct lista{
	int info;
	struct lista* prox;
}Lista;

int main()
{
	
}

void buscaLista (Lista *l, int valor)
{
	
}

Lista* lista_insere(Lista* ls, int dado) {//insere no inicio
      Lista *novo= (Lista*) malloc (sizeof(Lista));
      novo->info=dado;
      novo->prox=ls;
      return novo;//retorna ao programa o item recém inserido
}


