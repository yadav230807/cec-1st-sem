#include<stdio.h>
void main()
{
    int i, rows;
    printf("enter num of rows:");
    scanf("%d", &rows);
    printf("square pattern:\n");
    
    for(int i=1 ;i<=rows; i++)
    {
      for(int j=1 ;j<= rows; j++)
     {
      // if we print a symbol it will print 
      // if we print a j value , we will get numbers
    //    printf("*");
       printf("%d",j);
    //    printf("%d",i);
     }
     printf("\n");
    }
}

