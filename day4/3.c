#include<stdio.h>
void main(){
    int rows;

    printf("enter the number of rows: ");
    scanf("%d", &rows);

     printf("pyramid pattern with stars: \n");
     for(int i=1; i<=rows; i++){
     for(int space=1; space<=rows-i; space++){
     printf("  ");
    }
    for ( int j=1; j<=2*i-1; j++){
        printf("* ");
    } 
    printf("\n");
    }
    printf("pyramid pattern with stars: \n");
     for(int i=1; i<=rows; i++){
     for(int space=1; space<=rows-i; space++){
     printf("  ");
    }
    for ( int j=1; j<=2*i-1; j++){
        printf("%d ",j);
    } 
    printf("\n");
    }
    printf("pyramid pattern with stars: \n");
     for(int i=1; i<=rows; i++){
     for(int space=1; space<=rows-i; space++){
     printf("  ");
    }
    for ( int j=1; j<=2*i-1; j++){
        printf("%d ",i);
    } 
    printf("\n");
    }
}