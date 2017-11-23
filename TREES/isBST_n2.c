#include<stdio.h>




struct Node{
    int data;
    Node* left;
    Node* right;
}

int IsSubtreeLesser(Node* root, int value){

    if(root == NULL)
        return 1;
    if(root->data <= value
            && IsSubtreeLesser(root->left, value)
            && IsSubtreeLesser(root->right, value))
        return 1;
    else
        return 0;
}

int IsSubtreeGreater(Node* root, int value){

    if(root == NULL)
        return 1;
    if(root->data > value
            && IsSubtreeGreater(root->left, value)
            && IsSubtreeGreater(root->right, value))
        return 1;
    else
        return 0;
}



int IsBinarySearchTree(Node* root){

    if(root == NULL)
        return 1;

    if(IsSubtreeLesser(root->left, root->data)
            && IsSubtreeGreater(root->right, root->data)
            && IsBinartSearchTree(root->left)
            && IsBinarySearchTree(root->right))
        return 1;
    else
        return 0;
}


int main(void){



}
