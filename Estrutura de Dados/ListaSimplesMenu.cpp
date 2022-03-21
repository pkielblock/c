#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int contaElementos(Lista *lst)
{
	int cont;
	Lista *aux;
	
	for(aux = lst; aux != NULL; aux = aux->prox){
		cont++;
	}
	
	return cont;
}

int somaElementos(Lista *lst)
{
	Lista *aux;
	int soma;
	
	for(aux = lst; aux != NULL; aux = aux->prox){
		soma += aux->info;
	}
	
	return soma;
}

int ultimoLista(Lista *lst)
{	
	Lista *aux;
	int ultimo;
	
	for(aux = lst; aux != NULL; aux = aux->prox){
		if(aux->prox == NULL){
			ultimo = aux->info;
		}
	}
	
	return ultimo;
}

int primeiroLista(Lista *lst)
{
	int primeiro;
	
	primeiro = lst->info;
	
	return primeiro;	
}

//programa principal
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("------------------------------\n");
     printf("1. Insere na lista\n");     //Lista *lista_insere(Lista *l, int dado)  
     printf("2. Retira da lista\n");	 //Lista *lista_retira(Lista *l, int dado) 
     printf("3. Mostra a lista\n");      //void *lista_mostra(Lista *l) 
     printf("4. Busca na lista\n");		 //Lista *lista_busca(Lista *l, int dado) 
     printf("5. Conta elementos\n"); 	 //int contaElementos(Lista *lst)
     printf("6. Soma Elementos\n"); 	 //int somaElementos(Lista *lst)
     printf("7. Ultimo da Lista\n"); 	 //int ultimoLista(Lista *lst)
	 printf("8. Primeiro da Lista\n");   //int primeiroLista(Lista *lst)
	 printf("9. Fim\n");
     printf("==> ");
}
//--------------------------------------------------     
//programa principal       
//---------------------------------------------------
main(){
  int opmenu, item;
  Lista *li=lista_cria();//inicializa a lista com NULL
  Lista *aux;//ponteiro auxiliar - necessário para a busca
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
        case 4://busca
        	   printf("Informe o item que deseja buscar: ");
               scanf("%d",&item);
               aux=lista_busca(li,item);
               if (aux==NULL)
                   printf("%d NAO encontrado!\n",item);
                else
                	printf("%d Encontrado!\n",aux->info);
               break;
        case 5: //conta
        		if(lista_vazia(li)){
        			printf("Lista vazia\n");
				} else {
					printf("%d elementos", contaElementos(li));
				}
				break;
		case 6: //soma
				if(lista_vazia(li)){
        			printf("Lista vazia\n");
				} else {
					printf("Soma dos Elementos: %d", somaElementos(li));
				}
				break;
		case 7: //ultimo
				if(lista_vazia(li)){
        			printf("Lista vazia\n");
				} else {
					printf("Ultimo dos Elementos: %d", ultimoLista(li));
				}
				break;
		case 8: //primeiro
				if(lista_vazia(li)){
        			printf("Lista vazia\n");
				} else {
					printf("Primeiro dos Elementos: %d", primeiroLista(li));
				}
				break;
        }//fim switch
   printf("\n");
   system("pause");
   }while(opmenu!=9);
   lista_libera(li);
}
