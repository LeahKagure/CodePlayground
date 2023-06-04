# Given an array of strings, group the anagrams together

def group_anagrams(strs):
    hash_map = {}

    for word in strs:
        sorted_word = "".join(sorted(word))
        if sorted_word in hash_map:
            hash_map[sorted_word].append(word)
        else:
            hash_map[sorted_word] = [word]

    print("Grouped Anagrams:")
    for group in hash_map.values():
        print(group)

strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
group_anagrams(strs)
