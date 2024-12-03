def HexToDecimal(hex):
    """
    Converts a hexadecimal integer to a decimal integer.

    Args:
    hex_int: The hexadecimal integer (e.g., 0x3A7).

    Returns:
    The decimal equivalent of the hexadecimal integer.
    """
    decimal_number = 0
    power = 0
    while hex > 0:
        digit = hex % 16 # Get last hex digit
        if 0 <= digit <= 15:
            decimal_value = digit
        else:
            raise ValueError("Invalid Hex digit")
        
        decimal_number += decimal_value * (16 ** power)
        power += 1
        hex //= 16
    
    return decimal_number

# Example usage:
hex_number = 0x3A7
decimal_number = HexToDecimal(hex_number)
print(decimal_number)  # Output: 935