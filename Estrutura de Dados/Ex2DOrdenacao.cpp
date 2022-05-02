#include <stdio.h>

void quickSort (int v[], int primeiro, int ultimo) 
{
	int i, j, m, aux;
	i = primeiro;
	j = ultimo;
	m = v[(i+j)/2];
	
	do {
		while (v[i] < m) 
		{
			i++;	
		}
		while (v[j] > m)
		{
			j--;
		}
		
		if (i <= j)
		{
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
	} while (i <= j);
	
	if(primeiro < j) //Chamada recursiva 1ª Metade
	{
		quickSort(v, primeiro, j);
	}
	if(ultimo > i) //Chamada recursiva 2ª Metade
	{
		quickSort(v, i, ultimo);
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
	
	quickSort(v, 0, tam);
	
	for(i = 0; i <= tam; i++)
	{
		printf("%d ", v[i]);
	}
}
