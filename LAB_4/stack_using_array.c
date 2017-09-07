#include<stdio.h>
#include<stdlib.h>

//global variables
int stack[500];
static int size = 0;
static int start =0;
static int top = -1;

//functions
void push(int);
void pop();
void display();

//main function
int main(void){

    printf("\n\n\t\t***WELCOME TO STACK MANAGEMENT***\n\n");

    int n,value;
    while(n != 4){

        printf("1. Push.\n");
        printf("2. Pop.\n");
        printf("3. Print Stack.\n");
        printf("4. Exit.\n\n");

        printf("Input->");
        scanf(" %d",&n);
        switch(n){
            case 1:printf("Enter value: ");
                   scanf(" %d",&value);
                   push(value);
                   break;
            case 2:pop();
                   break;
            case 3:display();
                   break;
            case 4:printf("Exiting....\n\n");
                   break;
            default:printf("Not a valid input.\n\n");
        }
    }
}

//functions

void push(int value){
    
    stack[top+1] = value;
    top++;
    size++;
    printf("Pushed %d to top\n\n",value);

}

void pop(){

    if(top == -1){
        printf("No elements to pop.\n\n");
        return;
    }

    top--;
    size--;
    printf("Popped!\n\n");
}

void display(){
    if(top == -1){
        printf("Stack is empty.\n\n");
        return;
    }

    printf("Stack is:- ");
    for(int i=start; i<=top; i++){
        printf("%d ",stack[i]);
    }
    printf("\n\n");

}






















