#include<stdio.h>
int main(void)
{
    int a[5] = {19, 23, 29, 31, 37}, i, count;

    for(i = 0;i <= 4;i++)
    {
        printf("A[%d] = %d\n", i, a[i]);
    }
    
    printf("\n");

    count = 4;
    while(count >= 0)
    {
        printf("A[%d] = %d\n", count, a[count]);
        count--;
    }

    return 0;
}