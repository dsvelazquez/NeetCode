"""
You are given an integer n representing the number of steps to reach the top of a staircase. You can climb with either 1 or 2 steps at a time.

Return the number of distinct ways to climb to the top of the staircase.

Example 1:

Input: n = 2

Output: 2
Explanation:

1 + 1 = 2
2 = 2
Example 2:

Input: n = 3

Output: 3
Explanation:

1 + 1 + 1 = 3
1 + 2 = 3
2 + 1 = 3
Constraints:

1 <= n <= 30
"""
def climbStairs(n: int) -> int:
    one, two = 1, 1
    res = 0
    for i in range(n-1):
        res = one + two
        two = one
        one = res
    return res if n != 1 else 1

print(climbStairs(2))