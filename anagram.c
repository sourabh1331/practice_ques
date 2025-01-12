#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void sortString(char* str, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

bool areAnagrams(char* str1, char* str2) {
    if (strlen(str1) != strlen(str2)) {
        return false;
    }

    int length = strlen(str1);
    sortString(str1, length);
    sortString(str2, length);
    for (int i = 0; i < length; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    char* str1;
    char* str2;
    
    str1 = (char*)malloc(100 * sizeof(char));
    str2 = (char*)malloc(100 * sizeof(char));
    
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = '\0';
    
    if (areAnagrams(str1, str2)) {
        printf("The strings are anagrams.\n");
    } else {
        printf("The strings are not anagrams.\n");
    }
    
    free(str1);
    free(str2);
    
    return 0;
}