#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	int v[7], i;
	
	v[0] = 3;
	v[1] = 1;
	v[2] = 5;
	v[3] = 4;
	v[4] = 6;
	v[5] = 2;
	v[6] = 8;
	
	insertionSort (v, 7);
	
	for(i = 0; i < 7; i++)
	{
		printf("%d ", v[i]);
	}
	
}
