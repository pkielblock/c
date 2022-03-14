//fila com vetor
#include <stdio.h>
#include <stdlib.h>
#include "filaCompacta.h"

float somaElementos(Fila *f)
{
	Fila *aux = fila_cria();
	float v, soma;
	
	while(!fila_vazia(f)) {
		v = fila_retira(f);
		soma = soma + v;
		fila_insere(aux, v);
	}
	
    while(!fila_vazia(aux)) {
    	fila_insere(f,fila_retira(aux));	
	}
	
	fila_libera(aux);
	return soma;
	
}

float primeiro(Fila *f)
{
	Fila *aux = fila_cria();
	float v, p;
	
	if(fila_vazia(f)) {
		printf("Fila Vazia\n");
	} else {
		while (!fila_vazia(f)) {
			v = fila_retira(f);
			fila_insere(aux, v);
			if(!p) {
				p = v;
			}
		}
		
		while(!fila_vazia(aux)) {
    		fila_insere(f,fila_retira(aux));	
		}
		
		fila_libera(aux);
		return p;
	}
}

float ultimo(Fila *f)
{
	Fila *aux = fila_cria();
	float v;
	
	while (!fila_vazia(f)) {
		v = fila_retira(f);
		fila_insere(aux, v);
	}
	
    while(!fila_vazia(aux)) {
    	fila_insere(f,fila_retira(aux));	
	}

	fila_libera(aux);
	return v;
}


int contaElementos(Fila *f){
    int cont=0;
    Fila *aux=fila_cria();
    float v;
    //esvazia a fila original para contar
    while(!fila_vazia(f)){
      v=fila_retira(f);
      cont++;
      fila_insere(aux,v);
    }
    //restaura a fila original
    while(!fila_vazia(aux))
      fila_insere(f,fila_retira(aux));
      
    fila_libera(aux);
    return cont;
}
//--------------------------------------------------------------------	
void menu(){
     system("cls");
     printf("Escolha uma das opcoes do menu: \n");
     printf("1. Enfileira\n");       
     printf("2. Retira\n");
     printf("3. Mostra a Fila\n");
     printf("4. Conta Elementos\n");
     printf("5. Somar Elementos\n");
     printf("6. Primeiro da Fila\n");
     printf("7. Ultimo da Fila\n");
     printf("9. Fim\n");
}     
int main(){
 Fila *fi=fila_cria();
 int opmenu; 
 float item;
 do{
    menu(); 
    scanf("%d", &opmenu);
    switch (opmenu){
    case 1: //insere
          printf("Digite o valor a ser enfileirado: ");
          scanf("%f", &item);
          fila_insere(fi,item); break;
    case 2: //retira
          if(fila_vazia(fi)) 
              printf("fila vazia.\n");
          else
              printf("Elemento retirado = %.0f\n",fila_retira(fi));
          break;    
    case 3: //mostra
    	  if(fila_vazia(fi))	
    	     printf("Fila vazia!\n");
    	  else
            fila_mostra(fi);
	      break;
    case 4: //conta elementos
          printf("Numero de elementos: %d\n", contaElementos(fi));
          break;
    case 5:
    	  if(fila_vazia(fi)) {
    	  	printf("Fila Vazia\n");
		  }
		  else {
		  	printf("Soma: %.0f", somaElementos(fi));
		  }
		  break;
	case 6:
		  if(fila_vazia(fi)) {
    	  	printf("Fila Vazia\n");
		  }
		  else {
		  	printf("Primeiro elemento: %.0f", primeiro(fi));
		  }
		  break;
    case 7: //ultimo elemento
    	  	if(fila_vazia(fi)) {
				printf("Fila Vazia\n");
			} 
			else {
				printf("Ultimo elemento: %.0f", ultimo(fi));
			}
			break;
    }//switch
   printf("\n");
   system("pause"); 
 } while(opmenu!=9);
}
