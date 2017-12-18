/* C/C++ program to merge two sorted linked lists in reverse order */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
 
/* Link list node */
struct Node
{
    int data;
    struct Node* next;
};
 
 
/* Function to insert a node at the beginging of the
   linked list */
void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    
    printf("\n");
}

/*    #### FUNCTIONS USED IN DS ANSWER SHEET - NITANSHU ####     */

/*Utility Function to Reverse a Singly Linked List*/
struct Node* reverse(struct Node* head){

    struct Node* preptr = NULL;
    struct Node* ptr = head;
    struct Node* postptr;

    while(ptr != NULL){
        postptr = ptr->next;
        ptr->next = preptr;
        preptr = ptr;
        ptr = postptr;
    }

    return preptr;
}

/* Utility Function for MergeAndReverse */
struct Node* SortedMergeUtil(struct Node* a, struct Node* b) 
{
  struct Node* result = NULL;
 
  /* Base cases */
  if (a == NULL) 
     return(b);
  else if (b==NULL) 
     return(a);
 
  /* Pick either a or b, and recur */
  if (a->data <= b->data) 
  {
     result = a;
     result->next = SortedMergeUtil(a->next, b);
  }
  else
  {
     result = b;
     result->next = SortedMergeUtil(a, b->next);
  }
  return(result);
}

/*Main function to Merge 2 sorted linked lists in reverse order */
struct Node* MergeAndReverse(struct Node* a, struct Node* b)
{
	struct Node* temp = SortedMergeUtil(a, b);
	struct Node* result = reverse(temp);
	
	return result;
}
	
 
/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node* s1 = NULL;
    struct Node* s2 = NULL;

   /* Resultant list will be pointed by pointer s3 */
    struct Node* s3 = NULL;
 
    /* Let us create two sorted linked lists to test
      the functions
       Created lists, s1: 12->34->48->56,  s2: 2->3->14->23->57 */
    
    push(&s1, 56);
    push(&s1, 48);
    push(&s1, 34);
    push(&s1, 12);

    printf("s1 is: ");
    printList(s1);

    push(&s2, 57);
    push(&s2, 23);
    push(&s2, 14);
    push(&s2, 3);
    push(&s2, 2);

    printf("s2 is: ");
    printList(s2);
 
    /* Merge And Reverse the linked list */
    s3 = MergeAndReverse(s1, s2);
 
    printf("\nLinked List Merged in Reverse Order \n");
    printf("s3 is: ");
    printList(s3);
 
    return 0;
}
