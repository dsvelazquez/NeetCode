"""
Binary Search requires two pointers: LEFT and RIGHT
LEFT pointer must not exceed Right pointer
RIGHT pointer must not exceed Left pointer
Calculate MIDPOINT pointer : (L+R)//2
Check if TARGET is less than array[MIDPOINT] and update RIGHT POINTER if true
Check if TARGET is greater than array[MIDPOINT] and update LEFT POINTER if true
CHECK IF TARGET is equal to array[MIDPOINT] and return MIDPOINT index if true
"""

def BinarySearch(sArr: list[int], target: int) -> int:
    L, R = 0, len(sArr) - 1 # initialize Left and Right Pointers

    while L <= R:
        M = (L + R) // 2

        if target > sArr[M]:
            L = M + 1
        elif target < sArr[M]:
            R = M - 1
        else:
            return M
        
    return -1

sArr = [1,2,3,4,5,6,7,8,9]

index = BinarySearch(sArr, 7)
print(index)

