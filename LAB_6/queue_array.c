#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//Queue
struct Queue{
    int front;
    int* array;
    int rear;
    int capacity;
};

struct Queue* createQueue(){

    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));

    if(!queue){
        printf("Overflow.\n");
        return NULL;
    }
    printf("Enter capacity of queue: ");
    scanf(" %d",&queue->capacity);

    queue->front = -1;
    queue->rear = -1;

    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    
    if(!queue->array){
        printf("Overflow.\n");
        return NULL;
    }

    return queue;
}

void enqueue(struct Queue* queue, int value){
    
    if(queue->rear == queue->capacity-1){
        printf("Overflow\n");
        return;
    }

    if(queue->front == -1 && queue->rear == -1){
        queue->front = queue->rear = 0;
        queue->array[queue->rear] = value;
        return;
    }

    queue->rear++;
    queue->array[queue->rear] = value;
    
}

void dequeue(struct Queue* queue){

    if(queue->front == -1){
        printf("Underflow\n");
        return;
    }

    if(queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->rear--;

}

void display(struct Queue* queue){

    if(queue->rear == -1){
        printf("Queue is empty.\n");
        return;
    }

    for(int i=queue->front; i<=queue->rear; i++)
        printf("%d ",queue->array[i]);

    printf("\nDone!!\n");
    }


int main(void){

    int option,value;
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
            case 2: printf("Input value: ");
                    scanf(" %d",&value);
                    enqueue(queue,value);
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



