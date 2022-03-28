typedef struct lista {
       float info;
       struct lista* prox;
}Lista;

typedef struct{
        Lista *ini;//ponteiro para o primeiro elemento
        Lista *fim;//ponteiro para o ultimo elemento
}Fila;

Fila *fila_cria(){
     Fila *f=(Fila*)malloc(sizeof(Fila));
     f->ini=NULL;
     f->fim=NULL;
     return f;
}
void fila_insere (Fila *f,float v)
 {
        Lista* novo= (Lista*) malloc(sizeof(Lista));
        novo->info=v;
        novo->prox=NULL;
        if (f->ini==NULL)//primeiro da Fila
        {
             f->ini=novo;
             f->fim=novo;
             } 
        else   
           {
               f->fim->prox=novo;
               f->fim=novo;
               }
 }
float fila_retira(Fila *f){
    float v;
    Lista *aux;
    aux=f->ini;
    v=aux->info;
    f->ini=aux->prox;
    free(aux);
    return v;
}
void fila_mostra(Fila *f){
      Lista *l;
      for(l=f->ini;l!=NULL;l=l->prox)
        printf ("%.0f\n", l->info);
     
}
int fila_vazia(Fila *f){
    return (f->ini==NULL);
}
void fila_libera(Fila *f){
     Lista *q= f->ini;
     while (q!=NULL) {
           Lista *t=q->prox;
           free(q);
           q=t;
           }
     free(f);
}     
