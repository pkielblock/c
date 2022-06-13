#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
   float info;//informa��o mantida na pilha
   lista *prox;
}Lista;

typedef struct pilha {
   Lista *topo;//ponteiro para o elemento mais recente da pilha
}Pilha;

Pilha *pilha_cria(void){
      Pilha *p= (Pilha*) malloc(sizeof(Pilha));
      p->topo=NULL;//inicializa o ponteiro com NULL
      return p;
}

void pilha_push(Pilha *p, float v) {
     Lista *n = (Lista*) malloc (sizeof(Lista));//aloca espa�o para o item da pilha 
     n->info=v;                              //e liga com o anterior
     n->prox =p->topo;
     p->topo=n;//troca o inicio da pilha pelo item recem adicionado
}

int pilha_vazia(Pilha *p) {
    return (p->topo==NULL);
}

float pilha_pop(Pilha *p){
      Lista *t;
      float v;
      t=p->topo;
      v=t->info;
      p->topo=t->prox;
      free(t);
      return v;
}

void pilha_mostra(Pilha *p) { //percorre a pilha(lista) mostrando os elementos
     Lista *q;
     for(q=p->topo;q!=NULL;q=q->prox)
        printf("%.0f\n", q->info);
     printf("\n");
       
}

void pilha_libera(Pilha *p){//libera cada item da pilha
     Lista *q= p->topo;
     while (q!=NULL) {
           Lista *t=q->prox;
           free(q);
           q=t;
           }
     free(p);
}          

                                    
