#include <stdio.h>
#include <stdlib.h>
#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            printf("Assertion failed in %s, function %s, line %d: %s\n", __FILE__, __func__, __LINE__, message); \
            exit(1); \
        } \
    } while (0)
    
typedef struct Node_t{
    int value;
    struct Node_t *next; // pointer to next node
}Node_t;

// Prints the linked list
void printList(Node_t *head){
	Node_t *current = head;

    while(current != NULL){
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

// Pushes Node to the top of the list
void push(Node_t **head, int value){
	
	//1. Create a new node
    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));
	
	// 2. Add value
    newNode->value = value;
	
	// 3. point to old head
    newNode->next = *head;
	
	// 4. update the head
    *head = newNode;
	
}

// Pops Node from top of the list and returns the value
int pop(Node_t **head){
	
	//Check if there is a list
    if(*head == NULL)
        return -1;

    // 1. get address of next node
    Node_t *node = (*head)->next;
    
    // 2. get value of popped node
    int value = (*head)->value;

    // 3. free the popped node
    free(*head);

    // 4. assign head to new node
    *head = node;
	
	return value;	
}

void insert_at_index(Node_t **head, int index, int new_value){
	//check if empty
	if(*head == NULL){
		push(head, new_value);
		return;
	}
    
    if(index == 0){
        push(head, new_value);
        return;
    }
	
	// Create temp pointer to look for the index
	Node_t *temp = *head;
	int i;
	for(i=0;i<index-1;i++){
		if(temp == NULL)
			return;
		temp = temp->next;
	}

	if(temp == NULL){
        printf("Error: Index out of boudns for insertion");
        return;
    }

	// Create New Node
	Node_t *newNode;
	newNode = (Node_t*)malloc(sizeof(Node_t));
	
	// Assign value to new node
	newNode->value = new_value;	
	
	// Assigne newNode next to current->next
	newNode->next = temp->next;
	
	// Current node next is new node
	temp->next = newNode;
	
}
int remove_by_index(Node_t **head, int index){
    //check if list is empty
    if(*head == NULL)
        return -1;
    
    // check if index == 0
    if(index == 0)
        return pop(head);

    // go to node before index node to remove
    Node_t *current = *head;
    int i;
    for(i=0;i<index-1;i++){
        printf("%d \n", current->value);
        if(current == NULL)
            return -1;
        current = current->next;
    }

    Node_t *temp = current->next; // assign temp node to the address of node we are removing
    int value = temp->value;
    current->next = temp->next;
    free(temp);
    
    return value;
}
// Forward declarations for our linked list functions
void push(Node_t **head, int new_value);
int pop(Node_t **head);
void insert_at_index(Node_t **head, int index, int new_value);
int remove_by_index(Node_t **head, int index);

// --- UNIT TEST FUNCTIONS ---

// Test creating an empty list and pushing the first element
void test_push_to_empty_list() {
    Node_t *head = NULL;
    push(&head, 10);
    ASSERT(head != NULL, "Head should not be NULL after push.");
    ASSERT(head->value == 10, "Head value should be 10.");
    ASSERT(head->next == NULL, "Head->next should be NULL.");
    free(head); // Cleanup
    printf("test_push_to_empty_list: PASSED\n");
}

// Test pushing multiple elements
void test_push_multiple() {
    Node_t *head = NULL;
    push(&head, 10);
    push(&head, 20);
    ASSERT(head->value == 20, "Head value should be 20.");
    ASSERT(head->next->value == 10, "Second node value should be 10.");
    free(head->next);
    free(head);
    printf("test_push_multiple: PASSED\n");
}

// Test popping from a list
void test_pop() {
    Node_t *head = NULL;
    push(&head, 10);
    push(&head, 20);
    int val = pop(&head);
    ASSERT(val == 20, "Popped value should be 20.");
    ASSERT(head->value == 10, "New head should be 10.");
    free(head);
    printf("test_pop: PASSED\n");
}

// Test popping from an empty list
void test_pop_from_empty() {
    Node_t *head = NULL;
    int val = pop(&head);
    ASSERT(val == -1, "Popping from empty list should return -1.");
    ASSERT(head == NULL, "Head should still be NULL.");
    printf("test_pop_from_empty: PASSED\n");
}

// Test inserting a node in the middle
void test_insert_in_middle() {
    Node_t *head = NULL;
    push(&head, 10);
    push(&head, 30); // List: 30 -> 10
    insert_at_index(&head, 1, 20); // List: 30 -> 20 -> 10
    ASSERT(head->next->value == 20, "Value at index 1 should be 20.");
    ASSERT(head->next->next->value == 10, "Value at index 2 should be 10.");
    pop(&head); pop(&head); pop(&head); // Cleanup
    printf("test_insert_in_middle: PASSED\n");
}

// Test removing a node from the middle
void test_remove_from_middle() {
    Node_t *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30); // List: 30 -> 20 -> 10
    int val = remove_by_index(&head, 1); // Remove 20
    ASSERT(val == 20, "Removed value should be 20.");
    ASSERT(head->next->value == 10, "Node after removed one should be 10.");
    pop(&head); pop(&head); // Cleanup
    printf("test_remove_from_middle: PASSED\n");
}
int main(){
	
    printf("--- Running Linked List Unit Tests ---\n");
    test_push_to_empty_list();
    test_push_multiple();
    test_pop();
    test_pop_from_empty();
    test_insert_in_middle();
    test_remove_from_middle();
    printf("\nAll tests passed successfully!\n");






    /*
	Node_t *head = NULL;
	
	push(&head, 10);
	push(&head, 20);
	push(&head, 30);
	
    printList(head);

     printf("--- Testing insert_at_index() ---\n");
    
    insert_at_index(&head, 1, 15); // Insert 15 at index 1
    printList(head); 
    insert_at_index(&head, 0, 25); // Insert 25 at index 0 (push)
    printList(head); 
    insert_at_index(&head, 4, 5);  // Insert 5 at index 4
    printList(head); 
    printf("\n");

     printf("--- Testing remove_by_index() ---\n");
    int removed_value = remove_by_index(&head, 2); 
    printf("Removed value: %d\n", removed_value);
    printList(head); 
    removed_value = remove_by_index(&head, 0); 
    printf("Removed value: %d\n", removed_value);
    printList(head); 
    
    // Clean up remaining nodes to prevent memory leaks
    while(head != NULL) {
        pop(&head);
    }
    printf("\nFinal list after cleanup:\n");
    printList(head);
    */
	return 0;
}