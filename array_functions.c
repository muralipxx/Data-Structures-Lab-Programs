#include <stdio.h>
#include <stdlib.h>

//global variables
static int size;

//functions
void print_array(int array[]);
void create_array(int array[]);
void insert_at(int index, int value, int array[]);
void delete_from(int index, int array[]);
void linear_search(int value, int array[]);

int main(void)
{
    int array[100];
    create_array(array);
    print_array(array);
    int index=2, value =69;
    insert_at(index, value, array);
    print_array(array);
    delete_from(index, array);
    print_array(array);
    value = 5;
    linear_search(value, array);
}

void print_array(int array[])
{
    int i=0;
    printf("The array is:\n");
    for(i=0; i<size; i++)
        printf("%d ",array[i]);
    printf("\n");
}

void create_array(int array[])
{
    int i=0;
    printf("Input size of array: ");
    scanf(" %d",&size);
    for(i=0; i<size; i++)
        scanf(" %d",&array[i]);
}

void insert_at(int index, int value, int array[])
{
    int i=0,temp;
    size++;
    for(int i=size-2; i>=index; i--)
        array[i+1] = array[i];
    array[index] = value;
    printf("INSERTED !!\n");
}

void delete_from(int index, int array[])
{
    int i;
    for(int i=index; i<size; i++)
    {
        array[i] = array[i+1];
    }
    size--;
    printf("DELETED !!\n");
}
  
void linear_search(int value, int array[])
{
    int i,n,flag=0;
    for(i=0,n=size; i<n; i++)
    {
        if(array[i] == value)
        {
            printf("FOUND %d AT INDEX: %d\n",value,i);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("NOT FOUND !\n");
}

    









