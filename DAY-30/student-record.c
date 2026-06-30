#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50


struct Student {
    int roll_no;
    char name[NAME_LENGTH];
    float marks;
};


void addStudent(struct Student students[], int *count);
void displayStudents(const struct Student students[], int count);
void searchStudent(const struct Student students[], int count);

int main() {
    struct Student database[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
       
        printf("\n=== STUDENT RECORD SYSTEM ===\n");
        printf("1. Add New Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(database, &studentCount);
                break;
            case 2:
                displayStudents(database, studentCount);
                break;
            case 3:
                searchStudent(database, studentCount);
                break;
            case 4:
                printf("Exiting system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose an option between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}


void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Database full! Cannot add more records.\n");
        return;
    }

    struct Student newStudent;
    int duplicate = 0;

    printf("\nEnter Roll Number: ");
    scanf("%d", &newStudent.roll_no);

    
    for (int i = 0; i < *count; i++) {
        if (students[i].roll_no == newStudent.roll_no) {
            duplicate = 1;
            break;
        }
    }

    if (duplicate) {
        printf("Error: A student with Roll Number %d already exists!\n", newStudent.roll_no);
        return;
    }

    printf("Enter Name: ");
    getchar(); 
    
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter Marks: ");
    scanf("%f", &newStudent.marks);

    // Commit new student to database and increment overall count
    students[*count] = newStudent;
    (*count)++;
    
    printf("Record added successfully!\n");
}

 
void displayStudents(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n-------------------------------------------------\n");
    printf("%-10s | %-25s | %-10s\n", "Roll No", "Name", "Marks");
    printf("-------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10d | %-25s | %-10.2f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
    printf("-------------------------------------------------\n");
}


void searchStudent(const struct Student students[], int count) {
    if (count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int searchRoll;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == searchRoll) {
            printf("\nRecord Found!");
            printf("\nRoll Number : %d", students[i].roll_no);
            printf("\nName        : %s", students[i].name);
            printf("\nMarks       : %.2f\n", students[i].marks);
            found = 1;
            break;
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", searchRoll);
    }
}
