def countBits(n: int) -> list[int]:
        count = [0] * (n+1)
        for num in range(n+1):
            temp = num
            while temp > 0:
                if temp & 1 == 1:
                    count[num] += 1
                temp = temp >> 1
        return count

print(countBits(4))
