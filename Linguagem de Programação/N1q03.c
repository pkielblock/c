#include <stdio.h>
#include <math.h>

int main()
{
    printf("Pedro Henrique Sampaio Kielblock\n");
    printf("1680482112029\n");
    printf("Henrique Ernandes Rebelo\n");
    printf("1680482112038\n");
    printf("Questao 3\n");
    
    int min = 0, max = 0, i, j, soma = 0, qnt = 0, res;
    
    
    while(min <= 1){
        printf("Min = ");
        scanf("%d",&min);
        if(min <= 1){
            printf(" Minimo invalido\n");
        }
    }
    while(max <= min){
        printf("Max = ");
        scanf("%d",&max);
        if(max <= min){
            printf(" Maximo invalido\n");
        }
    }
    
    for(i = min; i <= max; i++){
        res = 0;
        for(j = 2; j < i; j++){
            if(i % j == 0){
                res = 1;
            }
        }
        if(!res){
            printf("%d \n",i);
            qnt++;
            soma += i;
        }
    }
    
    printf("Quantidade de primos no intervalo[%d, %d] = %d \n",min , max, qnt);
    printf("Soma dos primos no intervalo[%d, %d] = %d \n",min , max, soma);
    
    printf("\n\nFim do Programa\n\n");
    system("pause");
    return 0;
}

