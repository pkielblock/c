#define N 50
typedef struct pilha{
        int n;
        float vet[N];
        }Pilha;

Pilha *pilha_cria(){
      Pilha *p=(Pilha*)malloc(sizeof(Pilha));
      p->n=0;
      return p;
} 

int pilha_vazia(Pilha *p){
    if (p->n==0) return 1;
    return 0;
}

void pilha_push(Pilha *p, float v) {
    if(p->n==N){
      printf("Capacidade da pilha esgotada.\n");
      return; //volta para o programa
      }   //insere novo elemento
       p->vet[p->n]=v;
       p->n++;
	   
}

float pilha_pop(Pilha *p){
     float v;
//retira o elemento da pilha
     v=p->vet[p->n-1];  
     p->n--;
     return v;
}

void pilha_libera(Pilha *p){
     free(p);
}
    
void pilha_mostra(Pilha *p) {
     printf("Conteudo da pilha\n");
     for(int i=p->n-1;i>=0;i--)
         printf("%.2f\n",p->vet[i]);
     printf("\n");
} 
