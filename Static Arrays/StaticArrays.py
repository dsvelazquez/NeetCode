#1) Read from an array
myArr = [1, 2, 3, 5, 6, 9]
#print(myArr)
#print(myArr[1])

#2) Traverse through an array
def traverseArr(myArr):
    for i in range(len(myArr)):
        print(myArr[i])

#3) Deleting from an array
def removeEnd(arr, length):
    if length > 0:
        arr[length-1] = 0
    
    traverseArr(arr)

#removeEnd(myArr, len(myArr))

#4) Deleting at an ith index
def removeIthIndex(arr, i, length):
    for i in range(i+1, length):
        arr[i - 1] = arr[i]
    
    traverseArr(arr)

#removeIthIndex(myArr, 4, len(myArr))

#5) Inserting at the end
def insertEnd(arr, value, length, capacity):
    if length < capacity:
        arr[length-1] = value
    
    traverseArr(arr)

#insertEnd(myArr, 20, len(myArr))
#6) Inserting at the ith index
def insertIth(arr, i, n, length):
    # Shift starting from the end to i.
    for index in range(length - 1, i - 1, -1):
        arr[index + 1] = arr[index]
    
    # Insert at i
    arr[i] = n

    traverseArr(arr)

#insertIth(myArr, 2, 200, len(myArr))

#PROBLEMS
#Hint: For these problems, you want to use a pointer to keep track of the array since you cant use a second array.
#1) Remove duplicates
'''
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores). Use the same array O(1)
'''

nums = [0,0,1,1,1,2,2,3,3,4]

def removeDuplicates(nums): # only works for sorted arrays
    
    wptr = 1                 # set wptr = 1 because sorted array is always unique at index 0

    for i in range(1, len(nums)): # start i at 1
        if nums[i] != nums[wptr - 1]: # only adjust array when the neighbors are !=
            nums[wptr] = nums[i]
            wptr += 1
    
    print(nums)
    return wptr

#2) Remove Element
'''
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
'''
nums2 = [0,1,2,2,3,0,4,2]

def removeElement(nums, val):

    k = 0 # pointer to track length of array without val

    for i in range(len(nums)):
        if nums[i] != val:
            nums[k] = nums[i]
            k = k+1
    
    print(k)
    return k


def main():
   
    #print(myArr)
    #print(myArr[1])

    #removeEnd(myArr, len(myArr))

    #removeIthIndex(myArr, 4, len(myArr))

    #insertEnd(myArr, 20, len(myArr))

    #insertIth(myArr, 2, 200, len(myArr))

    #problems
    #1)
    #print(removeDuplicates(nums))
    #2)
    removeElement(nums2,2)

if __name__ == '__main__':
    main()