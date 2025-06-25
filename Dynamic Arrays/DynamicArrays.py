# Dynamic Array Insertion

# 1
# Insert n in the last position of the array
# First allocate memory in the __init__
# Second add elements using pushback()
# Third, if length == capacity, resize the array by doubling it.
class DynamicArray:

    def __init__(self, initial_capacity=5): # must initialize capacity, length, and array
        self.capacity = initial_capacity
        self.length = 0
        self.arr = [None] * initial_capacity #creates a list of "None" elements and multiplies by initial_capacity

    def pushback(self, n):
        if self.length == self.capacity:
            self.resize()
        self.arr[self.length] = n
        self.length += 1

    def popout(self):
        if self.length == 0:
            print("No elements to popout")
            return
        self.arr[self.length-1] = None
        self.length -= 1

    def removeIndex(self, index):
        # check the bounds
        if index < 0 or index > self.length-1:
            print("index out of bounds")
            return
        
        # from index, shift every element to the left
        for i in range(index, self.length):
            self.arr[i] = self.arr[i + 1]   
        
        self.length -= 1 # adjust the length
        self.arr[self.length] = None # set length index to None. This takes care of the removed element

    def sort_bubble(self):
        swapped = False
        if self.length <= 1:
            return # Already sorted or empty
        
        for i in range(self.length): # loop through each number in the array
            #The range of elements decreases by one (largest element now sorted at the end)
            for j in range(self.length - 1 - i): 
                if self.arr[j] > self.arr[j+1]:
                    self.arr[j] ^= self.arr[j+1]
                    self.arr[j+1] ^= self.arr[j]
                    self.arr[j] ^= self.arr[j+1]
                    swapped = True
                    #self.arr[j], self.arr[j+1] = self.arr[j+1], self.arr[j] # Swap
        if swapped == False: #optimization. Not needed but good if elements are sorted early on
            return self.arr
        
        return self.arr
    
    def resize(self):
        self.capacity *= 2  # Double the capacity
        new_arr = [None] * self.capacity
        # Copy elements to the new array
        for i in range(self.length):
            new_arr[i] = self.arr[i]
        self.arr = new_arr     



#Example usage
arr = DynamicArray()
arr.pushback(2)
arr.pushback(4)
arr.pushback(5)
arr.popout()
arr.removeIndex(1)
arr.pushback(90)
arr.pushback(66)
arr.pushback(3)
arr.pushback(1)
arr.pushback(28)
arr.pushback(19)
print(arr.length)
print(arr.arr)  # Output: [2, 4, 5, None, None, None, None, None, None, None]
print(arr.sort_bubble())


# Problems
#1)
'''
Given an integer array nums of length n, you want to create an array ans of 
length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).
Specifically, ans is the concatenation of two nums arrays.
Return the array ans.

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
'''

nums = [1,3,2,1]

#method 1
def getConcatenation(nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
    
        capacity = len(nums) * 2
        newArr = [None] * capacity
        
        j = 0
        for i in range(len(newArr)):
            newArr[i] = nums[j]
            j = j + 1
            if j % len(nums) == 0:
                 j = 0
            
        return newArr

#res = getConcatenation(nums)
#print(res)

#method 2
def getConcatentaion2(nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ans = []

        for i in range(2):
            for n in nums:
                ans.append(n)

        return ans

#print(getConcatentaion2(nums))