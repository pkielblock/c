//pilha com vetor
#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

float conta (Pilha *p){
	int cont=0;//contador de elementos
	Pilha *aux=pilha_cria();//cria pilha auxiliar para movimentar os dados
	float v;
	while(pilha_vazia(p)==0){//enquanto a pilha p n�o estiver vazia
	  v=pilha_pop(p);
	  cont++;
	  pilha_push(aux,v);//coloca o elemento retirado na pilha auxiliar
	}
	//restaura a pilha original
	while(pilha_vazia(aux)==0){// while(!pilha_vazia(aux))
		v=pilha_pop(aux);
		pilha_push(p,v);
	}
	pilha_libera(aux);
	return cont;//retorna o numero de elementos
}
//---------------------------------------------------
float soma (Pilha *p){
	int s=0;//acumulador de elementos
	Pilha *aux=pilha_cria();//cria pilha auxiliar para movimentar os dados
	float v;//usado para retirar elementos da pilha
	while(pilha_vazia(p)==0){//enquanto a pilha p n�o estiver vazia
	  v=pilha_pop(p);
	  s=s+v;//acumula o valor dos elementos contidos na pilha
	  pilha_push(aux,v);//coloca o elemento retirado na pilha auxiliar
	}
	//restaura a pilha original
	while(pilha_vazia(aux)==0){// while(!pilha_vazia(aux))
		v=pilha_pop(aux);
		pilha_push(p,v);
	}
	pilha_libera(aux);
	return s;//retorna a soma dos elementos
}
//-------------------------------------------------------------
void base(Pilha *s){
	if(pilha_vazia(s))
	   printf("Pilha vazia nao tem base\n");
	else{
		float b;//vai guardar a base
		Pilha *a=pilha_cria();//pilha auxiliar
		//esvazia a pilha original para descobrir a base (ultimo)
		while(!pilha_vazia(s)){
			b=pilha_pop(s);
			pilha_push(a,b);
		}
		printf("Base: %.2f\n",b);
		//restaura a pilha original
		while(!pilha_vazia(a))
	  		pilha_push(s,pilha_pop(a));
		pilha_libera(a);
	}
}//-------------------------------------------------------
void topo(Pilha *s){
	float topo;
	if(pilha_vazia(s))
	   printf("Pilha vazia nao tem topo\n");
	else{
	   topo=pilha_pop(s);
	   pilha_push(s,topo);
	   printf("Topo: %.2f\n", topo);
	}
}
//----------------------------------------------
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Empilha (push)\n");
     printf("2. Retira (pop)\n");
     printf("3. Mostra a pilha\n");
     printf("4. Conta elementos\n"); //int conta(Pilha *p);
     printf("5. Soma elementos\n"); //float soma(Pilha *p);
     printf("6. Mostra a base\n");//void base(Pilha *s)
     printf("7. Mostra o topo\n");//void topo(Pilha *s)
     
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
               if(pilha_vazia(pi))//verifica antes se est� vazia
                   printf("Pilha vazia.\n");
               else
                   printf("Elemento retirado = %.2f\n",pilha_pop(pi));
               break;
        case 3 : //mostra
                if(pilha_vazia(pi))
                   printf("Pilha vazia!\n");
                else
                   pilha_mostra(pi);
                break;
        case 4:// conta elementos
               printf("Numero de elementos: %d\n", conta(pi));
               break;
        case 5:// soma elementos
               printf("Soma dos elementos: %.2f\n", soma(pi));
               break;
		case 6:// mostra a base
               base(pi);
               break;
        case 7:// mostra o topo
               topo(pi);
               break;
               
       }//switch
       printf("\n");
       system("pause");
       
     } while(opmenu!=9);
     pilha_libera(pi);
   }
