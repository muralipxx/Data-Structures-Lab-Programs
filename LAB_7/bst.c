#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* root = NULL;
struct Node* trav = NULL;

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

void createTree(struct Node* trav, int value){

    struct Node* node = newNode(value);
    if(!root){
        root = node;
        return;
    }

    if(trav->left == NULL && trav->data > value)
        trav->left = node;
    else if(trav->right == NULL && trav->data < value)
        trav->right = node;
    else
    {
        if(trav->data < value)
            createTree(trav->right, value);
        else
            createTree(trav->left, value);
    }
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
                    createTree(root, value);
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

        
    


        
    


