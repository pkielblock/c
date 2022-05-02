#include <stdio.h>
#include <string.h>
void bubble (char v[][6], int tam) 
{
	int i, trocou;
	char temp[6];
	tam--;
	do {
		trocou = 0;
		for(i = 0; i < tam; i++)
		{
			if(strcmp(v[i], v[i+1]) > 0)
			{
				strcpy(temp, v[i]);
				strcpy(v[i], v[i+1]);
				strcpy(v[i]+1, temp);
				trocou = 1;
			}
		}
	} while(trocou);
}

int main()
{
	int tam = 2;
	int i;
	char v[][6] = {"pedro", "vtsp"};
	
	bubble(v, tam);
	
	for(i = 0; i < tam; i++)
	{
		printf("%s\t ", v[i]);
	}
}
