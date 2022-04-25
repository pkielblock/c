#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
	int v[7], i;
	
	v[0] = 5;
	v[1] = 8;
	v[2] = 9;
	v[3] = 6;
	v[4] = 2;
	v[5] = 7;
	v[6] = 4;
	
	selectionSort (v, 7);
	
	for(i = 0; i < 7; i++)
	{
		printf("%d ", v[i]);
	}
	
}
