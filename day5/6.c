#include<stdio.h>
#include<string.h>
void main(){
    char name[20], fullname[20] ,completename[20];

    printf("enter your name:");
    scanf("%s",&name);

    printf("your frist name is %s \n",name);

    printf(" enter your full name:");
    getchar();
    gets(fullname);

    printf("your name is %s\n",fullname);

    printf("enter your complete name again:");
    
    fgets(completename,sizeof(completename), stdin);

    printf("you name is %s\n",completename);

    printf("size of compelete name arry is %d\n", sizeof(completename));

    printf("you name is %s\n",completename);
}