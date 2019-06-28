#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ulaz = fopen("ulaz.txt","r");
    FILE *izlaz = fopen("izlaz.txt","w");
    if(!ulaz || !izlaz)
    {
        fprintf(stderr,"Greska pri otvaranju fajla.\n");
        exit(1);
    }

    int m,k,n;
    fscanf(ulaz , "%d%d",&m,&k);
    for(int i = 0; i < m; i++)
    {
        fscanf(ulaz,"%d",&n);
        fprintf(stdout, "%d ",fib_n_k(n,k));
    }
}

int fib_n_k(int n,int k)
{
    if(k <= n)
    {
        return 1;
    }
    int *fib = (int*)malloc(k * sizeof(int));
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++)
    {
        fib[i] = 1;
        sum2 += 1;
    }
    for(int i = n; i < k; i++)
    {
        fib[i] = sum2;
        sum2 = sum2 + sum2 - fib[i - n];
    }
    int t = fib[k - 1];
    free(fib);
    return fib[k-1];

}
