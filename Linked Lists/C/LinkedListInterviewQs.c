#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node_t{
    int value;
    struct Node_t *next; // pointer to next node
}Node_t;

Node_t* createNode(int value){
    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void printList(Node_t* head){
    Node_t *current = head;
    while(current != NULL){
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
int getLength(Node_t* head){
    Node_t *current = head;
    int length=0;

    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
}
int searchElement(Node_t* head, int value){
    Node_t *current = head;
    int position = 0;

    while(current != NULL){
        if(current->value == value)
            return position;
        position++;
        current = current->next;
    }
    return -1; // not found
} 
Node_t* findNode(Node_t* head, int value){
    Node_t *current = head;
    
    while(current != NULL){
        if(current->value == value)
            return current;
        current = current->next;
    }
    return NULL;
}
void insertBeginning(Node_t** head, int value){
    Node_t *newNode = createNode(value); // creates a node and returns address of the node
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(Node_t** head, int value){
    Node_t *newNode = createNode(value);
    
    // Check if empty list
    if(*head == NULL){
        *head = newNode;
        return;
    }

    // Traverse through the list until the end
    Node_t *current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}
void insertAtPosition(Node_t** head, int data, int position){

    if(position < 0)
        return;
    if(position == 0)
        insertBeginning(head, data);
        return;

    // traverse through the list right before the target
    Node_t *current = *head;
    int i;
    for(i=0;i<position-1;i++){
        if(current == NULL)
            return;
        current = current->next;
    }
    // check for position out of bounds i.e. 2 nodes, position = 3
    if(current == NULL){
        free(current);
        return;
    }
    Node_t *newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
}
void deleteByValue(Node_t** head, int value){
    //check if list is empty
    if(*head == NULL)
        return;
    
    // handle first node
    if((*head)->value == value){
        Node_t *temp = *head; // preserve head address
        *head = (*head)->next; // move head to next node
        free(temp); // free the preserved node
        return;
    }
    // Traverse to look for the node prior to target node
    Node_t *current = *head;
    while(current->next != NULL && current->next->value != value){
        current = current->next;
    }

    // Check if value was found
    if(current->next == NULL)
        return;
    
    Node_t *temp = current->next; // preserve the node to be deleted
    current->next = temp->next;   // link current node to node after deleted node
    free(temp);                   // free the node
}
void deleteByPosition(Node_t** head, int position){
    //check if list is empty
    if(*head == NULL)
        return;
    
    if(position < 0)
        return;
    
    // delete position 0
    if(position == 0){
        Node_t *temp = *head;       // preserve head node
        (*head) = (*head)->next;    // assign head to head node
        free(temp);                 // free preserved node
        return;
    }

    // Traverse through the list to find the position node -1
    Node_t *current = *head;
    int i;
    for(i=0;i<position-1;i++){
        if(current == NULL)
            return;
        current=current->next;
    }

    // We can still hit NULL when position is > than # of nodes
    if(current == NULL || current->next == NULL)
        return;

    Node_t *temp = current->next;
    current->next = temp->next;
    free(temp);
}
Node_t* reverseList(Node_t* head){ // requires 3 pointers for iteration
    Node_t *prev = NULL;
    Node_t *current = head;
    Node_t *next = NULL;

    while(current != NULL){
        next = current->next;       // Point to next node
        current->next = prev;       // reverse the link
        prev = current;
        current = next;
    }
    return prev;                     // returns new head (previously tail)
}
Node_t* findMiddle(Node_t* head){ // two pointer method using slow and fast pointers. Time Complexity O(n)

    // check list is empty
    if(head == NULL){
        return NULL;
    }

    Node_t *slow = head;
    Node_t *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
bool hasCycle(Node_t *head){ // two pointer method using slow and fast pointers.
    //check list is empty
    if(head == NULL){
        return NULL;
    }
    Node_t *slow = head;
    Node_t *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast){
            return true;
        }
    }
    
    return false;
}
void freeList(Node_t **head){
    Node_t *current = *head;
    
    while(current != NULL){
        Node_t *temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL; // Reset the head pointer to NULL
}
Node_t* mergeTwoSortedLists(Node_t *L1, Node_t *L2){
    Node_t dummy;
    Node_t *tail = &dummy;
    dummy.next = NULL;

    while(L1 != NULL && L2 != NULL){
        if(L1->value <= L2->value){
            tail->next = L1;
            L1 = L1->next;
        }else{
            tail->next = L2;
            L2 = L2->next;
        }
        tail = tail->next;
    }
}
int main(){

    


    return 0;
}