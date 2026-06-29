#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;
    double num1, num2, result;
    while (1) {
        
        printf("\n=== MENU DRIVEN CALCULATOR ===\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("==============================\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

       
        if (choice == 5) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        
        if (choice < 1 || choice > 5) {
            printf("Error: Invalid choice! Please select a valid option from the menu.\n");
            continue; // Skips the rest of the loop and re-displays the menu
        }

        
        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                
                if (num2 == 0) {
                    printf("Error: Division by zero is undefined!\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            default:
                printf("Error: Unexpected error occurred.\n");
                break;
        }
    }

    return 0;
}
