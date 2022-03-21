//lista simplesmente encadeada

typedef struct lista {
       int info;
       struct lista* prox;
}Lista;

Lista* lista_cria() { //função simbólica - inicializa a lista com NULL
        return NULL;
}
int lista_vazia(Lista* ls){//retorna o resultado da comparação entre ls e NULL (se Verdadeiro volta 1)
    return(ls==NULL);
}

Lista* lista_busca(Lista* ls, int dado) {     
    Lista *a; //variável auxiliar usada para percorrer a lista
    for(a=ls;a!=NULL;a=a->prox) { 
         if(a->info == dado) return a;// se achou retorna o item da lista contendo a info e o ponteiro 
         							  //para o próximo
    }
    return NULL;// se não achou retorna NULL
}

Lista* lista_insere(Lista* ls, int dado) {//insere no inicio
      Lista *novo= (Lista*) malloc (sizeof(Lista));
      novo->info=dado;
      novo->prox=ls;
      return novo;//retorna ao programa o item recém inserido
}

void lista_mostra(Lista* ls) {
     Lista *aux;//variável usada para percorrer a lista
     for(aux=ls;aux!=NULL;aux=aux->prox)
         printf("%d\t", aux->info);
     printf("\n");
}         
  
Lista* lista_retira(Lista* ls, int dado){
      Lista* ant=NULL; //ponteiro para o anterior
      Lista *aux=ls;// ponteiro para percorrer a lista  
      //procura o elemento na lista guardando seu anterior
      while(aux!=NULL && aux->info!=dado) {
            ant=aux;
            aux=aux->prox;
      }
      //verifica se achou o elemento
      if(aux==NULL) {
           printf("\nNAO localizado\n");         
           return ls; //não achou - retorna a lista
      }
      //retira o elemento
      if (ant==NULL) //primeiro da lista
         ls=aux->prox;
      else
        //retira do meio da lista
        ant->prox=aux->prox;
      free(aux);
      return ls;
}

//Opcionalmente pode-se inserir na lista de forma ordenada
Lista* lista_ordenada(Lista* ls, int v) {
    Lista* novo;
    Lista* ant=NULL;
    Lista* p=ls;
    
    //cria novo elemento
    novo=(Lista*)malloc(sizeof(Lista));
    novo->info=v;
        
    //procura posição de inserção
    while (p!=NULL && p->info < v)  {
          ant=p;
          p=p->prox;
    }     
    //encadeia o elemento
    if(ant==NULL) { //insere no inicio
         novo->prox=ls;
         ls=novo;
    }
    else //insere no meio ou no fim da lista
    {
         novo->prox=ant->prox;
         ant->prox=novo;
     }
     return ls;
} 

void lista_libera(Lista *ls){//libera a memória utilizada pela lista
     Lista *p,*t;//ponteiros auxiliares
     p=ls;
     while(p!=NULL){
       t=p->prox;
       free(p);
       p=t;
     }                           
}

