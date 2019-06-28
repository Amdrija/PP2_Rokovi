#include <stdio.h>
void radi(char *s) 
{
    if (!*s) return;
    if (*s >= '0' && *s <= '9') radi(++s);
    else 
    {
        *s += (*s >= 'a' && *s <= 'z') ? 'A' -'a' : 'a' -'A';
        radi(s+=2);
    }
}
void main(int argc, char *argv[]) 
{
    int i;
    for (i = 1; i < argc; i++) 
    {
        radi(argv[i]); 
        puts(argv[i]);
    }
}