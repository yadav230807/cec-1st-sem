#include<stdio.h>
void main()
{
    int n = 20;

    int* nptr =  &n;
    printf("value of n : %d and address of n: %p\n",n, &n);
    printf("Reffering aadress of nptr: %p and nptr refers to value :%d\n", nptr, *nptr);
    *nptr = 30;
    printf("value of n after changes: %d and address of n:%p\n",n , &n);

    printf("value of n after adding 5: %d\n", *nptr + 5);

    printf("value of n after subrating 8: %d\n", *nptr - 8);


}