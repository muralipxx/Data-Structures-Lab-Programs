#include <stdio.h>
#include <stdlib.h>

void multiply(int a[3][3], int b[3][3], int mult[3][3]);
void print(int arr[3][3]);

int main(void)
{
    int a[3][3] = {{1,2,3} , {1,2,3}, {1,2,3} };
    int b[3][3] = {{1,2,3} , {1,2,3}, {1,2,3} };
    int mult[3][3];

    multiply(a, b ,mult);
    print(mult);

    return 0;
}

void multiply(int a[3][3], int b[3][3], int mult[3][3])
{
    int i,j,k;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            mult[i][j] = 0;
            for(k=0; k<3; k++)
            {
                mult[i][j] += a[i][k]*b[k][j];
            }

        }
    }
}

void print(int arr[3][3])
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
           printf("%d  ",arr[i][j]);

        }
        printf("\n");
    }
}


