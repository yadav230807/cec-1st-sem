#include<stdio.h>
void main()
{
    int num;
    float decimal;
    char symbol;

    printf("enter any integer value: "); 
    scanf("%d", &num);
    printf("enter any decimal value: "); 
    scanf("%f", &decimal);
    printf("enter any  symbol: ");
    scanf(" %c", &symbol); 

    printf("₹4you've given %d for integer , %f for float , %c for symbol", num, decimal, symbol); 
}