#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int longestSubstringWithoutRepeating(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int start = 0;
    int map[256] = {0};

    for (int end = 0; end < n; end++) {
        while (map[s[end]] > 0) {
            map[s[start]]--; 
            start++; 
        }
        map[s[end]]++;

        if ((end - start + 1) > maxLength) {
            maxLength = end - start + 1;
        }
    }

    return maxLength;
}

int main() {
    char s[100];
    printf("Enter the string: ");
    scanf("%s", s);

    int result = longestSubstringWithoutRepeating(s);
    printf("Length of the longest substring without repeating characters: %d\n", result);

    return 0;
}