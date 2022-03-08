#include <stdio.h>
#include <stdlib.h>
#include "pilha1.h"
Pilha *intercala_pilhas(Pilha *p1, Pilha *p2){
	Pilha *aux1 = pilha_cria();
	Pilha *aux2 = pilha_cria();
	Pilha *aux3 = pilha_cria();
	
	
	
}

main(){     
      Pilha *p1=pilha_cria();
      Pilha *p2=pilha_cria();
      Pilha *p3;
      //inserir dados na pilha p1
      pilha_push(p1,1);
      pilha_push(p1,2);
      pilha_push(p1,3);
      pilha_push(p1,4);
      //inserir dados na pilha p2
      pilha_push(p2,10);
      pilha_push(p2,20);
      pilha_push(p2,30);
      //pilha_push(p2,40);
      
      //p3=intercala_pilhas(p1,p2);
      
	  //mostrar o conteúdo das pilhas
      printf("P1\n");
      pilha_mostra(p1);
      printf("P2\n");
      pilha_mostra(p2);
      printf("P3\n");
      pilha_mostra(p3);
  }

