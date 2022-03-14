#define N 50
typedef struct fila{
        int ini; //inicio da fila
        int fim; //fim da fila
        float *vet;//ponteiro para um vetor de float  
        int tamVetor;//numero de elementos do vetor
        
        int tamFila;//explicito para fila circular
        
        }Fila;

Fila *fila_cria(void){
      Fila *f=(Fila*)malloc(sizeof(Fila));
      f->fim=0;
      f->ini=0;
      f->tamFila=0;//item explicito
      f->tamVetor=N;
      f->vet=(float*)malloc(sizeof(float)*f->tamVetor);//alocação da área onde está o vetor
      return f;
}      

void fila_insere(Fila *f, float v){
    if(f->tamFila < f->tamVetor){ // tem espaço
        if(f->fim==f->tamVetor)// ultima posição do vetor está ocupada
           f->fim=0;
        //insere o elemento
        f->vet[f->fim]=v;
        f->fim++;
        f->tamFila++;//ao inserir incremeta o tamanho da fila
    }
    else
       printf("Fila cheia\n");
}        
int fila_vazia(Fila *f){
    return(f->tamFila==0);
}

float fila_retira(Fila *f){
     float v;
     //retira o elemento da fila
     v=f->vet[f->ini];
     if(f->ini==f->tamVetor-1)//último indice
        f->ini=0;
     else
        f->ini++;
        
     f->tamFila--;//remoção - decrementa o tamanho da fila
     return v;
}
void fila_libera(Fila *f){
     free(f->vet);//libera vetor
     free(f);//libera a fila
}                           
void fila_mostra(Fila *f){
	 if (f->tamFila==0){
	    printf("Fila vazia\n");
	    return;
	}
     printf("Conteudo da fila\n");
     int i;
     if(f->ini < f->fim) //fila não circulou
       for(i=f->ini;i<f->fim;i++)
              printf("%.0f\n",f->vet[i]);
     else{//fila circulou
          for(i=f->ini;i<f->tamVetor;i++)
              printf("%.0f\n",f->vet[i]);
          for(i=0;i<f->fim;i++)
             printf("%.0f\n",f->vet[i]);
          }
     printf("\n");
}               

