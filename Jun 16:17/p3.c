#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
char *x;
void f(char *a, char *b, int c) 
{   
    if (a < b && c>0) 
        f(a++, b--, c - 1);
   *a = *a < *b ? *a : ++*b; 
   printf("%s\n",x);
} 
int main(int argc, char *argv[]) 
{   
    int c = atoi(argv[argc - 1]);   
    char *p = argv[atoi(argv[3]) + 1],*q = p + strlen(p) - 1;  
    x = p;

    f(p, q, c);   
    printf("%s", p);
    return 0;
}