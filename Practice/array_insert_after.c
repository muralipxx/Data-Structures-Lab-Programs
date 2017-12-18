#include<stdio.h>
#include<stdlib.h>

void insert_after(int array[], int LB, int UP, int value);

int return_index(int array[], int value){

    for(int i=0; i<10; i++)
        if(array[i] == value)
            return i+1;
}
 
void insert_after(int array[],int size, int value, int after){
    int insert_at = return_index(array, after);

    for(int i =size-1 ; i > insert_at; i--)
        array[i] = array[i-1];

    array[insert_at] = value;
}
    
void print_array(int array[]){
    for(int i=0; i<10;i++)
        printf("%d ",array[i]);

    printf("\n");
}

void delete_at_index(int array[],int size, int index){

    for(int i=index; i<size-1; i++)
        array[i] = array[i+1];

    array[size-1] = 0;
    print_array(array);
}


int main(void){
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(array)/sizeof(int);
    print_array(array);
    insert_after(array, size, 69, 3);
    print_array(array);
    delete_at_index(array, size, 3);
}
