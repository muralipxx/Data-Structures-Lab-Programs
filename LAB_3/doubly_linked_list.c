#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
    struct node* prev;
}node;

struct node* start = NULL;
static int count = 0;

void insert_beginning(int);     
void insert_after(int, int);        
void delete_end();            
void display();           


int main(void)
{

    int value,data;
    printf("\n\n\t\t***WELCOME TO DOUBLY LINKED LIST MANAGEMENT***\n\n");
    for(;;)
    {
        printf("1. Insert at beginning.\n");
        printf("2. Insert after a node.\n");
        printf("3. Delete from end.\n");
        printf("4. Print Linked List.\n");
        printf("5. Size of linked list.\n\n");
        printf("ENTER 999 TO END.\n\n");

        int n, flag =0;
        printf("Input>");
        scanf(" %d",&n);
        switch(n)
        {
            case 1:printf("Enter value: ");
                   scanf(" %d",&value);
                   insert_beginning(value);
                   break;
            case 2:printf("Value: ");
                   scanf(" %d",&value);
                   printf("Data: ");
                   scanf(" %d",&data);
                   insert_after(value,data);
                   break;           
            case 3:delete_end();
                   break;
            case 4:display();
                   break;
            case 5:printf("Size of list-->%d\n\n",count);
                   break;
            case 999:flag = 1;
                   break;
            default:printf("Enter a valid input.\n\n");
                    break;
            
        }
        if(flag == 1)
            break;
    }


}

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


void insert_beginning(int k)
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
        return;
    }    
          
    new = (struct node*)malloc(sizeof(node));
    
    new->data = k;
    new->link = start;
    new->prev = NULL;
    start->prev = new;
    start = new;
  

    ++count;
    printf("Added %d at beginning.\n\n",k);
}


void display()
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


