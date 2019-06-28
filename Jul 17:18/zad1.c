#include <stdio.h>
#include <stdlib.h>


void pisi(int **mx,int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d ",mx[i][j]);
        }
        printf("\n");
    }
}

int **readMatrix(int *numrows, int *numcols)
{
    scanf("%d%d",numrows,numcols);

    int **matrix = (int**)malloc(*numrows * sizeof(int*));
    for(int i = 0; i < *numrows; i++)
    {
        matrix[i] = (int*)malloc(*numcols * sizeof(int));
        for(int j = 0; j < *numcols; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    return matrix;
}

void brisi(int **matrix, int n, int m)
{
    for(int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

int **rotateMatrix90(int **matrix, int numrows, int numcols)
{
    int **rotated = (int**)malloc(numcols * sizeof(int*));
    for(int i = 0; i < numcols; i++)
    {
        rotated[i] = (int*)malloc(numrows * sizeof(int));
        for(int j = 0; j < numrows; j++)
        {
            rotated[i][j] = matrix[numrows - 1 - j][i];
        }

    }
    return rotated;
}


int main()
{
    int **mx,**rx,n,m;
    mx = readMatrix(&n,&m);
    rx = rotateMatrix90(mx,n,m);
    pisi(mx,n,m);
    pisi(rx,m,n);
    brisi(mx,n,m);
    brisi(rx,m,n);
    return 0;
}
