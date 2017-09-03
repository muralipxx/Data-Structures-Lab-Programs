#include<stdio.h>
#include<stdlib.h>

int main(void){

    int a[] = {1,3,5,7,9};
    int b[] = {0,2,4,6,8,10,11,12};

    int m =sizeof(a) / sizeof(int);
    int n =sizeof(b) / sizeof(int);
    
    int j=0, k=0;
    int size = m + n;
    int array[size];
 
    
    for(int i=0; i<size; i++){

        if( a[j] < b[k]){
            array[i] = a[j];
            j++;
        }
        else if(b[k] < a[j]){
            array[i] = b[k];
            k++;
        }
        else{
            array[i] = a[j];
            j++;
        }

    }

    printf("Final array: ");
    for(int i=0; i<size; i++)
        printf("%d ", array[i]);

    printf("\n");
}
