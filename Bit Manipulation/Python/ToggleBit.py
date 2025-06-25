num = 5
print(f"Original Number: {num:b}") # Shift 1 to Nth bit then invert and AND with NUM;
def ToggleBit(num: int, bit:int) -> int:
    mask = (1<<bit)
    num ^= mask
    return num


num = ToggleBit(num,2)
print(f"Toggle bit: {num:b}")
num = ToggleBit(num,2)
print(f"Toggle bit: {num:b}")
