'''
Design Singly Linked List
Design a Singly Linked List class.

Your LinkedList class should support the following operations:

LinkedList() will initialize an empty linked list.
int get(int i) will return the value of the ith node (0-indexed). If the index is out of bounds, return -1.
void insertHead(int val) will insert a node with val at the head of the list.
void insertTail(int val) will insert a node with val at the tail of the list.
bool remove(int i) will remove the ith node (0-indexed). If the index is out of bounds, return false, otherwise return true.
int[] getValues() return an array of all the values in the linked list, ordered from head to tail.

'''
class NewNode:
    def __init__(self, val):
        self.val = val
        self.next = None

class LinkedList:
    
    def __init__(self): 
        self.head = None


    def get(self, index: int) -> int:        
        """
        Get value of a specific node
        """
        if not self.head:
            print ("list is empty")
            return
        
        i = 0
        curr = curr.next
        while i < index and curr:
            curr = curr.next
            i += 1
        
        return curr.val

    def prepend(self, val: int) -> None:
        """
        Adds a new node with the given data to the beginning of the list.
        """
        #if list is empty, create a new node
        if not self.head.next:
            self.head = NewNode(val)
            return
        new_node = NewNode(val)
        new_node.next = self.head
        self.head = new_node


    def append(self, val: int) -> None:
        """
        Adds a new node with the given data to the end of the list.
        """
        new_node = NewNode(val)
        if not self.head:       #if list is empty set head to new node
            self.head = new_node
            return
        
        curr = self.head
        while curr.next:
            curr = curr.next
        curr.next = new_node

    def remove(self, index: int) -> bool: # get the ith node prior to the node designated for removal
        #if list is empty
        if not self.head:
            print("empty list")
            return False
        #if removing head
        if index == 0:
            self.head = self.head.next
            return True
        #if removing down the list
        i = 0
        curr = self.head
        while i < index - 1 and curr: # prevent indexerror
            curr = curr.next
            i += 1
        
        #remove node
        if curr and curr.next:
            curr.next = curr.next.next #remove the node
            return True
        return False
        
    def getValues(self) -> list[int]: #get all values in the linked list
        curr = self.head
        res = list
        if not curr:
            print("Empty List")
        while curr:
            res.append(curr.val)
            curr = curr.next
        return res

    def print_list(self) -> None:
        curr = self.head
        while curr:
            print(curr.val, end = " ")
            curr = curr.next
        print()

    def reverseList(self) -> None:
        """
        Reverses the linked list.
        """
        #use two pointers
        prev = None
        curr = self.head

        while curr:
            nxt = curr.next # save the nodes address before breaking the link
            curr.next = prev # reverse the pointer
            prev = curr      # Move 'Prev' one step forward
            curr = nxt       # ' Move 'curr' one step forward   
        self.head = prev     # update the head to the last node (prev)


def mergeSortedLists(L1: LinkedList, L2: LinkedList) -> LinkedList:
    #begin with a dummy node
    dummy = NewNode(-1)
    tail = dummy

    while L1 and L2:
        if L1.val> L2.val:
            tail.next = L2
            L2 = L2.next
        else:
            tail.next = L1
            L1 = L1.next
        tail = tail.next

    #append remaining nodes
    if L1:
        tail.next = L1
    if L2:
        tail.next = L2
    
    return dummy.next # return the head of the merged list

l1 = LinkedList()
l1.append(5)
l1.append(6)
l1.append(5)

l2 = LinkedList()
l2.append(2)
l2.append(4)
l2.append(6)

merged_list = mergeSortedLists(l1.head, l2.head)

# Print the merged list (using the print_list method)
curr = merged_list
while curr:
    print(curr.val, end=" ")  # Access the 'val' attribute of NewNode
    curr = curr.next
print()  # Print a newline after the list