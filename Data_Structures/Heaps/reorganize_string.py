# Given a string S, check if the letters can be rearranged so that two characters that are adjacent
# to each other are not the same

import heapq

def reorganize_string(S):
    char_counts = [0] * 26
    for ch in S:
        char_counts[ord(ch) - ord('a')] += 1

    heap = []
    for i in range(26):
        if char_counts[i] > 0:
            heapq.heappush(heap, (-char_counts[i], chr(ord('a') + i)))

    result = []
    while len(heap) >= 2:
        count1, ch1 = heapq.heappop(heap)
        count2, ch2 = heapq.heappop(heap)
        result.extend([ch1, ch2])
        if count1 + 1 < 0:
            heapq.heappush(heap, (count1 + 1, ch1))
        if count2 + 1 < 0:
            heapq.heappush(heap, (count2 + 1, ch2))

    if heap:
        count, ch = heapq.heappop(heap)
        if count < -1:
            return ""
        result.append(ch)

    return "".join(result)

S = "aab"
result = reorganize_string(S)
print("Reorganized string:", result)
