"""
Design a stack class that supports the push, pop, top, and getMin operations.

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
Each function should run in 
O
(
1
)
O(1) time.

Example 1:

Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

Output: [null,null,null,null,0,null,2,1]

Explanation:
MinStack minStack = new MinStack();
minStack.push(1);
minStack.push(2);
minStack.push(0);
minStack.getMin(); // return 0
minStack.pop();
minStack.top();    // return 2
minStack.getMin(); // return 1
"""

class MinStack:
    def __init__(self):
        """
        Initialize the stack with a list
        """
        self.items = []

    def push(self, val:int) -> None:
        """
        Adds a value to the stack
        """
        self.items.append(val)
        

    def pop(self) -> None:
        """
        Pops/removes top item of the stack
        """
        self.items.pop()

    def top(self) -> int: 
        """
        Returns the last item on top of the stack
        """
        return self.items[-1]
    
    def getMin(self) -> int:
        self.items2 = []
        # copy the elements from items to items2
        for item in self.items:
            self.items2.append(item)

        if self.items2:
            min = self.items2.pop()
        else:
            return -1
        
        while self.items2:
            temp = self.items2.pop()
            if temp < min:
                min = temp
        
        return min
    
minStack = MinStack()
minStack.push(15)
minStack.push(6)
minStack.push(3)
minStack.push(0)
print(minStack.getMin())
minStack.pop()
minStack.top()
print(minStack.getMin())




