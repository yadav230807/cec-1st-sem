#include <stdio.h>
void main()
{
    int arr[50], size, revv[50];
    printf(" enter the element: ");
    scanf("%d", &size);
    printf("enter any %d elements:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        printf("element %d : %d \n", i, arr[i]);
    }
    for (int i = size - 1, j = 0; i >= 0; i--, j++)
    {
        revv[j] = arr[i];
    }

    printf(" reversed array elements are as follows : \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d \n ", revv[i]);
    }
}