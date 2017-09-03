#include<stdio.h>
#include<stdlib.h>

int main(void){

    //change arrays as per your need but it should be sorted
    int a[] = {1,2,3,7,8};
    int b[] = {0,3,5,6,9,10,11,12};

    int m =sizeof(a) / sizeof(int);
    int n =sizeof(b) / sizeof(int);
    
    int index=0, j=0, k=0;
    int size = m + n;
    int array[size];
 
    
    while(index < size) {

        while(a[j] < b[k] && j<m ){
            array[index] = a[j];
            ++index;
            ++j;
        }
        while(a[j] > b[k] && k<n){
            array[index] = b[k];
            ++index;
            ++k;            
        }
        while(a[j] == b[k]){
            array[index] = a[j];
            j++; index++;            
        }        
    }
   
    printf("Merged array: ");
    for(int i=0; i<size; i++)
        printf("%d ", array[i]);

    printf("\n");

}
