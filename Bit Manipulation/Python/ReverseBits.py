"""
Given a 32-bit unsigned integer n, reverse the bits of the binary representation of n and return the result.

Example 1:

Input: n = 00000000000000000000000000010101

Output:    2818572288 (10101000000000000000000000000000)
Explanation: Reversing 00000000000000000000000000010101, which represents the unsigned integer 21, gives us 10101000000000000000000000000000 which represents the unsigned integer 2818572288.

"""
num = 26
def reverseBits(n: int) -> int:
    res = 0
    for i in range(32):
        #Get the ith bit
        bit = (n >> i) & 1
        #shift the ith bit into Res
        res += (bit << (31 - i))
    return res

res = reverseBits(num)
print(f"Original number: {num:b}") 
print(f"Reversed number: {res:b}")
       