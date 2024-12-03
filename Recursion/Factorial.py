#recursive
def Factorial(val: int) -> int:
    if val <= 1:
        return 1
    
    return val * Factorial(val - 1)

print(Factorial(120))

#iteration
def Factorial_It(val: int) -> int:

    res = 1
    while val > 1:
        res = val * res
        val = val - 1
    
    return res

print(Factorial_It(5))
