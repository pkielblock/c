//fila com vetor

#include <stdio.h>
#include <stdlib.h>
#include "filaSmart.h"
Fila *concatenaFila(Fila *p, Fila *q){ //juntar aos elementos de p os elementos de q
	float x;
	Fila *p1,*q1,*nova;//ponteiro para 3 filas
	//p1 e q1 são filas auxiliares
	//nova é a fila a ser retornada pela função
	p1=fila_cria();
	q1=fila_cria();
	nova=fila_cria();
	//esvazia a fila p em p1
	while(fila_vazia(p)==0)
	   fila_insere(p1,fila_retira(p)); //final fila p vazia e fila p1 cheia
	//esvazia a fila q em q1
	while(fila_vazia(q)==0)
	   fila_insere(q1,fila_retira(q)); //final fila q vazia e fila q1 cheia
	//alimentar a fila nova a partir de p1 restaurando a fila p
	while(fila_vazia(p1)==0){
		x=fila_retira(p1); 
		fila_insere(p,x);//restaura
		fila_insere(nova,x);
	}
	//alimentar a fila nova a partir de q1 restaurando a fila q
	while(fila_vazia(q1)==0){
		x=fila_retira(q1); 
		fila_insere(q,x);//restaura
		fila_insere(nova,x);
	}
	fila_libera(p1);
	fila_libera(q1);
	return nova;
}

int main(){
	Fila *f1=fila_cria();
	Fila *f2=fila_cria();
	Fila *f3; //ponteiro para uma fila
	//insere elementos em f1
	fila_insere(f1,1);
	fila_insere(f1,2);
	fila_insere(f1,3);
	fila_insere(f1,4);
	
	//insere elementos em f2
	fila_insere(f2,10);
	fila_insere(f2,20);
	fila_insere(f2,30);
	fila_insere(f2,40);
	f3=concatenaFila(f1,f2);

	fila_mostra(f1);
	fila_mostra(f2);
	fila_mostra(f3);
}
