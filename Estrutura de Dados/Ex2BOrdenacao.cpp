#include <stdio.h>

void selectionSort (int *num, int tam) 
{
	int i, j, min;
	for (i = 0; i < (tam-1); i++)
	{
		min = i;
		for (j = (i+1); j < tam; j++)
		{
			if(num[j] < num[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			int swap = num[i];
			num[i] = num[min];
			num[min] = swap;
		}
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
	
	selectionSort(v, tam);
	
	for(i = 0; i < tam; i++)
	{
		printf("%d ", v[i]);
	}
}
