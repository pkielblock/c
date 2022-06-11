#include <stdio.h>
#include <stdlib.h>
//PROGRAMA:  abbExemplo
//arvore binaria
struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

//cria arvore vazia
Arv*  abb_cria(){
      return NULL;
}

//verifica se a arvore est� vazia
int abb_vazia(Arv* a){
    return a == NULL;
}

//insere elemento - vers�o interativa
Arv  *abb_insere(Arv* a, int c){
     Arv *p,*q,*r;
     p=(Arv*)malloc(sizeof(Arv));
     p->info = c;
     p->esq = p->dir = NULL;

     if (abb_vazia(a))//primeiro elemento da �rvore
         a=p;
     else
     {
         q=a;
         while(q!=NULL)
         {
             r=q;
             if(c < q->info)
                  q=q->esq;
             else
                  q=q->dir;
         }
         if(c < r->info)
            r->esq=p;
         else
            r->dir=p;
     }
     return a;
 }
//percursos
void abb_posfixo(Arv* a){
     if(!abb_vazia(a)) //travessia em pos-ordem 
     {
         abb_posfixo(a->esq); //visita a arvore esquerda, depois a direita e depois a raiz
         abb_posfixo(a->dir);
         printf("%d ", a->info);//raiz
      }
}
void abb_infixo(Arv* a){
     if(!abb_vazia(a)) //travessia em ordem
     {
         abb_infixo(a->esq); //visita a arvore esquerda, depois a raiz e depois a arvore direita
         printf("%d ", a->info);//raiz
         abb_infixo(a->dir);
      }
}

void abb_prefixo(Arv* a){
     if(!abb_vazia(a)) //travessia em preordem
     {
         printf("%d ", a->info);//raiz
         abb_prefixo(a->esq); //visita a arvore raiz, depois a esquerda, depois a direita
         abb_prefixo(a->dir);
      }
}

int max2 (int a, int b){
       return (a>b)?a:b; //if ternario
}
//altura da arvore
int abb_altura(Arv *a){
       if (abb_vazia(a))
           return -1;
       return 1+ max2(abb_altura(a->esq),abb_altura(a->dir));
}

Arv* abb_busca(Arv *t, int v){
	    if (t==NULL) return NULL;
    	if (t->info > v) 
                return abb_busca(t->esq,v);
    	if (t->info < v)
                 return abb_busca(t->dir,v);
    	return t;//achou
}

void abb_100filhos(Arv *t)
{
	if(t != NULL) {
		if(t->esq == NULL && t->dir == NULL) {
			printf("%d ", t->info);
		}
		abb_100filhos(t->esq);
		abb_100filhos(t->dir);
	}
}

void abb_2filhos(Arv *t)
{
	if(t != NULL) {
		if(t->esq && t->dir) {
			printf("%d ", t->info);
		}
		abb_2filhos(t->esq);
		abb_2filhos(t->dir);
	}
}

void abb_par(Arv *t)
{
	if(t != NULL) {
		if((t->info % 2) == 0) {
			printf("%d ", t->info);
		}
		abb_par(t->esq);
		abb_par(t->dir);
	}
}

void abb_impar(Arv *t)
{
	if(t != NULL) {
		if((t->info % 2) != 0) {
			printf("%d ", t->info);
		}
		abb_impar(t->esq);
		abb_impar(t->dir);
	}
}

//----------------------------------------------------------
int main(){
  int num;
  Arv *a=abb_cria();
   //insere elementos na abb at� que um valor negativo seja digitado
  do{
     printf("Entre com o valor a ser inserido, ou -1 para finalizar:\n");
     scanf("%d", &num);
     if(num>=0)
        a=abb_insere(a,num);//inser��o em ordem abb
     }while(num>=0);
     
   printf("Percurso em ordem\n");
   abb_infixo(a); //imprime em ordem
   printf("\nPercurso em pre-ordem\n");
   abb_prefixo(a);
   printf("\nPercurso em pos-ordem\n");
   abb_posfixo(a);
   
   printf("\nNos sem filhos\n");
   abb_100filhos(a);
   
	printf("\nNos dois filhos\n");
	abb_2filhos(a);
	
	printf("\nNos Pares\n");
	abb_par(a);
	
	printf("\nNos Impares\n");
	abb_impar(a);
   	
   	
   /* incluir os demais percursos*/
   printf("\n\nAltura da arvore = %d\n",abb_altura(a));
   }
