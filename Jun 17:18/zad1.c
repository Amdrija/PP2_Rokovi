#include <stdio.h>
#include <stdlib.h>

int **ucitavanje(int *brojFirmi)
{
    scanf("%d",brojFirmi);
    int **firme = (int**)malloc(*brojFirmi*sizeof(int*));
    int n;
    for(int i = 0; i < *brojFirmi; i++)
    {
        scanf("%d",&n);
        firme[i] = (int*)malloc((n + 1) * sizeof(int));
        firme[i][0] = n;
        for(int j = 1; j < n + 1; j++)
        {
            scanf("%d",&firme[i][j]);
        }
    }
    return firme;
}

void brisi(int **a,int n)
{
    for(int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
}

int *obrada(int **firme,int *brojFirmi)
{
    int *poslovanje = (int*)malloc(*brojFirmi * sizeof(int));
    int profit;
    for(int i = 0; i < *brojFirmi; i++)
    {
        profit = 0;
        for(int j = 1; j < firme[i][0] + 1;j++)
        {
            profit += firme[i][j];
        }
        if(profit > 0)
            poslovanje[i] = 1;
        else
            poslovanje[i] = 0;
        
    }
    return poslovanje;
}

void pisi(int *a, int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main()
{
    int br_firmi;
    int **firme = ucitavanje(&br_firmi);
    int *poslovanje = obrada(firme,&br_firmi);
    pisi(poslovanje,br_firmi);
    free(poslovanje);
    brisi(firme,br_firmi);
    return 0;
}