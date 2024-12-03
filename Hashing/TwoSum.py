"""
Given an array of integers nums and an integer target, return the indices i and j such that nums[i] + nums[j] == target and i != j.

You may assume that every input has exactly one pair of indices i and j that satisfy the condition.

Return the answer with the smaller index first.

Example 1:

Input: 
nums = [3,4,5,6], target = 7

Output: [0,1]
"""
# HASHMAP 1 pass method
nums = [3,4,5,6]
target = 9

def twoSum(nums:list[int], target: int) -> list[int]:
    hashMap = {}
    for i, num in enumerate(nums):
        res = target - num
        if res in hashMap:
            return [hashMap[res], i]
        else:
            hashMap[nums[i]] = i

print(twoSum(nums, target))

