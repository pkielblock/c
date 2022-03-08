//pilha com vetor
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int conta (Pilha *p)
{
	int cont = 0; // Contador de elementos
	Pilha *aux = pilha_cria(); //Cria pilha auxiliar para movimentar os dados
	float v;
	
	if(pilha_vazia(p)){
		printf("Pilha Vazia\n");
	} else {
		while(!pilha_vazia(p)) { //Enquanto pilha p não estiver vazia.
			v = pilha_pop(p);
			cont++;
			pilha_push(aux, v); //coloca na pilha auxiliar
		}
	
		while(!pilha_vazia(aux)) {
			v = pilha_pop(aux);
			pilha_push(p, v);
		}
	
		pilha_libera(aux);
		return cont;
	}
}

float soma (Pilha *p)
{
	Pilha *aux = pilha_cria();
	float v, soma;
	
	if(pilha_vazia(p)){
		printf("Pilha Vazia\n");
	} else {
		while (!pilha_vazia(p)){
			v = pilha_pop(p);
			soma = soma + v;
			pilha_push(aux, v);
		}
	
		while(!pilha_vazia(aux)) {
			v = pilha_pop(aux);
			pilha_push(p, v);
		}
	
		pilha_libera(aux);
		return soma;
	}
}

void base (Pilha *p)
{
	Pilha *aux = pilha_cria();
	float v;
	
	if(pilha_vazia(p)){
		printf("Pilha Vazia\n");
	} else {
		while(!pilha_vazia(p)) { //Enquanto pilha p não estiver vazia.
			v = pilha_pop(p);
			pilha_push(aux, v); //coloca na pilha auxiliar
		}
	
		printf("Base da Pilha: %0.f\n", v);
	
		while(!pilha_vazia(aux)) {
			v = pilha_pop(aux);
			pilha_push(p, v);
		}
	
		pilha_libera(aux);
	}
}

void topo (Pilha *p)
{
	float topo;
	
	if (pilha_vazia(p)) {
		printf("Pilha Vazia\n");
	} else {
		topo = pilha_pop(p);
		printf("Topo da pilha: %0.f", topo);
		pilha_push(p, topo);
	}
}

void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Empilha (push)\n");
     printf("2. Retira (pop)\n");
     printf("3. Mostra a pilha\n");
     printf("4. Contar elementos\n");
     printf("5. Somar elementos\n");
	 printf("6. Base da Pilha\n");
	 printf("7. Topo da Pilha\n");
     printf("9. Fim\n");
}

main(){
      Pilha *pi=pilha_cria();
      int opmenu;
      float item;
      do{
         menu();
         scanf("%d", &opmenu);
         switch (opmenu){
         case 1 : //insere
                printf("Digite o valor a ser empilhado: ");
                scanf("%f", &item);
                pilha_push(pi,item);
                break;
        case 2 : //retira
               if(pilha_vazia(pi))//verifica antes se está vazia
                   printf("Pilha vazia.\n");
               else
                   printf("Elemento retirado = %.0f\n",pilha_pop(pi));
               break;
        case 3 : //mostra
                if(pilha_vazia(pi))
                   printf("pilha vazia!\n");
                else
                   pilha_mostra(pi);
                break;
        case 4 : //contador de elementos
        		printf("Numero de elementos: %d\n", conta(pi));
        		break;
        case 5 :
        		printf("Soma dos elementos: %.0f\n", soma(pi));
        		break;
        case 6 :
        		base(pi);
        		break;
        case 7 :
        		topo(pi);
        		break;
       }//switch
       printf("\n");
       system("pause");
       
     } while(opmenu!=9);
     pilha_libera(pi);
   }
