#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int size);

int main(void)
{
    int array[50];
    int i,size;
    printf("Input size of array: ");
    scanf(" %d",&size);
    printf("Input elements: ");
    for(i=0; i<size; i++)
    {
        scanf(" %d",&array[i]);
    }
    printf("Done !!\n");
    printf("Array is: ");
    for(i=0; i<size; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
    sort(array, size);
    printf("Sorted Array is: ");
    for(i=0; i<size; i++)
    {
        printf("%d ",array[i]);
    }
}

void sort(int arr[], int size)
{
    int n=size;
    int i,j,loc,min,index=0;
    int temp;
    for(i=0; i<n-1; i++)
    {
        min = arr[i];
        for(j=i+1; j<n; j++)
        {

            if(min > arr[j])
            {
                loc = j;
                min = arr[j];
            }
        }
        if(arr[i] > min)
        {
        temp = arr[loc];
        arr[loc] = arr[i];
        arr[i] = temp;
        }

    }
}
