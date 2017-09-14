#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
    struct node* prev;
}node;

struct node* start1 = NULL;
struct node* start2 = NULL;
static int count = 0;

struct node* insert_beginning(struct node* start ,int);     
void insert_after(int, int);        
void delete_end();            
void display(struct node* start);           
void concat(struct node*, struct node*);

int main(void)
{

    int value,data,n;
    printf("\n\n\t\t***WELCOME TO DOUBLY LINKED LIST MANAGEMENT***\n\n");
     
    while(n != 5){
        printf("1. Insert start1.\n");
        printf("2. Insert start2.\n");
        printf("3. Concatenate.\n");
        printf("4. Display.\n");
        printf("5. Exit.\n\n");

        printf("Input>");
        scanf(" %d",&n);
        switch(n){
            case 1:printf("Enter value: ");
                   scanf(" %d",&value);
                   start1 = insert_beginning(start1, value);
                   break;
            case 2:printf("Enter value: ");
                   scanf(" %d",&value);
                   start2 = insert_beginning(start2, value);
                   break;
            case 3:concat(start1, start2);
                   break;
            case 4:printf("Display 1 or 2 ? ");
                   scanf(" %d",&value);
                   if(value == 1)
                       display(start1);
                   else if(value == 2)
                       display(start2);
                   else
                       printf("Dude ?\n");
                   break;
            case 5:printf("Bye!\n\n");
                   break;
            default:printf("Why bro ?\n\n");
        }
    }
    
}

void concat(struct node* s1, struct node* s2){

    struct node* ptr = NULL;
    ptr = s1;
    while(ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = s2;
    s2->prev = ptr;
   
    printf("Concatenated.\n\n");
}
    
/*
void insert_after(int value, int data){

    if(start == NULL){
        printf("Linked List not found.\n");
        return;
    }
    
    struct node* new = NULL;
    new = (struct node*)malloc(sizeof(node));
    new->data = data;
    struct node* ptr = start;
    while(ptr->data != value){
        ptr = ptr->link;
    }

    new->link = ptr->link;
    new->prev = ptr;
    ptr->link = new;
    new->link->prev = new;
    printf("%d added after %d.\n\n", data,value);
    ++count;
    
}

void delete_end()
{
    if(start == NULL)
    {
        printf("Underflow.\n");
        return;
    }

    struct node* ptr;
    ptr = start;

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->prev->link = NULL;
    free(ptr);
    --count;
    printf("Deleted last node.\n\n");
    
}

*/
struct node* insert_beginning(struct node* start,int k)
{
    struct node* new = NULL;
    if(start == NULL)
    {
        new = (struct node*)malloc(sizeof(node));
        new->link = NULL;
        new->prev = NULL;
        new->data = k;
        start = new;
        printf("Linked List Created. %d added.\n\n",k);
        ++count;
        return start;
    }    
          
    new = (struct node*)malloc(sizeof(node));
    
    new->data = k;
    new->link = start;
    new->prev = NULL;
    start->prev = new;
    start = new;
    

    ++count;
    printf("Added %d at beginning.\n\n",k);

    return start;
}



void display(struct node* start)
{
    if(start == NULL)
    {
        printf("Linked List does not exit.\n");
        return;
    }

    struct node* trav;
    trav = start;
    printf("Linked List is: ");

    while(trav->link != NULL)
    {
        printf("%d ",trav->data);
        trav = trav->link;
    }
    printf("%d ",trav->data);
  
    printf("\n\n");
}


