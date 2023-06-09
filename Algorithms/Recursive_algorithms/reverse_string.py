# Write a recursive function to reverse a string

def reverse_string(string):
    if len(string) == 0:
        return
    else:
        reverse_string(string[1:])
        print(string[0], end='')

str = "Hello, World!"
reverse_string(str)
print()