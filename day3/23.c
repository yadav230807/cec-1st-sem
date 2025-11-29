#include<stdio.h>
void main(){
    int operation;
    int a,b;
    do
    {
        printf("enter any 2 number: ");
        scanf("%d %d",&a,&b);
        printf("select any operation : \n");
        printf("1.ADD\n");
        printf("2.SUB \n");
        printf("3.MUL\n");
        printf("4.DIV FOR QUOT\n");
        printf("5.DIV FOR REM \n");
        printf(" 6.Exit \n");
        scanf("%d", &operation);

        switch(operation)
        {
            case 1:
             printf("sum of %d and%d :%d\n",a ,b,a+b);
             break;

            case 2:
            printf(" difference of %d and%d :%d\n",a ,b,a-b);
            break;

            case 3:
            printf(" multiplication of %d and%d :%d\n",a ,b,a*b);
            break;

            case 4:
            printf(" division of %d and%d :%d\n",a ,b,a/b);
            break;

            case 5:
            printf(" modulus of %d and%d :%d\n",a ,b,a%b);
            break;

            case 6:
            printf("thank you for use");
            break;

           default:
          printf(" invaild option");
           break;

        }


    }while (operation!=6);
}