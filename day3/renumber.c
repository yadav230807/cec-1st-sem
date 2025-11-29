#include<stdio.h>
void main()
{ 
    int a, rev = 0 , rem=0;


    printf("enter any number: ");
    scanf("%d", &a);
    printf("original number: %d\n", a);

    while(a > 0){
        rem = a % 10;
        rev = rev * 10 + rem;
        a = a / 10;

    }
    printf("revesed Number: %d", rev);
}
// tracing
// a=123
// step 1
// while(123>0)T
// rem= 123 % 10 =>3
// nev = 0* 10+3 =3
// 123 = 123/10=12
// step 2
// while(12>0)T
// rem= 12 % 10 =>2
// nev = 3* 10+2 =32
// 12 = 12/10=1
// step 3
// while(1>0)T
// rem= 1 % 10 =>1
// nev = 32* 10+1 =321
// 1 = 1/10=0
// step 3
// while(0>0)F
