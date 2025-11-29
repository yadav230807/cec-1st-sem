#include<stdio.h>
void main()
{
    int day;

    printf(" enter any numbert b/w 1 to 7 : ");
    scanf("%d",&day);

    switch(day){
        case 1 : 
        printf("day 1: Monday");
        break;

        case 2: 
        printf("day 2: tuesday");
        break;

        case 3: 
        printf("day 3: wednesday");
        break;

        case 4: 
        printf("day 4: thursday");
        break;

        case 5: 
        printf("day 5: friday");
        break;

        case 6: 
        printf("day 5: saturday");
        break;

        case 7: 
        printf("day 5: sunday");
        break;
        default:
        printf("invail input");
        break;

    }

}