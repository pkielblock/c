#include <stdio.h>

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
	
	bubble(v, tam);
	
	for(i = 0; i < tam; i++)
	{
		printf("%d ", v[i]);
	}
}
