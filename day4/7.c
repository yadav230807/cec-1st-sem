#include<stdio.h>
void main()
{
    int arr[50],size,sum=0;

    printf("enter the number of element : ");
    scanf("%d", &size);

    printf(" enter any %d element ")
    for(int i= 0; i < size ;i++){
        scanf("%d", &arr[i]);
    }
    printf("the arry elements are as follows: \n");
    for ( int i=0; i < size ; i++){
        printf(" element %d: %d\n",i, arr[i]);
    } 
    
}