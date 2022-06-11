#include <stdio.h>
#include <stdlib.h>
#include <time.h>
	
typedef struct lista{
	int conta;
	float saldo;
	struct lista *ant;
	struct lista *prox;
}Lista;

typedef struct arv{
	int codigo;
	float preco;
	struct arv *left;
	struct arv *right;
}Arv;
	
void preencheVetor(int v[], int n){
		int i = 0;
		while(i < n){
			int numero = rand() % n + 1;
			for(int j = 0; j < n; j++){
				if(numero == v[j]){
					numero = rand() % n + 1;
					j = -1;
				}
			}
			v[i] = numero;
			i++;
			printf("%d ", numero);
		}

	}
	
	int pesquisaVetor(int v[], int tam, int valor){
		int i = tam;
		if(v[i] == valor){
			printf("\n%d", i);
			return i;
		}
		
		i--;
		pesquisaVetor(v, i, 4);
	}
	
	void procuraConta(Lista *final, int cc){
		if(final->conta == cc){
			printf("conta: %d com saldo de: %.2f", final->conta, final->saldo);
		}else if(final->ant == NULL){
			printf("Conta n�o encontrada!");
		}else {
			procuraConta(final->ant, cc);
		}
	}
	
	void leArq(FILE *Arq, int t){
		float soma, prim = NULL, ult, saida;
		if(Arq != NULL && t < 2){
			while(fread(&saida,sizeof(ult), 1, Arq) == 1){
				if(!prim){
					prim = saida;
				}
				soma += saida;
				ult = saida;
				printf("%f\n", saida);
			}
			printf("Primeiro: %.2f\nSoma: %.2f\nUltimo: %.2f", prim, soma, ult);
		}else {
			printf("Dados insuficientes");
		}
		
	}

	void mostraMenor (Arv *t, float valor) {
		if(t != NULL){
			if(t->left != NULL){
				mostraMenor(t->left, valor);
			}
			if(t->preco < valor){
				printf("\nMenor preco: %.2f", t->preco);
			}
			if(t->right != NULL){
				mostraMenor(t->right, valor);
			}
		}
	}

	int contaNota(Arv *t, float valor1, float valor2){
		int cont = 0;
		if(t != NULL){
			if(t->preco >= valor1 && t->preco <= valor2){
				cont++;
			}
			if(t->left != NULL){
				cont += contaNota(t->left, valor1, valor2);
			}
			if(t->right != NULL){
				cont += contaNota(t->right, valor1, valor2);
			}
		}
		return cont;
	}
		
int main(){

	Lista *conta1 = (Lista*)malloc(sizeof(Lista));
	Lista *conta2 = (Lista*)malloc(sizeof(Lista));
	Lista *conta3 = (Lista*)malloc(sizeof(Lista));
	
	conta1->conta = 1;
	conta1->saldo = 22.33;
	conta1->ant = NULL;
	conta1->prox = conta2;

	conta2->conta = 2;
	conta2->saldo = 144.79;
	conta2->ant = conta1;
	conta2->prox = conta3;
	
	conta3->conta = 3;
	conta3->saldo = 948.47;
	conta3->ant = conta2;
	conta3->prox = NULL;

	Arv *arvore = (Arv*)malloc(sizeof(Arv));

	arvore->codigo = 1;
	arvore->preco = 12.99;
	arvore->left = arvore->right = NULL;


	//////////////////////////////////////////////////////
	FILE *arq;
	arq = fopen("numBinario", "rb");
	
	int n = 5;
	int v[n];
	
	srand(time(NULL));
	preencheVetor(v, n);
	pesquisaVetor(v, n, 4);
	printf("\n");
	
	
	//////////////////////////////////////////////////////
	
	procuraConta(conta3, 2);
	printf("\n");
	leArq(arq, 4);
	
	/////////////////////////////////////////////////////
	mostraMenor(arvore, 13.99);	
	printf("\n");

	int cont = contaNota(arvore, 12, 13);
	printf("Numero de elementos: %d\n", cont);

	system("pause");
	return 0;
}
