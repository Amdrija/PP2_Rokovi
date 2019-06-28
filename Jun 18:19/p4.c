#include <stdio.h>
struct s
{
    char a[30];
};

int main()
{
    char (*a)[30];
    a = (char (*)[30])malloc(sizeof(char[30]));
    printf("%lu %lu\n",a, a + 2);
    printf("%lu %lu\n",sizeof(struct s), sizeof(char*));
}