#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define NAME_LENGTH 40
#define ROLL_LENGTH 15

// Function declarations
void displayMenu();
void addStudent(char names[][NAME_LENGTH], char rolls[][ROLL_LENGTH], int active[], int *count);
void displayStudents(char names[][NAME_LENGTH], char rolls[][ROLL_LENGTH], int active[], int count);
void searchStudent(char names[][NAME_LENGTH], char rolls[][ROLL_LENGTH], int active[], int count);
void deleteStudent(char rolls[][ROLL_LENGTH], int active[], int count);
void clearInputBuffer();

int main() {
    // 2D character arrays to store database entries
    char studentNames[MAX_STUDENTS][NAME_LENGTH];
    char rollNumbers[MAX_STUDENTS][ROLL_LENGTH];
    
    // 1D array acting as a boolean flag for deletion tracking
    int isActive[MAX_STUDENTS] = {0}; 
    int totalStudents = 0;
    int choice;

    printf("=== Welcome to the Student Management System ===\n");

    do {
        displayMenu();
        printf("Enter your choice (1-5): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid data type entered.\n");
            clearInputBuffer();
            choice = 0; 
            continue;
        }
        clearInputBuffer(); // Flush newline left behind by scanf

        switch (choice) {
            case 1:
                addStudent(studentNames, rollNumbers, isActive, &totalStudents);
                break;
            case 2:
                displayStudents(studentNames, rollNumbers, isActive, totalStudents);
                break;
            case 3:
                searchStudent(studentNames, rollNumbers, isActive, totalStudents);
                break;
            case 4:
                deleteStudent(rollNumbers, isActive, totalStudents);
                break;
            case 5:
                printf("\nExiting system safely. Goodbye!\n");
                break;
            default:
                printf("Error: Please choose a valid option from the menu.\n");
        }
    } while (choice != 5);

    return 0;
}

// Renders the options UI
void displayMenu() {
    printf("\n-------------------------------------\n");
    printf("1. Add New Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by Roll Number\n");
    printf("4. Delete Student Record\n");
    printf("5. Exit Application\n");
    printf("-------------------------------------\n");
}

// Appends data securely into arrays using bounded sizing
void addStudent(char names[][NAME_LENGTH], char rolls[][ROLL_LENGTH], int active[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error: System storage is full! Cannot add more students.\n");
        return;
    }

    printf("Enter Student Full Name: ");
    fgets(names[*count], NAME_LENGTH, stdin);
    // Remove newline character if appended by fgets
    names[*count][strcspn(names[*count], "\n")] = '\0';

    printf("Enter Unique Roll Number: ");
    fgets(rolls[*count], ROLL_LENGTH, stdin);
    rolls[*count][strcspn(rolls[*count], "\n")] = '\0';

    // Verify uniqueness
    for (int i = 0; i < *count; i++) {
        if (active[i] && strcmp(rolls[i], rolls[*count]) == 0) {
            printf("Error: A student with Roll Number '%s' already exists.\n", rolls[i]);
            return;
        }
    }

    active[*count] = 1; // Mark slot as active
    (*count)++;
    printf("Success: Record saved successfully!\n");
}

// Displays structural listing of data
void displayStudents(char names[][NAME_LENGTH], char rolls[][ROLL_LENGTH], int active[], int count) {
    int visibleCount = 0;
    
    printf("\n%-5s %-20s %-15s\n", "S.No", "Student Name", "Roll Number");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        if (active[i]) {
            visibleCount++;
            printf("%-5d %-20s %-15s\n", visibleCount, names[i], rolls[i]);
        }
    }

    if (visibleCount == 0) {
        printf("No records found in database.\n");
    }
}

// Performs sequential string lookup based on keys
void searchStudent(char names[][NAME_LENGTH], char rolls[][ROLL_LENGTH], int active[], int count) {
    char searchKey[ROLL_LENGTH];
    int found = 0;

    printf("Enter Roll Number to search: ");
    fgets(searchKey, ROLL_LENGTH, stdin);
    searchKey[strcspn(searchKey, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (active[i] && strcmp(rolls[i], searchKey) == 0) {
            printf("\n--- Match Found ---\n");
            printf("Name: %s\n", names[i]);
            printf("Roll Number: %s\n", rolls[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Notification: No student found matching Roll Number '%s'.\n", searchKey);
    }
}

// Simulates deletion cleanly by modifying active state array indexes
void deleteStudent(char rolls[][ROLL_LENGTH], int active[], int count) {
    char targetKey[ROLL_LENGTH];
    int found = 0;

    printf("Enter Roll Number to delete: ");
    fgets(targetKey, ROLL_LENGTH, stdin);
    targetKey[strcspn(targetKey, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (active[i] && strcmp(rolls[i], targetKey) == 0) {
            active[i] = 0; // Toggle flag to soft-delete
            printf("Success: Record for Roll Number '%s' removed.\n", targetKey);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: Record not found. Verification failed.\n");
    }
}

// Eliminates trailing inputs left in standard stream to avoid menu skips
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
