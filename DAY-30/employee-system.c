#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Define the Employee structure
typedef struct {
    int id;
    char name[50];
    char designation[50];
    float salary;
} Employee;

// Global array and counter to manage records
Employee employees[MAX_EMPLOYEES];
int employeeCount = 0;

// Function Prototypes
void addEmployee();
void listEmployees();
void searchEmployee();
void modifyEmployee();
void deleteEmployee();
int findIndexById(int id);
void clearInputBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=================================");
        printf("\n    EMPLOYEE MANAGEMENT SYSTEM   ");
        printf("\n=================================");
        printf("\n1. Add Employee Record");
        printf("\n2. List All Employee Records");
        printf("\n3. Search Employee by ID");
        printf("\n4. Modify Employee Record");
        printf("\n5. Delete Employee Record");
        printf("\n6. Exit Program");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: listEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: modifyEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("\nInvalid choice! Please select between 1 and 6.\n");
        }
    }
    return 0;
}

// Function to safely clear trailing input characters
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Helper function to locate an employee index via ID
int findIndexById(int id) {
    for (int i = 0; i < employeeCount; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

// 1. Add Employee Record
void addEmployee() {
    if (employeeCount >= MAX_EMPLOYEES) {
        printf("\nDatabase Full! Cannot add more employees.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID sequence.\n");
        clearInputBuffer();
        return;
    }

    // Check for duplicate ID entries
    if (findIndexById(id) != -1) {
        printf("\nError: Employee ID %d already exists!\n", id);
        return;
    }

    employees[employeeCount].id = id;
    clearInputBuffer();

    printf("Enter Name: ");
    fgets(employees[employeeCount].name, sizeof(employees[employeeCount].name), stdin);
    employees[employeeCount].name[strcspn(employees[employeeCount].name, "\n")] = '\0'; // Remove newline

    printf("Enter Designation: ");
    fgets(employees[employeeCount].designation, sizeof(employees[employeeCount].designation), stdin);
    employees[employeeCount].designation[strcspn(employees[employeeCount].designation, "\n")] = '\0';

    printf("Enter Salary: ");
    if (scanf("%f", &employees[employeeCount].salary) != 1) {
        printf("Invalid Salary format.\n");
        clearInputBuffer();
        return;
    }

    employeeCount++;
    printf("\nRecord added successfully!\n");
}

// 2. List All Employee Records
void listEmployees() {
    if (employeeCount == 0) {
        printf("\nNo records found in the system.\n");
        return;
    }

    printf("\n-------------------------------------------------------------------");
    printf("\n%-10s %-25s %-20s %-10s", "ID", "Name", "Designation", "Salary");
    printf("\n-------------------------------------------------------------------");
    for (int i = 0; i < employeeCount; i++) {
        printf("\n%-10d %-25s %-20s $%-9.2f", 
               employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
    printf("\n-------------------------------------------------------------------\n");
}

// 3. Search Employee by ID
void searchEmployee() {
    int id;
    printf("\nEnter Employee ID to search: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        return;
    }

    int index = findIndexById(id);
    if (index == -1) {
        printf("\nEmployee record not found.\n");
        return;
    }

    printf("\n--- Record Found ---");
    printf("\nID:          %d", employees[index].id);
    printf("\nName:        %s", employees[index].name);
    printf("\nDesignation: %s", employees[index].designation);
    printf("\nSalary:      $%.2f\n", employees[index].salary);
}

// 4. Modify Employee Record
void modifyEmployee() {
    int id;
    printf("\nEnter Employee ID to modify: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        return;
    }

    int index = findIndexById(id);
    if (index == -1) {
        printf("\nEmployee record not found.\n");
        return;
    }

    clearInputBuffer();
    printf("\nEnter New Name (Current: %s): ", employees[index].name);
    fgets(employees[index].name, sizeof(employees[index].name), stdin);
    employees[index].name[strcspn(employees[index].name, "\n")] = '\0';

    printf("Enter New Designation (Current: %s): ", employees[index].designation);
    fgets(employees[index].designation, sizeof(employees[index].designation), stdin);
    employees[index].designation[strcspn(employees[index].designation, "\n")] = '\0';

    printf("Enter New Salary (Current: %.2f): ", employees[index].salary);
    if (scanf("%f", &employees[index].salary) != 1) {
        printf("Invalid input. Modification suspended.\n");
        clearInputBuffer();
        return;
    }

    printf("\nRecord updated successfully!\n");
}

// 5. Delete Employee Record
void deleteEmployee() {
    int id;
    printf("\nEnter Employee ID to delete: ");
    if (scanf("%d", &id) != 1) {
        clearInputBuffer();
        return;
    }

    int index = findIndexById(id);
    if (index == -1) {
        printf("\nEmployee record not found.\n");
        return;
    }

    // Shift subsequent items back to fill the empty slot
    for (int i = index; i < employeeCount - 1; i++) {
        employees[i] = employees[i + 1];
    }
    
    employeeCount--;
    printf("\nRecord deleted successfully!\n");
}
