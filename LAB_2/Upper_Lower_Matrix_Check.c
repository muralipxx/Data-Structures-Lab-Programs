#include <stdio.h>
#include <stdlib.h>

#define m 3
#define n 3

void upper(int a[m][n]);
void lower(int a[m][n]);
void read_matrix(int a[m][n]);

int main(void)
{
    int a[3][3], b[3][3];
    printf("MATRIX A\n");
    read_matrix(a);
    upper(a);
    read_matrix(a);
    lower(a);
    return 0;
}

void read_matrix(int a[m][n])
{
    printf("Input values:\n");
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Done\n");
}

void upper(int a[m][n])
{
    int i, j, isUpper=1;
    
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        {
            if(j<i && a[i][j] != 0)
                isUpper = 0;
        }

    if(isUpper == 1)
        printf("Matrix is upper matrix.\n");
    else
        printf("Matrix is not upper matrix.\n");
}

void lower(int a[m][n])
{
    int i, j, isLower=1;
    
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
        {
            if(j>i && a[i][j] !=0)
                isLower = 0;
        }

    if(isLower == 0)
        printf("Matrix is lower matrix.\n");
    else
        printf("Matrix is not lower matrix.\n");
}
  





























