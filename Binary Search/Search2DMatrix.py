"""
You are given an m x n 2-D integer array matrix and an integer target.

Each row in matrix is sorted in non-decreasing order.
The first integer of every row is greater than the last integer of the previous row.
Return true if target exists within matrix or false otherwise.
"""

matrix=[
    [1,3,5,7],
    [10,11,16,20],
    [23,30,34,60]]

target = 31


def SearchMatrix(matrix: list[list[int]], target: int) -> bool:

    #Identify which row in the matrix the target lies
    rows = len(matrix)
    cols = len(matrix[0])
    foundRow = False

    #Check the rows for where the target might lie
    for i, row in enumerate (matrix):
        if row[0] <= target <= row[-1]:
            print(f"Row {i}: {row}")
            foundRow = True
            break
        
    if foundRow == False:
        return False

    #Perform Binary Search on the Row
    L, R = 0, cols-1
    while L <= R:
        mid = (L+R)//2
        print(matrix[i][mid])
        if target < matrix[i][mid]:
            R = mid - 1
        elif target > matrix[i][mid]:
            L = mid + 1
        else:
            return True
    #not found in binary search
    return False

print(SearchMatrix(matrix, target))