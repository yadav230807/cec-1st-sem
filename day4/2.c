#include<stdio.h>
void main()
{
    int  rows;
    printf("enter num of rows: ");
    scanf("%d", &rows);

    printf("right angled triangle pattern:  \n");
    for(int i=1; i<=rows; i++){
     for(int j=1; j<=i; j++){
     printf("* ");
    }
    printf("\n");
    }
    printf("right angled triangle pattern j:  \n");
    for(int i=1; i<=rows; i++){
     for(int j=1; j<=i; j++){
     printf("%d", j);
    }
    printf("\n");
    }
    printf("right angled triangle pattern i:  \n");
    for(int i=1; i<=rows; i++){
     for(int j=1; j<=i; j++){
     printf("%d", i);
    }
    printf("\n");
    }
    
}