#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* root = NULL;

struct Node* newNode(int value){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node*));

    if(!node){
        printf("Overflow.\n");
        return NULL;
    }
    node->data = value;
    node->left = node->right = NULL;

    return node;
}

struct Node* insert(struct Node* root, int data){

    struct Node* node = newNode(data);
    if(!root){
        root = node;
    }
    else if(data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;
}

void search(struct Node* root, int data){
    if(root == NULL)
        printf("NOT FOUND.\n");
    else if(root->data == data)
        printf("FOUND.\n");
    else if(data <= root->data)
        search(root->left , data);
    else
        search(root->right, data);
}

int input(){
    int value;
    printf("Enter Value:");
    scanf(" %d", &value);
    
    return value;
}

void Preorder(struct Node* root){
    if(root == NULL)
        return;
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(struct Node* root){
    if(root == NULL)
        return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}

void Postorder(struct Node* root){
    if(root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ",root->data);
}

int main(void){
       
    int option, value;
    while(option != 99){
        printf("1. Insert.\n");
        printf("2. Preorder.\n");
        printf("3. Inorder.\n");
        printf("4. Postorder.\n");
        printf("99. Exit\n\n");
        printf("OPTION->");
        scanf(" %d", &option);
        switch(option){
            case 1: value = input();
                    root = insert(root, value);
                    break;
            case 2: Preorder(root);
                    printf("\n");
                    break;
            case 3: Inorder(root);
                    printf("\n");
                    break;
            case 4: Postorder(root);
                    printf("\n");
                    break;

        }
    }
}

        
    


        
    


