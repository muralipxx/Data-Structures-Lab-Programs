#include <stdio.h>
#include <stdlib.h>

#define m 3
#define n 3

void multiply(int a[m][n], int b[m][n], int mult[m][n]);
void print(int arr[m][n]);
void transpose(int arr[m][n]);
void read_matrix(int a[m][n]);

int main(void)
{
    int a[3][3], b[3][3];
    printf("MATRIX A\n");
    read_matrix(a);
    printf("MATRIX B\n");
    read_matrix(b);
    int mult[3][3];
    printf("MULTIPLICATION:-\n");
    multiply(a, b ,mult);
    print(mult);
    transpose(mult);

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

void multiply(int a[m][n], int b[m][n], int mult[m][n])
{
    int i,j,k;

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            mult[i][j] = 0;
            for(k=0; k<n; k++)
            {
                mult[i][j] += a[i][k]*b[k][j];
            }

        }
    }
}

void print(int arr[m][n])
{
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
           printf("%d  ",arr[i][j]);

        }
        printf("\n");
    }
}

void transpose(int arr[m][n])
{
    int i,j,temp[m][n];
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            temp[j][i] = arr[i][j];
        }
    }
    printf("Transpose is:\n");
    
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", temp[i][j]);
        }
        printf("\n");
    }
}


