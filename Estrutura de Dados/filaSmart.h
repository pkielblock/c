#define N 5
//compactação inteligente
typedef struct {
        int n;//posicao final
        int ini;
        float vet[N];
        }Fila;

Fila *fila_cria(void){
      Fila *f=(Fila*)malloc(sizeof(Fila));
      f->n=0;
      f->ini=0;
      return f;
}      
//-------------------------------------------------------------
void compacta(Fila *f){//compactação inteligente
	for(int i=0;i<f->n;i++)
        f->vet[i]=f->vet[i+f->ini];//pulos maiores
    //depois de compactar os dados corrige o inicio e o fim
     f->n= f->n- f->ini;
     f->ini=0;
}        
void fila_insere(Fila *f, float v){
    int tamfila= f->n - f->ini;
    if(tamfila==N){
	 //fila cheia
      printf("Capacidade da fila esgotada.\n");
      return; //retorna ao programa 
  	}
	if(f->n ==N) 
		compacta(f);
	  //insere novo elemento
    f->vet[f->n]=v;
    f->n++; 
}
//------------------------------------------------------------------
            
int fila_vazia(Fila *f){
    return(f->n==f->ini);
    /*if(f->n==f->ini)
        return 1;
    return 0;*/
}

float fila_retira(Fila *f){
     float v;
     //retira o elemento da fila
     v=f->vet[f->ini];
     f->ini++;
     return v;
}
void fila_libera(Fila *f){
     free(f);
}                           
void fila_mostra(Fila *f){
	 if (fila_vazia(f))
	    print("Fila vazia\n");
	 else{
	      printf("Conteudo da fila\n");
          for(int i=f->ini;i<f->n;i++)
              printf("%0.f\n",f->vet[i]);
     	  printf("\n");
 	 }
}               

