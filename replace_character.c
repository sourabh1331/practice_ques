#include <stdio.h>
#include <stdlib.h>

void replaceCharacter(char *str, char oldChar, char newChar) {
    for (char *ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr == oldChar) {
            *ptr = newChar;
        }
    }
    printf("Modified String: %s\n", str);
}

int main() {
    char *str = (char *)malloc(100 * sizeof(char));
    char oldChar, newChar;
    scanf("%[^\n]%*c", str);
    scanf(" %c %c", &oldChar, &newChar);
    replaceCharacter(str, oldChar, newChar);
    free(str);
    return 0;
}