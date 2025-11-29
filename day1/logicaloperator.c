//AND(&&),OR(||),NOT(!)
//AND(X)
// A   B  RESULT
// 0   0    0
// 0   1    0
// 1   0    0
// 1   1    1
//OR(+)
// A   B  RESULT
// 0   0    0
// 0   1    1
// 1   0    1
// 1   1    1
// NOT(TOGGLE)
// A   RESULT
// 0     1
// 1     0
#include<stdio.h>
void main()
{
    int number = 10;
    int number2 = 20;

    if (number > 5 && number < 20 )
    {
        printf("%d is b/w 5 & 20", number);
    }
     if (number2 > 5 && number2 < 20 )
    {
        printf("%d is b/w 5 & 20", number2);
    } 
    esle 
        { 
            printf("%d is not b/w 5 & 20", number2);
        } 
}