#include<stdio.h>
void main()
{
    int i = 10;
    char c = '+';
    float f =3.142;

    //shfit +alt+Bottom Arrow
    printf("integer i contains :%d, size of int:%d\n", i,sizeof(i));
    printf("float f contains :%f, size of float:%d\n", f,sizeof(f));
    printf("char c contains :%c, size of char:%d\n", c,sizeof(c));
}       