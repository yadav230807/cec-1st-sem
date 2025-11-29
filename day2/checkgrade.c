#include<stdio.h>
void main()
{
    int marks;
    printf("Enter your marks");
    scanf("%d", &marks);

 if(marks >= 35 && marks < 60)
   {
    printf("you've passed the exam");
   }
 else if ( marks >= 60 && marks < 70)
   {
    printf(" you have b grade");
   }
 else if ( marks >= 70 && marks < 85)
  {
    printf(" you have A grade"); 
  }
 else if ( marks >= 85)
  {
    printf(" you have distrinction");
  }
 else 
 {
    printf("you have fail");
 }
}