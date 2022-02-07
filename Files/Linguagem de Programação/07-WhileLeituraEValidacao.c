#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;

    do
    {
        printf("N (<100): ");
        scanf("%d", &n);

        if (n >= 100)
        {
            printf("\n%d e muito grande\n\n", n);
        }

    } while(n >= 100);
	
	printf("\n%d E um bom valor\n", n);

	printf("\nFim do Programa\n");
	system("pause");
}