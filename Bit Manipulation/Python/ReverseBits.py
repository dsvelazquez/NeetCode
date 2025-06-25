"""
Given a 32-bit unsigned integer n, reverse the bits of the binary representation of n and return the result.

Example 1:

Input: n = 00000000000000000000000000010101

Output:    2818572288 (10101000000000000000000000000000)
Explanation: Reversing 00000000000000000000000000010101, which represents the unsigned integer 21, gives us 10101000000000000000000000000000 which represents the unsigned integer 2818572288.

"""
SIZE_NUM = 8   # number of bits 
num = 253
def reverseBits(n: int) -> int:
    res = 0
    for i in range(SIZE_NUM):
        bit = (num >> i) & 1 #Get the ith bit
        res += (bit << ((SIZE_NUM-1)-i))#Shift the ith bit to the MS place
    return res

res = reverseBits(num)
print(f"Original number: {num:b}") 
print(f"Reversed number: {res:b}")
       