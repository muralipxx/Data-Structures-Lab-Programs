#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee{
    int id;
    char name[30];
    char address[50];
};

int main(void){

    int n, temp;
    char tn[30], ta[50];
    printf("\nInput no. of employees: ");
    scanf(" %d",&n);

    struct employee array[n];

    printf("Input data:\n\n");
    for(int i=0; i<n; i++){
        printf("Employee ID: ");
        scanf(" %d", &array[i].id);
        printf("Employee Name: ");
        scanf(" %[^\n]", array[i].name);
        printf("Employee Address: ");
        scanf(" %[^\n]", array[i].address);
        printf("\n");
    }

    //sorting employee array 
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n ;j++){

            if (strcmp(array[i].name, array[j].name) > 0){
                //shifting name
                strcpy(tn, array[i].name);
                strcpy(array[i].name, array[j].name);
                strcpy(array[j].name, tn);
                //shifting id
                temp = array[i].id;
                array[i].id = array[j].id;
                array[j].id = temp;
                //shifting address
                strcpy(ta, array[i].address);
                strcpy(array[i].address, array[j].address);
                strcpy(array[j].address, ta);                
            }
        }
    }

    printf("\t***Sorted Order***\n\n");
    //printing employess by name
    for(int i=0; i<n; i++){
        printf("Employee ID: ");
        printf(" %d\n", array[i].id);
        printf("Employee Name: ");
        printf(" %s\n", array[i].name);
        printf("Employee Address: ");
        printf(" %s\n", array[i].address);
        printf("\n");
    }

}
