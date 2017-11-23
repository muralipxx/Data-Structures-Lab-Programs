#include<stdio.h>



int IsBstUtil(Node* root, int minValue, int maxValue){

    if(root == NULL)
        return 1;

    if(root->data > minValue && root->data < maxValue
            && IsBstUtil(root->left, minValue, root->data)
            && IsBstUtil(root->right, root->data, maxValue))
        return 1;
    else
        return 0;
}

int IsBinarySearchTree(Node* root){
    return IsBstUtil(root, INT_MIN, INT_MAX);

}
