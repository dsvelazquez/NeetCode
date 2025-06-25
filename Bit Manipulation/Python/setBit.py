num = 5
print(f"Original Number: {num:b}")
def setBit(num:int, bit:int) -> int:
    num |= (1 << bit)
    return num

num = setBit(num,1)
print(f"Set Number: {num:b}")
      