#include<stdio.h>
int sumofnum(int num)
{
    if(num == 0) return 0;
    return num + sumofnum(num - 1);
}
void main()
{
    int n;
    printf("enter the number to find the sum of the numbers:");
    scanf("%d",&n);
printf("sum of 0 to %d is : %d\n", n, sumOfNum(n));

}








