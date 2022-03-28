typedef struct lista2 {
       int matricula;
       float nota;
       lista2* ant;
       lista2* prox;
}Lista2;

Lista2* lista_cria() {
        return NULL;
}
int lista_vazia(Lista2* lst) {
    if(lst==NULL) return 1;
    return 0;
}

Lista2* lista_busca(Lista2* lst, int dado) {     
    Lista2 *a; //variável usada para percorrer a lista
    for(a=lst;a!=NULL;a=a->prox)  { 
         if(a->matricula == dado) return a;
     }         
    return NULL;//retorna NULL se não encontrou
}
    
Lista2* lista_ordenada(Lista2* lst, int v, float n) {
    Lista2* novo;
    Lista2* anterior=NULL;
    Lista2* p=lst;
    //cria novo elemento
    novo=(Lista2*)malloc(sizeof(Lista2));
    novo->matricula=v;
    novo->nota=n;
          
    //procura posição de inserção
    while (p!=NULL && p->matricula < v) {
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
         printf("%d  - %.2f\n", aux->matricula, aux->nota);
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
      printf("\nElemento retirado: %d\n",aux->matricula);    
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
