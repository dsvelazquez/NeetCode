#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t{
    int value;
    struct Node_t *next;
}Node_t;

Node_t *insertHead(Node_t **head, int val) // Double pointer stores the memory address of the single pointer
{
    // Allocate Memory for Node
    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));

    // check if list is empty
    if(*head == NULL)
    {
        newNode->next = NULL;
    }
    else
    {
        newNode->next = *head;
    }
    newNode->value = val;
    *head = newNode;
    return newNode;
}
Node_t *insertTail(Node_t **head, int val) // Double pointer stores the memory address of the single pointer
{
    // Allocate memory for node
    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));

    // Check if list is empty
    if(*head == NULL)
    {
        *head = newNode;
    }
    else // traverse to the last node that contains next = null
    {
        Node_t *curr = *head;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    newNode->next = NULL;
    newNode->value = val;
    return newNode;
}
void removeNode(Node_t **head, int val) // USE TWO POINTERS WHEN REMOVING THE NODE TO KEEP TRACK OF CURRENT AND PREVIOUS
{
    Node_t *curr = *head;
    Node_t *prev = NULL;
    while((curr->value != val) && (curr != NULL))
    {
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL)
        return; // Nothing
    
    // Found NODE
    if(prev == NULL){
        // Node to remvoe is the head
        *head = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }

    // free the memory of the removed node
    free(curr);
}
void printList(Node_t **head)
{
    Node_t *curr = *head;
    while(curr != NULL)
    {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
}
int main()
{
    Node_t *head = NULL;

    insertHead(&head, 10);
    insertHead(&head,2);
    insertTail(&head, 50);
    insertTail(&head, 30);
    insertTail(&head, 40);
    insertHead(&head,5);
    insertTail(&head, 1);
    removeNode(&head, 5);

    printList(&head);


    return 0;
}