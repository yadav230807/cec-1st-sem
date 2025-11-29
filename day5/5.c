#include<stdio.h>
void main(){
    int size;
    char name[20];

    printf("enter the number of charector in your name: \n");
    scanf("%d", &size);

    printf(" enter your first name: ");
    for(int i=0; i<size; i++){
        scanf(" %c", &name[i]);

    }
     printf( " you've entered :  \n");
    for(int i=0; i<size; i++){
        printf("%c", name[i]);
  }
}