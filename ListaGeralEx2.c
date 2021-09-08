#include<stdio.h>
int main (){

    int valor, par = 0, impar = 0;

    FILE *arq;
    arq = fopen("ListaGeralEx2.txt", "w");

    while(1)
    {
        scanf("%d", &valor);

        if (valor == 0)
        {
            printf("Pares: %d\n", par);
            printf("Impares: %d\n", impar);
            fprintf(arq, "Pares: %d\n", par);
            fprintf(arq, "Impares: %d\n", impar);
            
            fclose(arq);
            return 0;
        }
        else if (valor % 2 == 0)
        {
            par = par + valor;
        }
        else if (valor % 2 != 0)
        {
            impar = impar + valor;
        }
    }
}