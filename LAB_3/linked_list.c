#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
}node;

struct node* start = NULL;
static int count = 0;

void insert_beginning(int);     
void insert_end(int);           
void delete_beginning();        
void delete_end();            
void display();           


int main(void)
{

    int value;
    printf("\n\n\t\t***WELCOME TO LINKED LIST MANAGEMENT***\n\n");
    for(;;)
    {
        printf("1. Insert at beginning.\n");
        printf("2. Insert at end.\n");
        printf("3. Delete from beginning.\n");
        printf("4. Delete from end.\n");
        printf("5. Print Linked List.\n");
        printf("6. Size of linked list.\n\n");
        printf("ENTER 999 TO END.\n\n");

        int n, flag =0;
        scanf(" %d",&n);
        switch(n)
        {
            case 1:printf("Enter value: ");
                   scanf(" %d",&value);
                   insert_beginning(value);
                   break;
            case 2:printf("Enter value: ");
                   scanf(" %d",&value);
                   insert_end(value);
                   break;
            case 3:delete_beginning();
                   break;
            case 4:delete_end();
                   break;
            case 5:display();
                   break;
            case 6:printf("Size of list-->%d\n\n",count);
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

void delete_end()
{
    if(start == NULL)
    {
        printf("Underflow.\n");
        return;
    }

    struct node* ptr;
    struct node* preptr;
    ptr = start;
    preptr = start;

    while(ptr->link != NULL)
    {
        preptr = ptr;
        ptr = ptr->link;
    }

    preptr->link = NULL;
    free(ptr);
    count--;
    printf("Deleted last node.\n\n");
    
}



void insert_end(int k)
{
    struct node* new = NULL;
    if(start == NULL)
    {
        new = (struct node*)malloc(sizeof(node));
        new->link = NULL;
        new->data = k;
        start = new;
        printf("Linked list created. %d added.\n\n",k);
        return;
    }

    new = (struct node*)malloc(sizeof(node));
    struct node* ptr;
    ptr = start;

    while(ptr->link != NULL)
        ptr = ptr->link;
    
    ptr->link = new;
    new->link = NULL;
    new->data = k;
    count++;
    printf("%d added at the end of linked list.\n\n",k);
}


void delete_beginning()
{
    if(start == NULL)
    {
        printf("Underflow.");
        return;
    }

    struct node* ptr;
    ptr = start;
    start = start->link;
    free(ptr);
    count--;
    printf("Deleted First Node.\n\n");
}



void insert_beginning(int k)
{

    struct node* new = NULL;
    if(start == NULL)
    {
        new = (struct node*)malloc(sizeof(node));
        new->link = NULL;
        new->data = k;
        start = new;
        printf("Linked List Created. %d added.\n\n",k);
        return;
    }
        
    new = (struct node*)malloc(sizeof(node));
    new->data = k;
    new->link = start;
    start = new;
    count++;
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



