#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	int v[5], i;
	
	v[0] = 5;
	v[1] = 3;
	v[2] = 1;
	v[3] = 2;
	v[4] = 4;
	
	quickSort (v, 0, 4);
	
	for(i = 0; i < 5; i++)
	{
		printf("%d ", v[i]);
	}
	
}
