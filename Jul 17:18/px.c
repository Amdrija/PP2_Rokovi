#include <stdio.h>

int main()
{
    int p[5] = {0, 1, 2 ,3 ,4};
    int *a = p;
    int (*r)[2] = (int(*)[2])p;
    printf("%d" , --*a++);
    printf("%d",*a);
}