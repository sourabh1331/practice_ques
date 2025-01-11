#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

void countFrequency(char str[]) {
    int i, len;
    int freq[26] = {0};

    len = strlen(str);

    for(i = 0; i < len; i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            freq[str[i] - 'a']++;
        } else if(str[i] >= 'A' && str[i] <= 'Z') {
            freq[str[i] - 'A']++;
        }
    }

    printf("\nFrequency of all characters in the given string: \n");
    for(i = 0; i < 26; i++) {
        if(freq[i] != 0) {
            printf("'%c' = %d\n", (i + 'a'), freq[i]);
        }
    }
}

int main() {
    char str[MAX_SIZE];

    printf("Enter any string: ");
    fgets(str, MAX_SIZE, stdin);
    
    str[strcspn(str, "\n")] = '\0';

    countFrequency(str);

    return 0;
}
