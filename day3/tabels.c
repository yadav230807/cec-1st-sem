#include<stdio.h>
void main()
{
    int num, i =1;

    printf("enter the number to print the tables");
    scanf("%d",&num);

    printf("the tables for the number our follows:\n");
    while(i <= 100000000){
        printf("%d * %d = %d\n", num, i, num * i);
        i++;
    }

}