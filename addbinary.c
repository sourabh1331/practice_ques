#include <stdio.h>
#include <string.h>
void addBinary(char* a, char* b, char* result) {
    int alen = strlen(a);
    int blen = strlen(b);
    int carry = 0, i = 0, j = 0, k = 0;

    while (i < alen || j < blen || carry) {
        int x = 0, y = 0;

        if (i < alen && a[alen - i - 1] == '1') {
            x = 1;
        }

        if (j < blen && b[blen - j - 1] == '1') {
            y = 1;
        }

        result[k++] = (x + y + carry) % 2 + '0';

        carry = (x + y + carry) / 2;

        i++; 
        j++;
    }
    result[k] = '\0';

    int start = 0, end = k - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char a[100], b[100], result[200];

    printf("Enter the first binary number: ");
    scanf("%s", a);
    printf("Enter the second binary number: ");
    scanf("%s", b);

    addBinary(a, b, result);

    printf("Sum of %s and %s is %s\n", a, b, result);

    return 0;
}