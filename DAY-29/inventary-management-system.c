#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.dat"

// Structure to define product attributes
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

// Function declarations
void addProduct();
void viewInventory();
void updateStock();
void searchProduct();

int main() {
    int choice;

    // Continuous loop for user interaction
    while (1) {
        printf("\n=== INVENTORY MANAGEMENT SYSTEM ===\n");
        printf("1. Add New Product\n");
        printf("2. View Current Inventory\n");
        printf("3. Update Product Stock\n");
        printf("4. Search for a Product\n");
        printf("5. Exit System\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Numeric choices only.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewInventory(); break;
            case 3: updateStock(); break;
            case 4: searchProduct(); break;
            case 5: printf("Exiting system. Data safely saved.\n"); exit(0);
            default: printf("Error: Choice out of range.\n");
        }
    }
    return 0;
}

// Function to add a brand new item to the file
void addProduct() {
    FILE *file = fopen(FILE_NAME, "ab"); // Append in binary mode
    if (file == NULL) {
        printf("Error: Data file could not be accessed.\n");
        return;
    }

    Product p;
    printf("\nEnter Unique Product ID (Integer): ");
    scanf("%d", &p.id);
    getchar(); // Consume remaining newline character

    printf("Enter Product Name: ");
    fgets(p.name, sizeof(p.name), stdin);
    p.name[strcspn(p.name, "\n")] = '\0'; // Strip trailing newline

    printf("Enter Stock Quantity: ");
    scanf("%d", &p.quantity);
    printf("Enter Base Unit Price: ");
    scanf("%f", &p.price);

    fwrite(&p, sizeof(Product), 1, file);
    fclose(file);
    printf("Product registered successfully.\n");
}

// Function to read and display all items
void viewInventory() {
    FILE *file = fopen(FILE_NAME, "rb"); // Read in binary mode
    if (file == NULL) {
        printf("\nNo data found. Inventory is currently empty.\n");
        return;
    }

    Product p;
    printf("\n%-10s %-25s %-12s %-10s\n", "ID", "Product Name", "Quantity", "Price");
    printf("------------------------------------------------------------\n");

    while (fread(&p, sizeof(Product), 1, file) == 1) {
        printf("%-10d %-25s %-12d $%-9.2f\n", p.id, p.name, p.quantity, p.price);
    }
    fclose(file);
}

// Function to find an item and modify its stock level
void updateStock() {
    FILE *file = fopen(FILE_NAME, "rb+"); // Read and write in binary mode
    if (file == NULL) {
        printf("Error: Inventory file is empty or missing.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter the Product ID to update: ");
    scanf("%d", &searchId);

    Product p;
    // Iterate through binary blocks to find match
    while (fread(&p, sizeof(Product), 1, file) == 1) {
        if (p.id == searchId) {
            printf("Current Quantity for %s: %d\n", p.name, p.quantity);
            printf("Enter New Stock Quantity: ");
            scanf("%d", &p.quantity);

            // Move file cursor backwards by one product size to overwrite
            fseek(file, -sizeof(Product), SEEK_CUR);
            fwrite(&p, sizeof(Product), 1, file);
            found = 1;
            printf("Stock level updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Product ID %d not found.\n", searchId);
    }
    fclose(file);
}

// Function to retrieve a single item's details
void searchProduct() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        printf("Error: System data file missing.\n");
        return;
    }

    int searchId, found = 0;
    printf("\nEnter Product ID to search: ");
    scanf("%d", &searchId);

    Product p;
    while (fread(&p, sizeof(Product), 1, file) == 1) {
        if (p.id == searchId) {
            printf("\n--- Match Found ---\n");
            printf("ID: %d\n", p.id);
            printf("Name: %s\n", p.name);
            printf("In-Stock: %d\n", p.quantity);
            printf("Price per Unit: $%.2f\n", p.price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product ID %d does not exist.\n", searchId);
    }
    fclose(file);
}
