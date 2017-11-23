// c++ program swap nodes
#include<bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// function to create a new tree node
Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
// swap two Node
void Swap( Node **a , Node **b)
{
    Node * temp = *a;
    *a = *b;
    *b = temp;
}
 
// A utility function swap left- node & right node of tree
// of every k'th level
void swapEveryKLevelUtil( Node *root, int level, int k)
{
    // base case
    if (root== NULL ||
            (root->left==NULL && root->right==NULL) )
        return ;
 
    //if current level + 1  is present in swap vector
    //then we swap left & right node
    if ( (level + 1) % k == 0)
        Swap(&root->left, &root->right);
 
    // Recur for left and right subtrees
    swapEveryKLevelUtil(root->left, level+1, k);
    swapEveryKLevelUtil(root->right, level+1, k);
}
 
// This function mainly calls recursive function
// swapEveryKLevelUtil()
void swapEveryKLevel(Node *root, int k)
{
    // call swapEveryKLevelUtil function with
    // initial level as 1.
    swapEveryKLevelUtil(root, 1, k);
}
 
// Utility method for inorder tree traversal
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
// Driver Code
int main()
{
    /*    1
        /   \
       2     3
     /      /  \
    4      7    8   */
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->right = newNode(8);
    root->right->left = newNode(7);
 
    int k = 2;
    cout << "Before swap node :"<<endl;
    inorder(root);
 
    swapEveryKLevel(root, k);
 
    cout << "\nAfter swap Node :" << endl;
    inorder(root);
    return 0;
}
