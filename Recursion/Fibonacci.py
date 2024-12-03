# Fibonacci number: F(n) = F(n-1) + F(n-2)
# F(0) = 0 F(1) = 1
def Fibonacci(val:int) -> int:
    if val <= 1:
        return val
    
    return Fibonacci(val-1) + Fibonacci(val - 2)

print(Fibonacci(8))