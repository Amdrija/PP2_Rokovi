#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int** fun(int n, int m, int cnt);

void main()
{
    int n = 3, m = 2, cnt = 3;
    int **a = fun(n, m, cnt), i, j;
    for(i = 0; i < cnt; i++)
    {
        for(j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        free(a[i]);
    }
    free(a);
}
int** fun(int n, int m, int cnt)
{
    int i, j, temp;
    int** a = (int**)malloc(cnt * sizeof(int*));
    for(i = 0; i < cnt; i++)
    {
        a[i] = malloc(m * sizeof(int));
        if(i == 0)
            for(j = 0; j < m; j++) 
                a[i][j] = j;
        else 
        {
            // red i dobija kopiju reda i-1
            memcpy(a[i],a[i-1],sizeof(int)*m);
            for(j = m -1; j >= 0; j--)
            {
                if (a[i][j] + (m -j) < n) 
                {
                    temp = ++a[i][j];
                    
                    while(j < m) 
                    {
                        printf("%d\n",a[i][j + 1]);
                        a[i][++j]=++temp;
                        break;
                    }
                }
            }
        }
    }
    return a;
}