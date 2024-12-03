"""
Given an integer array nums, return true if any value appears more than once in the array, otherwise return false.

Example 1:

Input: nums = [1, 2, 3, 3]

Output: true
"""
nums1 = [1, 2, 7, 3]

def hasDuplicate(nums: list[int]) -> bool:
    hashMap = {}

    for num in nums:
        if num not in hashMap:
            hashMap[num] = 1
        else:
            hashMap[num] += 1

        if hashMap[num] > 1:
            return True
    
    return False


print(hasDuplicate(nums1))