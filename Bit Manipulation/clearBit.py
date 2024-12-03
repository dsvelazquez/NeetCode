num = 5
print(f"Original Number: {num:b}") # Shift 1 to Nth bit then invert and AND with NUM;
def clearBit(num: int, bit:int) -> int:
    mask = ~(1 << bit)
    num &= mask
    return num


num = clearBit(num,2)
print(f"Clear bit: {num:b}")
      