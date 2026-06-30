#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Define structure for book information
struct Book {
    int id;
    char title[100];
    char author[100];
    int isAvailable; // 1 = Available, 0 = Checked Out
};

// Global variables to manage library state
struct Book library[MAX_BOOKS];
int bookCount = 0;

// Function prototypes
void addBook();
void displayBooks();
void searchBook();
void checkOutBook();
void returnBook();

int main() {
    int choice;

    do {
        printf("\n=================================");
        printf("\n--- MINI LIBRARY SYSTEM MENU ---");
        printf("\n=================================");
        printf("\n1. Add a New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Check Out a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input! Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: checkOutBook(); break;
            case 5: returnBook(); break;
            case 6: printf("\nExiting system. Goodbye!\n"); break;
            default: printf("\nInvalid selection! Choose between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// 1. Add a new book to the library array
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("\nError: Library storage full!\n");
        return;
    }

    struct Book newBook;
    printf("\nEnter Unique Book ID (Integer): ");
    scanf("%d", &newBook.id);
    while (getchar() != '\n'); // Clear trailing newline character

    // Check if Book ID already exists
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == newBook.id) {
            printf("\nError: A book with ID %d already exists!\n", newBook.id);
            return;
        }
    }

    printf("Enter Book Title: ");
    scanf(" %[^\n]", newBook.title); // Reads entire line including spaces

    printf("Enter Author Name: ");
    scanf(" %[^\n]", newBook.author);

    newBook.isAvailable = 1; // Default status is available

    library[bookCount] = newBook;
    bookCount++;

    printf("\nSuccess: Book successfully added to the system!\n");
}

// 2. Display all books currently stored in memory
void displayBooks() {
    if (bookCount == 0) {
        printf("\nThe library inventory is currently empty.\n");
        return;
    }

    printf("\n%-10s %-30s %-25s %-15s\n", "Book ID", "Title", "Author", "Status");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%-10d %-30s %-25s %-15s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].isAvailable ? "Available" : "Checked Out");
    }
}

// 3. Search for a specific book record by its unique ID
void searchBook() {
    if (bookCount == 0) {
        printf("\nNo books available to search.\n");
        return;
    }

    int searchId;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == searchId) {
            printf("\n--- Book Found ---");
            printf("\nID: %d", library[i].id);
            printf("\nTitle: %s", library[i].title);
            printf("\nAuthor: %s", library[i].author);
            printf("\nStatus: %s\n", library[i].isAvailable ? "Available" : "Checked Out");
            return;
        }
    }
    printf("\nRecord not found: No book matches ID %d.\n", searchId);
}

// 4. Update status to checked out (Unavailable)
void checkOutBook() {
    int checkId;
    printf("\nEnter Book ID to check out: ");
    scanf("%d", &checkId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == checkId) {
            if (library[i].isAvailable == 1) {
                library[i].isAvailable = 0; // Mark as unavailable
                printf("\nSuccess: Book checked out successfully!\n");
            } else {
                printf("\nStatus: This book is already checked out by someone else.\n");
            }
            return;
        }
    }
    printf("\nRecord not found: No book matches ID %d.\n", checkId);
}

// 5. Update status back to Available
void returnBook() {
    int returnId;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &returnId);

    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == returnId) {
            if (library[i].isAvailable == 0) {
                library[i].isAvailable = 1; // Mark as available
                printf("\nSuccess: Book returned successfully!\n");
            } else {
                printf("\nStatus: This book was already in the library inventory.\n");
            }
            return;
        }
    }
    printf("\nRecord not found: No book matches ID %d.\n", returnId);
}
