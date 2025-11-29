#include<stdio.h>
void main(){
    
     int size ,arr[50] ,largest = 0, second = 0, smallest = 0, total=0,avg = 0;

    printf(" enter any size of element:" ,size);

    scanf("%d",&size);
    for(int i=0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("the arry elements are as follows: \n");
    for(int i=0; i<size; i++){
        printf("element %d: %d\n",i,arr[i]);
    }
     largest = arr[0];

     smallest = arr[0];

     for(int i=0; i< size; i++){
        total= total +arr[i];
        if(arr[i] > largest){
            largest= arr[i];
        }
        if(arr[i] < smallest){
            smallest= arr[i];
        }
    }

    avg = (total)/size;
    printf("largest element in the given array: %d",largest);
    printf("smallest element in the given array: %d",smallest);
    printf(" avg value in the given array: %d",avg);
}