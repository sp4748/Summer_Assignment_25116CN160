#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contact {
    char name[50];
    char phone[15];
};

struct Contact contacts[MAX];
int count = 0;

void addContact() {
    printf("\nEnter Name: ");
    scanf(" %[^\n]", contacts[count].name);

    printf("Enter Phone Number: ");
    scanf("%s", contacts[count].phone);

    count++;
    printf("Contact added successfully!\n");
}

void displayContacts() {
    int i;

    if (count == 0) {
        printf("\nNo contacts available.\n");
        return;
    }

    printf("\nContact List:\n");
    printf("-------------------------------\n");

    for (i = 0; i < count; i++) {
        printf("%d. Name : %s\n", i + 1, contacts[i].name);
        printf("   Phone: %s\n", contacts[i].phone);
    }
}

void searchContact() {
    char searchName[50];
    int i;

    printf("\nEnter Name to Search: ");
    scanf(" %[^\n]", searchName);

    for (i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("\nContact Found!\n");
            printf("Name : %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            return;
        }
    }

    printf("Contact not found!\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Contact Management System =====\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;

            case 2:
                displayContacts();
                break;

            case 3:
                searchContact();
                break;

            case 4:
                printf("Thank you!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}