#include <stdio.h>

void insertionSort (int *v, int n) 
{
	int i, j, chave;
	for (j = 1; j < n; j++)
	{
		chave = v[j];
		i = j-1;
		while(i >= 0 && v[i] > chave)
		{
			v[i+1] = v[i];
			i--;
		}
		v[i+1] = chave;
	}
	
}

int main()
{
	int tam = 8; 
	int v[tam], i;
	
	v[0] = 11;
	v[1] = 37;
	v[2] = 8;
	v[3] = 43;
	v[4] = 29;
	v[5] = 18;
	v[6] = 41;
	v[7] = 51;
	v[8] = 25;
	
	insertionSort(v, tam);
	
	for(i = 0; i < tam; i++)
	{
		printf("%d ", v[i]);
	}
}
