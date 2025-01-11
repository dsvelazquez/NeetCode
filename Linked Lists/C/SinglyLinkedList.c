#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
Design Singly Linked List
Design a Singly Linked List class.

Your LinkedList should support the following operations:

int get(int i) will return the value of the ith node (0-indexed). If the index is out of bounds, return -1.
void insertHead(int val) will insert a node with val at the head of the list.
void insertTail(int val) will insert a node with val at the tail of the list.
bool existElement(Node_t **) returns true if element is in the list else returns false
bool remove(int i) will remove the ith node (0-indexed). If the index is out of bounds, return false, otherwise return true.
int[] getValues() return an array of all the values in the linked list, ordered from head to tail.
int countNumberNodes() return the number of nodes in a linked list
*/

typedef struct node{
    int data;
    struct node *next;
}Node_t;

Node_t *insertHead(Node_t **head, int val)
{
    Node_t *newNode = malloc(sizeof(Node_t));
    
    if(*head == NULL) // If empty list
    {
        newNode->next = NULL;
    }
    else{
        newNode->next = *head;
    }
    newNode->data = val;
    *head = newNode;
    return newNode;
}

Node_t *insertTail(Node_t **head, int val)
{
    Node_t *newNode = malloc(sizeof(Node_t));

    if(*head == NULL)//Check if list is empty
    {
        *head = newNode;
    }
    else{
        Node_t *curr = *head;
        while(curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    newNode->next = NULL;
    newNode->data = val;
    return newNode;
}
bool existElement(Node_t **head, int element)
{
    Node_t *curr = *head;
    while(curr != NULL)
    {
        if(curr->data == element)
        {
            return true;
        }
        else{
            curr = curr->next;
        }
    }
    return false;
}
int getIthNode(Node_t **head, int ith)
{
    Node_t *curr = *head;
    int count = 0;
    while(curr !=NULL)
    {
        if(count == ith)
            return curr->data;
        else
            curr = curr->next;
        count++;   
    }
    return -1;
}
int getHead(Node_t **head)
{
    return (*head)->data;
}
int getTail(Node_t **head)
{
    Node_t *curr = *head;
    while(curr->next != NULL)
    {
        curr= curr->next;
    }
    return curr->data;
}
int *getValues(Node_t **head)
{
}
void printList(Node_t **head)
{
    Node_t *curr = *head;
    while(curr != NULL)
    {
        printf("%d-> ", curr->data);
        curr = curr->next;
    }
}
int countNumberNodes(Node_t **head)
{
    Node_t *curr = *head;
    int count = 0;
    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}
int main()
{
    Node_t *head = NULL;

    head = insertHead(&head, 20);
    insertTail(&head, 10);
    insertTail(&head, 15);
    insertTail(&head, 1);
    head = insertHead(&head, 30);
    insertTail(&head, 5);
    insertTail(&head, 9);
    insertTail(&head, 21);
    printList(&head);
    printf("\r\n");

    if(existElement(&head, 1000))
        printf("element exists\r\n");
    else
        printf("element doesn't exist\r\n");

    printf("ith Node: %d\r\n", getIthNode(&head, 6));
    printf("get Head Value: %d\r\n", getHead(&head));
    printf("get Tail Value: %d\r\n", getTail(&head));
    printf("Total Number of nodes in LL: %d\r\n", countNumberNodes(&head));
    
    return 0;
}