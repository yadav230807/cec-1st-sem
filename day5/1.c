#include<stdio.h>
void main()
{
    int a[20] = {2,4,6,8,10};
    int* aptr =  a;
    int (*arrayptr)[20] =  &a;
    printf("array contains:\n");
    for(int i=0;i<5; i++)
    {
    printf("%d\t",a[i]);
    }
    printf("\naddress of array:%p\n", &a);

    printf("aptr referingto address: %p and address has:%d \n", aptr ,*aptr);
    printf("array pointer contains :\n");
    for(int i=0;i<5; i++)
    {
        printf("%d\t",(*arrayptr)[i]);
    }
}
    int i = 20;
    float f = 1.45;
    char ch = 'A';

    int* iptr;
    float* fptr; 
    char* cptr;

    iptr = &i;
    fptr = &f;
    cptr = &ch;

    printf(" variable i contains value: %d\n", i);
    printf(" variable i present at : %p\n", &i);
    printf(" iptr refers to : %p\n", iptr);
    printf(" iptr contains : %d\n", *iptr);
    printf(" iptr is present at : %p\n", &iptr);

    printf(" variable f contains value: %f\n", f);
    printf(" variable f present at : %p\n", &f);
    printf(" fptr refers to : %p\n", fptr);
    printf(" fptr contains : %f\n", *fptr);
    printf(" fptr is present at : %p\n", &fptr);

    printf(" variable ch contains value: %c\n", ch);
    printf(" variable ch present at : %p\n", &ch);
    printf(" cptr refers to : %p\n", cptr);
    printf(" cptr contains : %f\n", *cptr);
    printf(" cptr is present at : %p\n", &cptr);


}