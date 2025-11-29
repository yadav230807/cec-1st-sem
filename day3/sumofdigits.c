#include<stdio.h>
void main()
{
int a, sum=0;

printf("enter any number: ");
scanf("%d",&a);
printf("original number: %d\n", a);

while(a > 0){
    sum =sum + a % 10;
    a= a /10; 
}
printf("sum of the given digits: %d", sum);
}

// tracing:
//  num = 13579
// 