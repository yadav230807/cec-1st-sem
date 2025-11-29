#include<stdio.h>
void main()
{
    int choice;

    

    do{
        printf("choose any of the option: \n ");
      printf("1. welcome\n");
      printf("2.good mornig\n");
      printf("3.good aftrnoon\n");
      printf("4.good evening\n");
      printf("5.good night\n");
      scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("wlecome to cprograming irp\n");
            break;

            case 2:
            printf("good mornig\n");
            break;

            case 3:
            printf("good aftrnoon \n");
            break;

            case 4:
            printf("good evening\n");
            break;

            case 5:
            printf("good night\n");
            break;

            default:
            printf("invail choice\n");
       }
    } while (choice !=5);
}