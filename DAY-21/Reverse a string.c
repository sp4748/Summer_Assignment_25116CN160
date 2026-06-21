#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp;
    int i, len;

    printf("Enter a string: ");
    scanf("%99s", str);

    len = strlen(str);

    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}