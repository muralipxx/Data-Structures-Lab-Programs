#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Linked List
struct node{
    struct node* link;
    int data;
};

//Queue
struct Queue{
    struct node *front, *rear;
};

struct node* newNode(int k){
    struct node* temp = (struct node*)malloc(sizeof(struct node));

    if(temp == NULL){
        printf("overflow\n");
        return NULL;
    }

    temp->data = k;
    temp->link = NULL;
    return temp;
}

struct Queue* createQueue(){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct node));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct Queue* queue){
    int value;
    printf("Enter value->");
    scanf(" %d",&value);
    struct node* node = newNode(value);
    
    if(!queue->front){
        queue->front = queue->rear = node;
        return;
    }
    
    queue->rear->link = node;
    queue->rear = node;
}

void dequeue(struct Queue* queue){
    if(queue->front == NULL){
        printf("Queue is empty\n");
        return;
    }

    if(queue->front == queue->rear){
        free(queue->front);
        queue->front = queue->rear = NULL;
    }
    else{
        struct node* temp = queue->front;
        queue->front = queue->front->link;
        free(temp);
    }

}

void display(struct Queue* queue){
    if(queue->front == NULL){
        printf("Queue is empty.\n");
        return;
    }
    struct node* trav = queue->front;
    while(trav->link != NULL){
        printf("%d ",trav->data);
        trav = trav->link;
    }
    printf("%d \n",trav->data);
    printf("Displayed !!\n");
}

int main(void){

    int option;
    struct Queue* queue = NULL;

    printf("\t\tWELCOME TO QUEUE MANAGEMENT\t\t\n\n");
    while(option != 99){

        printf("\n1. Create Queue.\n");
        printf("2. Enqueue.\n");
        printf("3. Dequeue.\n");
        printf("4. Display.\n");
        printf("99. Exit.\n\n");
        
        printf("Option->");
        scanf(" %d",&option);

        switch(option){
            case 1: queue = createQueue();
                    break;
            case 2: enqueue(queue);
                    break;
            case 3: dequeue(queue);
                    break;
            case 4: display(queue);
                    break;
            case 99:printf("Bye!!\n");
                    break;
            default:printf("###Enter a valid input###");
                    break;
        }
        
    }
}



