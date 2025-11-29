#include<stdio.h>
void main(){
    int num, even = 0, odd =0,rem =0;

    printf("enter the number : ");
    scanf("%d", &num);
    
    printf("Given Numbe: %d\n", num);

    while(num > 0){
        rem = num % 10;
        if(rem % 2 == 0){
            even +=rem;
        } else {
            odd +=  rem;
        }
        num = num / 10;
    }
    printf("sum of even digits: %d\n", even);
    printf("sum of odd digits: %d\n", odd);
}
// ?=54
// 