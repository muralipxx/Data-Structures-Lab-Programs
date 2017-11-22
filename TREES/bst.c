#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    struct BstNode* left;
    struct BstNode* right;
    int data;
};

struct BstNode* root = NULL;

void insert(int value){
    struct BstNode* newNode = (struct BstNode*)malloc(sizeof(struct BstNode));

    newNode->data = value;

    if(root == NULL){
        root = newNode;
    }
    else{
        struct BstNode* focusNode = root;

        struct BstNode* parent;

        while(1){

            parent = focusNode;

            if(value < focusNode->data){
                focusNode = focusNode->left;

                if(focusNode == NULL){
                    parent->left = newNode;
                    return;
                }
                
            }else{
                focusNode = focusNode->right;

                if(focusNode == NULL){
                    parent->right = newNode;
                    return;
                }
            }
        }
    }
}

void inOrder(struct BstNode* focusNode){
    if(focusNode != NULL){
        inOrder(focusNode->left);
        printf("%d ", focusNode->data);
        inOrder(focusNode->right);
    }
}

struct BstNode* search(int value){
    
    struct BstNode* focusNode = root;
    struct BstNode* parent;
    while(focusNode->data != value){
        if(value < focusNode->data)
            focusNode = focusNode->left;
        else
            focusNode = focusNode->right;

        if(focusNode == NULL)
            return NULL;
    }
}

/*
int remove(int value){
    struct BstNode* focusNode = root;
    struct BstNode* parent = root;
    int isLeft = 1;

    while(focusNode->data != value){
        parent = focusNode;
        if(value < focusNode->data){
            isLeft = 1;
            focusNode = focusNode->left;
        }else{
            isLeft = 0;
            focusNode = focusNode->right;
        }

        if(focusNode == NULL)
            return 0;
    }

    if(focusNode->left == NULL && focusNode->right == NULL){
        if(focusNode == root)
            root == NULL;
        else if(isLeft)
            parent->right = null;
    }

}
*/

//Iterative approach to find largest no.
int largest(struct BstNode* focusNode){

    while(focusNode->right != NULL)
        focusNode = focusNode->right;
   
    return focusNode->data;
}

//Iterative approach to find smallest no.
int smallest(struct BstNode* focusNode){

    while(focusNode->left != NULL)
        focusNode = focusNode->left;

    return focusNode->data;
}

//Recursive approach to find min
int findMin(struct BstNode* focusNode){
    if(focusNode->left == NULL)
        return focusNode->data;
    else
        findMin(focusNode->left);
}

//Recursive approach to find max
int findMax(struct BstNode* focusNode){
    if(focusNode->right == NULL)
        return focusNode->data;
    else
        findMax(focusNode->right);
}

//Utility function for find height of a bst
int max(int a, int b){
    if(a > b)
        return a;
    else if(a < b)
        return b;
    else 
        return a;
}

int findHeight(struct BstNode* focusNode){

    if(focusNode == NULL)
        return -1;

    int leftHeight = findHeight(focusNode->left);
    int rightHeight = findHeight(focusNode->right);

    return max(leftHeight, rightHeight) + 1;
}

//Utility functions for level order traversal

struct Queue{
    int front;
    int rear;
    struct BstNode* array[100];
};

struct Queue* queue = NULL;

struct Queue* createQueue(){

    queue = (struct Queue*)malloc(sizeof(struct Queue));

    if(!queue){
        printf("Overflow.\n");
        return NULL;
    }

    queue->front = -1;
    queue->rear = -1;
    
    if(!queue->array){
        printf("Overflow.\n");
        return NULL;
    }

    return queue;
}

void enqueue(struct BstNode* bstNode){
    
    createQueue();

    if(queue->front == queue->rear + 1){
        printf("Overflow\n");
        return;
    }

    if(queue->front == -1 && queue->rear == -1){
        queue->front = queue->rear = 0;
        queue->array[queue->front] = bstNode;
    }
    else{
     queue->rear = (queue->rear + 1)%100;
     queue->array[queue->rear] = bstNode;
    }

}

struct BstNode* dequeue(){
    if(queue->front == -1){
        printf("Underflow\n");
        return NULL;
    }

    if(queue->front == queue->rear){
        queue->front = queue->rear = -1;
    }
    else
        queue->front = (queue->front + 1) % 100;
    return queue->array[queue->front+1];
}
    
void levelOrder(struct BstNode* root){
    enqueue(root);
    
    while(queue->front != -1){
        struct BstNode* current = dequeue();
        printf("%d ",current->data);
        if(current->left != NULL)
            enqueue(current->left);
        if(current->right != NULL)
            enqueue(current->right);
    }
}

//Recursive Approach
struct BstNode* searchRecursive(struct BstNode* root, int value){
    if(root->data == value)
        return root;
    else if (value < root->data)
        searchRecursive(root->left, value);
    else
        searchRecursive(root->right, value);
}

int lessThanN(struct BstNode* root, int N){
    if(root->left == NULL && root->right == NULL && root->data > N)
        return -1;

    if((root->data <= N && root->right == NULL) || (root->data <= N && root->right->data > N))
        return root->data;

    if(root->data >= N)
        return lessThanN(root->left, N);
    else
        return lessThanN(root->right, N);
}
    

int main(void){


    insert(20);
    insert(10);
    insert(30);
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    inOrder(root);
    printf("\n");
    if(search(10))
        printf("Found.\n");
    else
        printf("Not Found.\n");
    
    printf("Largest No is: %d\n",largest(root));
    printf("Smallest No is: %d\n",findMin(root));
    printf("Height of the tree is: %d\n", findHeight(root));
    //levelOrder(root);
    printf("Less than 26: %d", lessThanN(root, 29));
    printf("\n");
}










        
        
