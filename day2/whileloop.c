#include<stdio.h>
void main()
{
    int num, i=0;


    printf("enter hoe many number need to be printed:");
    scanf("%d ", &num);
    printf("numbers are as follows: \n");
    while(i < num)
    {
      printf("%d\n",i);
      i++;
    }
}

    