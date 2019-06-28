#include <stdio.h>
#include <stdlib.h>
struct s
{
    int id;
    char *str;
};

int main()
{
    struct s s1,s2;
    s1.id = 1;
    s2.id = 2;
    s1.str = (char*)malloc(10*sizeof(char));
    scanf("%s",s1.str);
    s2.str = (char*)malloc(10*sizeof(char));
    scanf("%s",s2.str);
    s2 = s1;
    s1.str[0] = 'X';
    s1.str[4] = 'Y';
    printf("%d %s %d %s\n",s1.id,s1.str,s2.id,s2.str);

    
    return 0;
}