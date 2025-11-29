#include<stdio.h>
void main(){
    int i=5;
    int *ptr;
    ptr = &i;

    printf("the value in i is : %d\n",i);
    printf("the address in i is : %p\n",&i);
    printf("pointer ptr contains:%p\n",ptr);
    printf("pointer value contains:%d\n",*ptr);
    printf("address of the pointer:%p\n",&ptr);
}