#include <stdio.h>

struct Employee {
    int id;
    char name[50];
    float basicSalary, hra, da, deduction, netSalary;
};

struct Employee emp[100];
int count = 0;

void addEmployee() {
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp[count].id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp[count].name);

    printf("Enter Basic Salary: ");
    scanf("%f", &emp[count].basicSalary);

    printf("Enter HRA: ");
    scanf("%f", &emp[count].hra);

    printf("Enter DA: ");
    scanf("%f", &emp[count].da);

    printf("Enter Deduction: ");
    scanf("%f", &emp[count].deduction);

    emp[count].netSalary = emp[count].basicSalary + emp[count].hra +
                           emp[count].da - emp[count].deduction;

    count++;
    printf("Employee salary record added successfully!\n");
}

void displayEmployees() {
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------\n");
    printf("ID\tName\t\tBasic\tHRA\tDA\tDeduction\tNet Salary\n");
    printf("--------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t%.2f\t%.2f\t%.2f\t\t%.2f\n",
               emp[i].id,
               emp[i].name,
               emp[i].basicSalary,
               emp[i].hra,
               emp[i].da,
               emp[i].deduction,
               emp[i].netSalary);
    }
}

void searchEmployee() {
    int id, found = 0;

    printf("\nEnter Employee ID: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == id) {
            printf("\nEmployee Found\n");
            printf("ID : %d\n", emp[i].id);
            printf("Name : %s\n", emp[i].name);
            printf("Net Salary : %.2f\n", emp[i].netSalary);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Employee not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Salary Management System =====\n");
        printf("1. Add Employee Salary\n");
        printf("2. Display Salary Records\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try Again.\n");
        }

    } while (choice != 4);

    return 0;
}