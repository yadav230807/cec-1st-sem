#include<stdio.h>
void main ()
{
    int a,b,c;
    printf("enter the 3 number");
    scanf("%d %d %d", &a,&b,&c);
    if (a > b)
    {
        if( a > c)
       {
         printf("%d id the greatest of all the 3 number", a);
       }
    
     else
     {
      printf("%d id the greatest of all the 3 number", c);
     }
    }
else
    if (b > c)
    {
        printf("%d id the greatest of all the 3 number", a);
    }
 else
    {
      printf("%d id the greatest of all the 3 number", c);
    }
}