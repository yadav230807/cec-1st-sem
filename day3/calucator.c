#include<stdio.h>
void main()
{
    int a,b;
    char operator;

    printf("enter any 2 number: ");
    scanf("%d %d",&a,&b);

    printf("choose the operator(+,-,*,/,%) ");
    scanf(" %c",&operator);

    switch(operator){
        case '+':
        printf("sum of %d and%d :%d\n",a ,b,a+b);
        break;

        case '-':
        printf(" difference of %d and%d :%d\n",a ,b,a-b);
        break;

        case '*':
        printf(" multiplication of %d and%d :%d\n",a ,b,a*b);
        break;

        case '/':
        printf(" division of %d and%d :%d\n",a ,b,a/b);
        break;

        case '%':
        printf(" modulus of %d and%d :%d\n",a ,b,a%b);
        break;

        default:
        printf(" invaild option");
        break;

    }

}