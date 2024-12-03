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

    def resize(self):
        self.capacity *= 2  # Double the capacity
        new_arr = [None] * self.capacity
        # Copy elements to the new array
        for i in range(self.length):
            new_arr[i] = self.arr[i]
        self.arr = new_arr

            



# Example usage
#arr = DynamicArray()
#arr.pushback(2)
#arr.pushback(4)
#arr.pushback(5)
#print(arr.arr)  # Output: [2, 4, 5, None, None, None, None, None, None, None]

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

print(getConcatentaion2(nums))