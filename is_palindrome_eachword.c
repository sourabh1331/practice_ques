#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindrome(char *start, char *end) {
    while (start < end) {
        if (*start != *end) {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void checkPalindromeWords(char *str) {
    char *token = strtok(str, " ");
    while (token) {
        if (isPalindrome(token, token + strlen(token) - 1)) {
            printf("%s: Palindrome\n", token);
        } else {
            printf("%s: Not a palindrome\n", token);
        }
        token = strtok(NULL, " ");
    }
}

int main() {
    char *str = (char *)malloc(100 * sizeof(char));
    scanf("%[^\n]%*c", str);
    checkPalindromeWords(str);
    free(str);
    return 0;
}