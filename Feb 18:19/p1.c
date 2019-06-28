#include <stdio.h>

int f(int x)
{
    return 0;
}

int main()
{
    int (*v)(int) = &f;
    v--;
    int a = 1;
    int *p = &a;
    printf("%p\n",&p);

    char *c;
    c = (char*)(p + 1);

    int q[2] = {2,1};
    int (*r)[2] = (int(*)[2])q;
    printf("%d %d",**r, *(*r + 1));

    return 0;
}