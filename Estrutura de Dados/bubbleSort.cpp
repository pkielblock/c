#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble (int *v, int tam) 
{
	int i, aux, trocou;
	do {
		tam--;
		trocou = 0;
		for(i = 0; i < tam; i++)
		{
			if(v[i] > v[i + 1])
			{
				aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
				trocou = 1;
			}
		}
	} while(trocou);
}

int main()
{
	int v[7], i;
	
	v[0] = 11;
	v[1] = 9;
	v[2] = 8;
	v[3] = 7;
	v[4] = 5;
	v[5] = 4;
	v[6] = 3;
	
	bubble(v, 7);
	
	for(i = 0; i < 7; i++)
	{
		printf("%d ", v[i]);
	}
	
}
