#include<stdio.h>
void main()
{
    int arr[50],second=0,largest=0,smallest=0,avg=0;
    printf("enter num of element : ");
    scanf("%d", &size);
      printf("enter any %d element : ", size);
    for(int i= 0; i < size ;i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("the arry elements are as follows: \n");
    for ( int i=0; i < size ; i++){
        printf("  %d\n",arr[i]);
    } 
    printf("even number in the given array: \n");
    for ( int i=0; i < size ; i++){
      if(arr[1]%2 == 0){
        printf("%d", arr[i]);

      }
    printf("odd number in the given array: \n");
    for ( int i=0; i < size ; i++){
      if(arr[1]%2 !=0){
        printf("%d", arr[i]);

      }
    printf("the sum of arry elements : %d\n", sum);
 }
 }
}