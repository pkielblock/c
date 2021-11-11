#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>

struct TDados {
  int Qtde;
  double Preco;
};

void ExibeVetor(TDados *pV, int pTamV);
void OrdenaPelaQtde(TDados *pV, int pTamV);
void OrdenaPeloPreco(TDados *pV, int pTamV);

int main() 
{
  TDados *Dados;
  int Tam;
  FILE *ArqEnt;
  TDados UmDado;
  
  ArqEnt = fopen("dadosVetor.txt", "r");
  Dados = NULL;
  Tam = 0;
  while (fscanf(ArqEnt, "%d;%lf", &UmDado.Qtde, &UmDado.Preco) != EOF) {
    Tam++;
    Dados = (TDados *)realloc(Dados, sizeof(TDados) * Tam);
    Dados[Tam-1] = UmDado;
  }
  fclose(ArqEnt);
  
  printf("\nDados nao ordenados\n");
  ExibeVetor(Dados, Tam);

  printf("\nVetor ordenado pela Quantidade\n");
  OrdenaPelaQtde(Dados, Tam);
  ExibeVetor(Dados, Tam);

  printf("\nVetor ordenado pelo Preco (decrescente)\n");
  OrdenaPeloPreco(Dados, Tam);
  ExibeVetor(Dados, Tam);

  printf("\n\nFim do programa");
  return 0;
}

void ExibeVetor(TDados *pV, int pTamV) 
{
  int i;
  for (i = 0; i < pTamV; i++) {
    printf("%6d %8.2lf\n", pV[i].Qtde, pV[i].Preco);
  }
  printf("\n");  
}

void OrdenaPelaQtde(TDados *pV, int pTamV) 
{
  TDados aux;
  int i;
  bool Trocou;
  
  do {
    Trocou = false;
    i = 0;
    while (i < pTamV-1) {
      if (pV[i].Qtde > pV[i+1].Qtde) {
        aux = pV[i];
        pV[i] = pV[i+1];
        pV[i+1] = aux;
        Trocou = true;
      }
      i = i + 1; 
    }
  } while (Trocou);  
}
  
void OrdenaPeloPreco(TDados *pV, int pTamV) 
{
  TDados aux;
  int i;
  bool Trocou;
  
  do {
    Trocou = false;
    i = 0;
    while (i < pTamV-1) {
      if (pV[i].Preco < pV[i+1].Preco) {
        aux = pV[i];
        pV[i] = pV[i+1];
        pV[i+1] = aux;
        Trocou = true;
      }
      i = i + 1; 
    }
  } while (Trocou);  
}