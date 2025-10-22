#include <iostream>

struct ListNode{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

void printList(ListNode* head){
    ListNode* current = head;
    while(current != nullptr){
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

void insertAtHead(ListNode*& head, int val){

    ListNode *newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(ListNode*& head, int val){

    ListNode *newNode = new ListNode(val);

    //check if list is empty
    if(head == nullptr){
        head = newNode;
        return;
    }

    // Otherwise, traverse through the list
    ListNode *current = head;
    while(current->next != nullptr){
        current = current->next;
    }

    current->next = newNode;
}

void insertAtPosition(ListNode*& head, int val, int pos){

    //check if there is a list
    if(head == nullptr || pos == 0){
        insertAtHead(head, val);
        return;
    }

    //Otherwise, traverse to N-1 position
    ListNode* current = head;
    int count = 0;
    while(current != nullptr && count < pos-1){
        current = current->next;
        count++;
    }

    if(current == nullptr){
        std::cout << "Out of bounds!\n";
        return;
    }

    //Insert new node
    ListNode* newNode = new ListNode(val);
    newNode->next = current->next;
    current->next = newNode;  
        
}

void deleteAtPosition(ListNode*& head, int pos){

    // Is list empty?
    if(head == nullptr || pos < 0){
        return;
    }

    // Are we deleting position 0?
    if(pos == 0){
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    //Otherwise, go to N-1 position to delete node
    ListNode* current = head;
    int count = 0;
    while(current != nullptr && count < pos - 1){
        current = current->next;
        count++;
    }

    if(current == nullptr || current->next == nullptr)
        return;

    ListNode* temp = current->next;
    current->next = temp->next;
    delete temp;
}

void connectHeadTail(ListNode* head){

    // Is there a list?
    if(head == nullptr)
        return;

    // Otherwise, look for the tail
    ListNode *tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    tail->next = head;
}
bool hasCycle(ListNode* head) {

    ListNode *slowPtr = head;
    ListNode *fastPtr = head;

    // use tortoise-hare algorithm (slow/fast pointers)
    while(fastPtr != nullptr && fastPtr->next != nullptr){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;

        if(slowPtr == fastPtr)
            return true;
    }

    return false;
}

// For reversing a list, you need three pointers: previous, current, and tempNode (holds the next node)
ListNode* reverseList(ListNode* head) {
    ListNode* prev {nullptr};
    ListNode* current {head};
    ListNode* temp {nullptr};

    while(current != nullptr){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }

    return prev; // prev is the new head
}

ListNode* middleNode(ListNode* head) {
    
    // Is there a list?
    if(head == nullptr)
        return nullptr;

    // Otherwise, use Tortoise-Hare algorightm (fast/slow pointers)
    ListNode* slowPtr = head;
    ListNode* fastPtr = head;
    
    while(fastPtr != nullptr && fastPtr->next != nullptr){
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // returns the middle node
    return slowPtr;
}

// Merge two sorted lists into one list.
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    // create a dummy node to avoid checking if head == nullptr
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    // Begin appending nodes to the dummy node
    while(list1 != nullptr && list2 != nullptr){
        if(list1->val < list2->val){
            current->next = list1; // assign current node to next node in list1
            list1 = list1->next; // update list to next node
        }else{
            current->next = list2; // assign curent node ot next node in list2
            list2 = list2->next; // update list to next node
        }
        current = current->next; // update current ptr to point to next node
    }

    // check the remaining list if it still has nodes
    if(list1 == nullptr)
        current->next = list2; // append rest of list2 to sorted list
    else if (list2 == nullptr)
        current->next = list1; // append rest of list1 to sorted list

    return dummy->next; // head
}

int main(){
    
    ListNode* head = nullptr;
    ListNode* temp = nullptr;

    insertAtHead(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 35);
    insertAtTail(head, 77);

    printList(head);

    //connectHeadTail(head);
    std::cout << "Is Cycle? " << hasCycle(head) << std::endl;
    
    insertAtPosition(head, 100, 4);
    printList(head);

    deleteAtPosition(head, 3);
    printList(head);

    temp = middleNode(head);
    std::cout << "Middle node: " << temp->val << std::endl;

    ListNode* head2 = nullptr;
    ListNode* merged = nullptr;
    insertAtHead(head2, 9);
    insertAtTail(head2, 11);
    insertAtTail(head2, 34);
    insertAtTail(head2, 76);
    printList(head2);

    merged = mergeTwoLists(head, head2);

    printList(merged);

    ListNode* reversed = nullptr;
    reversed = reverseList(merged);
    printList(reversed);
    return 0;
}