typedef struct lista2 {
       lista2* ant;
	   int info;
       lista2* prox;
}Lista2;//lista duplamente encadeada

Lista2* lista_cria() {
        return NULL;
}
int lista_vazia(Lista2* lst) {
    return(lst==NULL);
}

Lista2* lista_busca(Lista2* lst, int dado) {     
    Lista2 *a; //variável usada para percorrer a lista
    for(a=lst;a!=NULL;a=a->prox)  { 
         if(a->info == dado) return a;
     }         
    return NULL;//retorna NULL se não encontrou
}
    
//insere novos elementos no inicio da lista
Lista2* lista_insere( Lista2* lst, int dado) {
      Lista2 *novo= (Lista2*) malloc (sizeof(Lista2));
      novo->info=dado;
      novo->prox=lst;
      novo->ant=NULL;
      //verifica se a lista não esta vazia
      if(lst!= NULL)
         lst->ant=novo;
      return novo;
}
//insere os elementos em ordem
Lista2* lista_ordenada(Lista2* lst, int v) {
    Lista2* novo;
    Lista2* anterior=NULL;
    Lista2* p=lst;
    //cria novo elemento
    novo=(Lista2*)malloc(sizeof(Lista2));
    novo->info=v;
          
    //procura posição de inserção
    while (p!=NULL && p->info < v) {
          anterior=p;
          p=p->prox;
    }     
    //encadeia o elemento
    if(anterior==NULL) {//insere no inicio
        if(lst!=NULL)
		     lst->ant=novo;
         novo->prox=lst;
         novo->ant=NULL;
         lst=novo;
    }      
    else {//insere no meio ou no fim da lista
         novo->prox=anterior->prox;
         novo->ant=anterior;
         if (anterior->prox!=NULL)
             anterior->prox->ant=novo;
         anterior->prox=novo;
    }
    return lst;
}


void lista_mostra(Lista2* lst) {
     Lista2 *aux;//variável usada para percorrer a lista
     for(aux=lst;aux!=NULL;aux=aux->prox)
         printf("%d\t", aux->info);
    printf("\n");
}    
     
Lista2* lista_retira(Lista2* lst, int dado) {
      //procura o elemento na lista usando a função busca
      Lista2* aux=lista_busca(lst, dado);
      if (aux==NULL) //não achou o elemento
          return lst; 
      //retira o elemento encadeado
      if(lst==aux) {//verifica se é o primeiro da lista
        // aux->prox->ant=aux->ant;
         lst=aux->prox;
        }
      else{
	       aux->ant->prox=aux->prox;
	   }
      //testa para ver se é o ultimo da lista
      if (aux->prox!=NULL)        
          aux->prox->ant=aux->ant;
      printf("\nElemento retirado: %d\n",aux->info);    
      free(aux);
      return lst;
}

void lista_libera(Lista2 *lst){
     Lista2 *p,*t;
     p=lst;
     while(p!=NULL){
       t=p->prox;
       free(p);
       p=t;
     }  
}
