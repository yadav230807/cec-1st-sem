#include<stdio.h>
void main()
{
    int a, b;
    printf("enter any 2 number");
    scanf("%d %d", &a , &b);
    ( a % 2 == 0)
    ? printf("%d is the even number", a)
    : printf("%d is the odd number", a);
    (a > b)
    ? printf("%d is grater than %d", a, b)
    : printf("%d is smaller than %d", a, b);
}
