# Count the number of bits in a number
def countBits(n: int) -> int:
    count = 0
    while (n > 0):
        if n & 1 == 1:
            count += 1
        n = n >> 1
    return count

print(countBits(255))