#include<stdio.h>
void main(){
    int num, count=0;

    printf("enter any number:");
    scanf("%d", &num);

    printf("given Number: %d\n",num);

    while(num >= 0)
    {if (num == 0){count = 1;
    }else{
        count++;
        num= num /10;
    }
  printf("number of digits in a given number: %d",count);
}
}