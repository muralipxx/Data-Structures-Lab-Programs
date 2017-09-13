#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exp;
    struct node* link;
}node;

struct node* start1 = NULL;
struct node* start2 = NULL;
struct node* start3 = NULL;

//functions
struct node* insert_polynomial(struct node* start);
void display(struct node* start);
int scan();

int main(void){

    printf("Insert first equation:\n");
    start1 = insert_polynomial(start1);
    printf("Insert seconde equation:\n");
    start2 = insert_polynomial(start2);

    display(start1);
    
}


//function to take input
int scan(){
    int x;
    scanf(" %d",&x);

    return x;
}

//function to create ll
struct node* insert_polynomial(struct node* start)
{
    struct node* new = NULL;
    int n;
    while(n != 999){

        if(start == NULL)
        {   
            new = (struct node*)malloc(sizeof(node));
            new->link = NULL;
            printf("Insert exp: ");
            scanf(" %d",&n);
            new->exp = n;
            printf("Insert coeff: ");
            n = scan();
            new->coeff = n;
            start = new;
            printf("LL Created. Value added.\n\n");
        }

        new = (struct node*)malloc(sizeof(node));
        struct node* ptr;
        ptr = start;

        while(ptr->link != NULL)
            ptr = ptr->link;
    
        ptr->link = new;
        new->link = NULL;
        printf("Insert exp: ");
        new->exp = scan();
        printf("Insert coeff: ");
        new->coeff = scan();
        printf("Value added.\n\n");

    }
    return start;
}

//function to display ll
void display(struct node* start){
    if(start == NULL)
    {
        printf("Polynomial not found.\n");
        return;
    }

    struct node* trav;
    trav = start;
    printf("Polynomial is: ");

    while(trav != NULL)
    {
        printf("%dx^%d +  ",trav->coeff, trav->exp);
        trav = trav->link;
    }
  
    printf("\n\n");
}












