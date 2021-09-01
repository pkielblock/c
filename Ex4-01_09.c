#include<stdio.h>
int main(){

    int min, max, i;

    do
    {
        printf("Min (> 1000): ");
        scanf("%d", &min);
    } while (min <= 1000);
    do
    {
        printf("Max (> Min): ");
        scanf("%d", &max);
    } while (max <= min);

    for (i = min; i <= max; i++)
    {
        if (i % 5 == 0)
        {
            printf("%d\n", i);
        }   
    }

    return 0;
}