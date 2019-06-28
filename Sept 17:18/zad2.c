#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXD 100
int find(char *s)
{
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == '%' && s[i + 1] == 's')
        {
            return i;
        }
        i++;
    }
    return -1;
}

void copy_last(char *s1, char *s2, int pos)
{
    int j = 0;
    for(int i = pos; s2[i] != '\0'; i++)
    {
        s1[j++] = s2[i];
    }
    s1[j] = '\0';
}

char *insertString(char *s1, char *s2)
{
    int pos = find(s1);
    char *posle = (char*)malloc((strlen(s1) - pos - 1) * sizeof(char));
    copy_last(posle,s1,pos + 2);
    s1 = (char*)realloc(s1, (strlen(s2) + strlen(s1) - 1) * sizeof(char));
    s1[pos] = '\0';
    strcat(s1,s2);
    strcat(s1,posle);
    free(posle);
    return s1;
}

int main()
{
    char *s = (char*)malloc((MAXD + 1) * sizeof(char));
    gets(s);
    s = (char*)realloc(s,(strlen(s) + 1) * sizeof(char));
    char *d;
    while(find(s) >= 0)
    {
        d = (char*)malloc((MAXD + 1) * sizeof(char));
        gets(d);
        d = (char*)realloc(d,(strlen(d) + 1) * sizeof(char));
        s = insertString(s, d);
        free(d);
    }

    printf("%s\n",s);
    free(s);
    return 0;
}