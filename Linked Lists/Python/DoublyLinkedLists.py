class NewNode:
    def __init__(self, val):
        self.prev = None
        self.val = val
        self.next = None

class DLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insertFront(self, val):
        newNode = NewNode(val) # create New Node

        #Check if list is empty
        if not (self.head and self.tail):
            self.head = newNode
            self.tail = newNode
            return
        
        newNode.next = self.head
        self.head.prev = newNode
        self.head = newNode

    def insertEnd(self, val):
        newNode = NewNode(val) # create New Node

        #Check if list is empty
        if not (self.head and self.tail):
            self.head = newNode
            self.tail = newNode
            return
        
        self.tail.next = newNode
        newNode.prev = self.tail
        self.tail = newNode

    def removeFront(self):
        self.head = self.head.next
        self.head.prev = None
    
    def removeEnd(self):
        self.tail = self.tail.prev
        self.tail.next = None

    def countNodes(self):
        curr = self.head
        count = 0
        while curr:
            count = count + 1
            curr = curr.next
        return count
    
    def removeIth(self, index):
        #if list is empty
        if not (self.head and self.tail):
            print("Empty List!")
            return False
        
        #if Ith node is greater than number of nodes
        if index > (self.countNodes() - 1):
            print("Index doesn't exist in LL")
            return False
        
        #Remove the head
        if index == 0:
            self.removeFront()
            return True

        #Remove the tail
        if index == (self.countNodes() - 1):
            self.removeEnd()
            return True
        
        #Traverse down the line
        curr = self.head
        i = 0
        while i < index - 1 and curr:
            i = i+1
            curr = curr.next
        
        if curr:
            curr.next = curr.next.next
            curr.next.prev = curr
            return True
        
        return False

    def print(self):
        curr = self.head
        while curr != None:
            print(curr.val, " -> ")
            curr = curr.next

doubly = DLinkedList()
doubly.insertFront(5)
doubly.insertEnd(10)
doubly.insertEnd(4)
doubly.insertEnd(7)
doubly.insertEnd(22)
doubly.removeIth(4)
#doubly.removeFront()
#doubly.removeEnd()
doubly.print()
print("Number of nodes: " + str(doubly.countNodes()))

        