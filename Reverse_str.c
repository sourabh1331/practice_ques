#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);
    int start = 0, end = length - 1;
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char *str;
    int size;

    printf("Enter the size of the string: ");
    scanf("%d", &size);
    getchar();

    str = (char *)malloc((size + 1) * sizeof(char));
    fgets(str, size + 1, stdin); 
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    reverseString(str);
    printf("Reversed string: %s\n", str);

    free(str);

    return 0;
}