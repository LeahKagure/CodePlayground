// Given a string S, check if the letters can be rearranged so that two characters that are adjacent
// to each other are not the same

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ch;
    int count;
} CharCount;

int compare(const void* a, const void* b) {
    return ((CharCount*)b)->count - ((CharCount*)a)->count;
}

void swap(CharCount* a, CharCount* b) {
    CharCount temp = *a;
    *a = *b;
    *b = temp;
}

char* reorganizeString(char* S) {
    int charCounts[26] = {0};
    int len = strlen(S);

    for (int i = 0; i < len; i++)
        charCounts[S[i] - 'a']++;

    CharCount* counts = (CharCount*)malloc(26 * sizeof(CharCount));
    for (int i = 0; i < 26; i++) {
        counts[i].ch = 'a' + i;
        counts[i].count = charCounts[i];
    }

    qsort(counts, 26, sizeof(CharCount), compare);

    if (counts[0].count > (len + 1) / 2) {
        free(counts);
        return "";
    }

    int index = 0;
    for (int i = 0; i < 26; i++) {
        while (counts[i].count > 0) {
            S[index] = counts[i].ch;
            index += 2;
            if (index >= len)
                index = 1;
            counts[i].count--;
        }
    }

    free(counts);
    return S;
}

int main() {
    char S[] = "aab";

    char* result = reorganizeString(S);
    printf("Reorganized string: %s\n", result);

    return 0;
}
