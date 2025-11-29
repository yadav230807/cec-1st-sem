#include <stdio.h>
void main()
{
    int a,b,c;
    printf("enter any 3 num:");
    scanf("%d %d %d", &a, &b, &c);
    (a %2 == 0)
    ? printf("%d is even number!\n",a)
    : printf("%d is odd number!\n",a);

    (a > b)
    ? printf("%d is more than %d\n ", a,b)
    : printf("%d is less than %d\n", a,b);
     (a > b)
     ?(a > c)
     ? printf("%d is grater than othernumbers\n", a)
     : printf("%d is grater than othernumbers\n ", c)
     :(b > c)
     ? printf("%d is grater than othernumbers\n ", b)
     : printf("%d is grater than othernumbers\n", c);
     
    }