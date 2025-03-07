#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node_t;

Node_t *insertFront(Node_t **head, Node_t **tail, int val)
{
    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));

    // Check memory allocation failure
    if(newNode == NULL)
        return NULL;

    // Check if list is empty
    if(*head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        (*tail) = newNode;
    }
    else
    {
        newNode->next = *head;
        newNode->prev = NULL;
        (*head)->prev = newNode;
    }
    newNode->data = val;
    (*head) = newNode;

    return newNode;
}
Node_t *insertBack(Node_t **head, Node_t **tail, int val)
{
    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));

    // Handle memory allocation failure
    if(newNode == NULL)
        return NULL;

    //Check if list is empty
    if(*head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        (*head) = newNode;
    }
    else
    {
        newNode->prev = *tail;
        newNode->next = NULL;
        (*tail)->next = newNode;
    }
    newNode->data= val;
    *tail = newNode;

    return newNode;
}
Node_t *deleteIth(Node_t **head, int index)
{
   
}
void printList(Node_t **head)
{
    Node_t *current = *head;

    while(current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }

}

int main()
{
    Node_t *head = NULL, *tail = NULL;

    head = insertFront(&head, &tail, 10);
    insertBack(&head, &tail, 12);
    insertBack(&head, &tail, 22);
    deleteIth(&head, 2);
    insertBack(&head,&tail, 222);
    //insertFront(&head, &tail, 5);
    printList(&head);

}