#include<stdio.h>
void main()
{
    int month;

    printf(" enter any numbert b/w 1 to 12 : ");
    scanf("%d",&month);

    switch(month){
        case 1 : 
        printf("month 1: JAN");
        break;

        case 2: 
        printf("month 2: FEB");
        break;

        case 3: 
        printf("month 3: MAR");
        break;

        case 4: 
        printf("month 4: APR");
        break;

        case 5: 
        printf("month 5: MAY");
        break;

        case 6: 
        printf("month 5: JUNE");
        break;

        case 7: 
        printf("month 5: JULY");
        break;

        case 8: 
        printf("month 8: AUG");
        break;
        case 9: 
        printf("month 9: SEP");
        break;
        case 10: 
        printf("month 10: OCT");
        break;
        case 11: 
        printf("month 11: NOV");
        break;
        case 12: 
        printf("month 12: DEC");
        break;
        default:
        printf("invail input");
        break;

    }

}