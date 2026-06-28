#include <stdio.h>
#include <string.h>

struct BankAccount {
    int accNo;
    char name[50];
    float balance;
};

int main() {
    struct BankAccount acc;
    int choice;
    float amount;

    printf("=== Create Bank Account ===\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc.accNo);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", acc.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &acc.balance);

    do {
        printf("\n===== Bank Account Management System =====\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Display Account Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                acc.balance += amount;
                printf("Amount deposited successfully.\n");
                break;

            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if (amount <= acc.balance) {
                    acc.balance -= amount;
                    printf("Amount withdrawn successfully.\n");
                } else {
                    printf("Insufficient balance!\n");
                }
                break;

            case 3:
                printf("Current Balance: %.2f\n", acc.balance);
                break;

            case 4:
                printf("\nAccount Number : %d\n", acc.accNo);
                printf("Account Holder: %s\n", acc.name);
                printf("Balance       : %.2f\n", acc.balance);
                break;

            case 5:
                printf("Thank you for using the Bank Management System.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}