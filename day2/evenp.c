#include<stdio.h>
void main()
{
    int num, i=1;


    printf("how many  even number need to be printed:");
    scanf("%d", &num);
    printf(" the even numbers till %d are as follows: \n");
    while(i <= num)
    { 
        if(i % 2 == 0){
      printf("%d\n",i);
    }
    i++;
 }
}
    