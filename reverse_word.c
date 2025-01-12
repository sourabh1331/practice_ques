#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseString(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseWords(char* str) {
    int n = strlen(str);
    reverseString(str, 0, n - 1);
    int start = 0;
    for (int i = 0; i <= n; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverseString(str, start, i - 1);
            start = i + 1;
        }
    }
}

void printString(char* str) {
    printf("%s\n", str);
}

int main() {
    char* str;
    str = (char*)malloc(100 * sizeof(char));
    if (str == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    reverseWords(str);
    
    printf("String with each word reversed: ");
    printString(str);

    free(str);

    return 0;
}