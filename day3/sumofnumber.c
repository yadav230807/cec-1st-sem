#include<stdio.h>
void main()
{
    int a, sum=0, i = 0 ;

    printf("enter the number to find the sum");
    scanf("%d",&a);

    while(i <= a){
        sum = sum + i;
     i++;
    }
     printf("sum of 0 to %d: %d", a, sum);

}

// tracing
// 