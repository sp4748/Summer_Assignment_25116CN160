#include <stdio.h>
#include <string.h>
void remove_newline(char str[]) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main() {
    char str1[100], str2[100], result[200];
    int choice;

    do {
        printf("\n=================================");
        printf("\n      STRING OPERATIONS MENU     ");
        printf("\n=================================");
        printf("\n1. Find Length of a String");
        printf("\n2. Copy String");
        printf("\n3. Concatenate Two Strings");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        // Read user choice
        if (scanf("%d", &choice) != 1) {
            printf("Invalid numeric input. Exiting.\n");
            break;
        }
        
        
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("\nEnter a string: ");
                fgets(str1, sizeof(str1), stdin);
                remove_newline(str1);
                
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("\nEnter the source string: ");
                fgets(str1, sizeof(str1), stdin);
                remove_newline(str1);
                
                strcpy(str2, str1); // Copies str1 into str2
                printf("Successfully copied! Target String: \"%s\"\n", str2);
                break;

            case 3:
                printf("\nEnter first string: ");
                fgets(str1, sizeof(str1), stdin);
                remove_newline(str1);
                
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                remove_newline(str2);
                 
                strcpy(result, str1);
                strcat(result, str2); // Appends str2 to result
                printf("Concatenated String: \"%s\"\n", result);
                break;

            case 4:
                printf("\nEnter first string: ");
                fgets(str1, sizeof(str1), stdin);
                remove_newline(str1);
                
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                remove_newline(str2);
                
                int cmp = strcmp(str1, str2);
                if (cmp == 0) {
                    printf("Result: Both strings are perfectly equal.\n");
                } else if (cmp > 0) {
                    printf("Result: First string is lexicographically greater.\n");
                } else {
                    printf("Result: Second string is lexicographically greater.\n");
                }
                break;

            case 5:
                printf("\nEnter a string to reverse: ");
                fgets(str1, sizeof(str1), stdin);
                remove_newline(str1);
                
                int len = strlen(str1);
                printf("Reversed String: ");
                for (int i = len - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("\nExiting the system. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select a valid option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}
