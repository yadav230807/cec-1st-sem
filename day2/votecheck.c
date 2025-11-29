#include<stdio.h>
void main ()
{
    int age;

    printf("enter the age");
    scanf("%d", &age);

    if (age > 0)
    {
        if (age > 18)
      {  
        printf("you can vote");
      }
      else
      { 
        printf("you need to be 18 to vote");
      }
    }
}