# Write a recursive function to find the GCD (greatest common divisor) of two numbers

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

number1 = 36
number2 = 48
result = gcd(number1, number2)
print("GCD of", number1, "and", number2, "is", result)