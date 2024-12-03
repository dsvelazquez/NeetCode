class stack:
    def __init__(self):

        """
        Initialize an empty stack
        """
        self.items = []

    def push(self, item):

        """
        Adds an item to the top fo the stack

        Args:
        item: The item to be added
        """
        self.items.append(item)

    def pop(self):

        """
        Removes and returns the item from the top of the stack

        Returns:
        The item from the top of the stack
        Raises:
        IndexError: if the stack is empty
        """

        if not self.is_empty():
            return self.items.pop()
        else:
            raise IndexError("Cannot pop from an empty stack")
        
    def peek(self):
        """
        Returns the item from the top of the stack without removing it

        Reurns:
        The item from the top of the stack
        Raises:
        IndexError: If the stack is empty
        """

        if not self.is_empty():
            return self.items[-1] # get last item from the stack
        else:
            raise IndexError("Cannot peek into an empty stack")
        
    def is_empty(self):
        """
        Checks if the stack is empty

        Returns:
        True if the stack is empty, False otherwise
        """
        return len(self.items) == 0 # if this condition satisfies, then it's true. Otherwise, it's false.
    

#Examples
#stack = stack()

#stack.push(5)
#stack.push(6)
#stack.push(8)

#print(stack.peek())
#print(stack)
#print(stack.pop())
#print(stack.pop())

#print(stack.is_empty())
#print(stack.pop())
#print(stack.is_empty())

#Problems

'''
You are given a string s consisting of the following characters: '(', ')', '{', '}', '[' and ']'.

The input string s is valid if and only if:

Every open bracket is closed by the same type of close bracket.
Open brackets are closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
Return true if s is a valid string, and false otherwise.

Input: s = "([{}])"

Output: true

Input: s = "[(])"

Output: false
'''
s = "{"
#s = "){}}{"
#s = "([{}])"

def isValid(s:str) -> bool:
    stack = []
    hashMap = { ')':'(', '}':'{', ']':'['} #map every closed paranthesis with an open paranthesis

    for c in s: # for each character in s
        if c not in hashMap:    # if the character is not in the hashmap
            stack.append(c)     # add the character to the stack
            print(stack)
        else:
            if stack and stack[-1] == hashMap[c]:   #if their are items in the stack and top of the stack is equal to the value in hashmap
                stack.pop()                         # pop the value
            else:
                return False
        
    return True if not stack else False
    
print(isValid(s))
