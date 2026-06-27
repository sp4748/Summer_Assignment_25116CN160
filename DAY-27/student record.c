#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student s[100];
int count = 0;

// Add Student
void addStudent() {
    printf("\nEnter Roll Number: ");
    scanf("%d", &s[count].roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s[count].name);

    printf("Enter Marks: ");
    scanf("%f", &s[count].marks);

    count++;
    printf("Student record added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("---------------------------------\n");
    printf("Roll\tName\t\tMarks\n");
    printf("---------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
    }
}

void searchStudent() {
    int roll, found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            printf("\nRecord Found:\n");
            printf("Roll Number: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            printf("Marks: %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Student record not found.\n");
}

void deleteStudent() {
    int roll, found = 0;

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (s[i].roll == roll) {
            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            found = 1;
            printf("Record deleted successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Student record not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}