#include <stdio.h>
#include <stdlib.h>
#include "lista2.h"
void lista_reverso(Lista2* lst)
{
	Lista2* aux;
	aux = lst;
	while(aux->prox != NULL)
	{
		aux = aux->prox;
	}
	for(aux; aux->ant != NULL; aux = aux->ant)
	{
		printf("%d\t", aux->info);
	}
	printf("%d\t", aux->info);
}

void mostrar_vizinhos(Lista2* lst, int item)
{
	Lista2* aux;
	aux = lista_busca(lst, item);
	printf("%d Encontrado!\n", aux->info);
	
	//ant
	if(aux->ant != NULL)
	{
		printf("Anterior: %d\n", aux->ant->info);
		aux = aux->prox;
	} else {
		printf("Anterior: Ninguem\n");
	}
	
	//prox
	if(aux->prox != NULL)
	{
		printf("Proximo: %d\n", aux->prox->info);
	} else {
		printf("Proximo: Ninguem\n");
	}
}

void mostrar_extremos(Lista2* lst, int item)
{
	Lista2* aux;
	int primeiro, ultimo;
	aux = lista_busca(lst, item);
	printf("%d Encontrado!\n", aux->info);
	
	//Primeiro
	while(aux->prox != NULL)
	{
		aux = aux->prox;
	}
	while(aux->ant != NULL)
	{
		aux = aux->ant;
	}
	primeiro = aux->info;
	printf("Primeiro: %d\n", primeiro);
	
	//Ultimo
	for(aux = lst; aux != NULL; aux = aux->prox){
		ultimo = aux->info;
	}
	
	printf("Ultimo: %d\n", ultimo);
}

//programa principal
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("------------------------------\n");
     printf("1. Insere na lista\n");
     printf("2. Retira da lista\n");
     printf("3. Mostra a lista\n");
     printf("4. Mostra reverso\n");
     printf("5. Busca elemento e mostra vizinhos\n");
     printf("6. Busca elemento e mostra primeiro e ultimo\n");
	 printf("9. Fim\n");
     printf("==> ");
}
//--------------------------------------------------     
//programa principal       
//---------------------------------------------------
main(){
  int opmenu, item;
  Lista2 *li=lista_cria();
  Lista2 *aux;
  do{
     menu();   
     scanf("%d",&opmenu);
     switch(opmenu){
        case 1: //insere
                printf("Informe o item que deseja adicionar: ");
                scanf("%d",&item);
            	if(lista_busca(li,item)){
			 		printf("Item Duplicado");
			 	} else {
             		li=lista_ordenada(li,item);
			 	}
             	break;
        case 2:  //retira
             printf("Informe o item que deseja retirar: ");
             scanf("%d",&item);
             li=lista_retira(li,item);
			 break;
        case 3://mostra
		    if(lista_vazia(li))
			   printf("Lista vazia\n");
			else {
		  		  printf("\nLista:\n");
		          lista_mostra(li);
		      }
            break;
        case 4://mostra reverso
        	if(lista_vazia(li))
			   printf("Lista vazia\n");
			else {
		  		  printf("\nLista:\n");
		          lista_reverso(li);
		      }
            break;
        case 5://busca e vizinhos
        	   printf("Informe o item que deseja buscar: ");
               scanf("%d",&item);
               aux=lista_busca(li,item);
               if (aux==NULL)
                   printf("%d NAO encontrado!\n",item);
               else
               	   mostrar_vizinhos(li, item);
               break;
        case 6://busca, primeiro e ultimo
        	   printf("Informe o item que deseja buscar: ");
               scanf("%d",&item);
               aux=lista_busca(li,item);
               if (aux==NULL)
                   printf("%d NAO encontrado!\n",item);
               else
               	   mostrar_extremos(li, item);
               break;
        }//fim switch
   printf("\n");
   system("pause");
   }while(opmenu!=9);
   lista_libera(li);
}
