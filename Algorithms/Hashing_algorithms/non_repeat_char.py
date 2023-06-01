# Given a string, find the first non-repeating character

def find_first_non_repeating_char(s):
    count = {}
    for char in s:
        count[char] = count.get(char, 0) + 1

    for i, char in enumerate(s):
        if count[char] == 1:
            return i

    return -1  # No non-repeating character found

s = "openai"

index = find_first_non_repeating_char(s)
if index != -1:
    print(f"First non-repeating character: {s[index]}")
else:
    print("No non-repeating character found!")
