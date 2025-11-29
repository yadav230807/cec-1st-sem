#include<stdio.h>
void main()
{
    int arr[50],size,sum=0;

    printf("enter any size of element : ");

    scanf("%d", &size);

      printf("enter any %d element : ", size);
    for(int i= 0; i < size ;i++){
        scanf("%d", &arr[i]);
    }
    printf("the arry elements are as follows: \n");
    for ( int i=0; i < size ; i++){
        printf("  %d\n",arr[i]);
    } 
    for ( int i=0; i < size ; i++){
       sum = sum + arr [i];
    printf("the sum of arry elements : %d\n", sum);
 }
}