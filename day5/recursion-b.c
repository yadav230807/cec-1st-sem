#include <stdio.h>
void printEvenNumbers(int n)
{
    if (n == 0) return;
    printEvenNumbers(n - 1);
    if(n % 2 == 0)
    printf("%d ", n);
}
void main()
{
    int a, b;
    printf("how many even numbers to be printed?\n");
    printf("give the even numbers to be printed:");
    scanf("%d %d", &a, &b);
    printEvenNumbers(a);
    printEvenNumbers(b);
}