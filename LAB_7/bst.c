#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* search(struct Node* root, int x);
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

struct Node* minValueNode(struct Node* root){
    struct Node* trav = root;

    while(trav->left != NULL)
        trav = trav->left;

    return trav;
}

struct Node* deleteNode(struct Node* root, int data){
    if(!root)
        return root;

    if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, data);

    }

    return root;

}

void smallerThanX(struct Node* root, int x){
    


}


struct Node* search(struct Node* root, int data){
    if(root == NULL)
        return NULL;
    else if(root->data == data)
        return root;
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
    //return root->data;
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
        printf("2. Delete.\n");
        printf("3. Preorder.\n");
        printf("4. Inorder.\n");
        printf("5. Postorder.\n");
        printf("6. Smaller Than.\n");
        printf("99. Exit\n\n");
        printf("OPTION->");
        scanf(" %d", &option);
        switch(option){
            case 1: value = input();
                    root = insert(root, value);
                    break;
            case 2: value = input();

                    break;
            case 3: Preorder(root);
                    printf("\n");
                    break;
            case 4: Inorder(root);
                    printf("\n");
                    break;
            case 5: Postorder(root);
                    printf("\n");
                    break;
            case 6: value = input();
                    smallerThanX(root, value);
                    break;
                    
        }
    }
}
      
    


