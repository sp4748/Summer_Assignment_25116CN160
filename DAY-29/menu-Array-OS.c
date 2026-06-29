#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function prototypes
void createArr(int arr[], int *s);
void displayArr(int arr[], int s);
void insertAt(int arr[], int *s);
void deleteAt(int arr[], int *s);
void linearSearch(int arr[], int s);

int main() {
    int arr[MAX_SIZE], size = 0, ch;
    while (1) {
        printf("\n1.Create, 2.Display, 3.Insert, 4.Delete, 5.Search, 6.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: createArr(arr, &size); break;
            case 2: displayArr(arr, size); break;
            case 3: insertAt(arr, &size); break;
            case 4: deleteAt(arr, &size); break;
            case 5: linearSearch(arr, size); break;
            case 6: exit(0);
            default: printf("Invalid!\n");
        }
    }
    return 0;
}

// Functions
void createArr(int arr[], int *s) {
    printf("Elements count: ");
    scanf("%d", s);
    for (int i = 0; i < *s; i++) scanf("%d", &arr[i]);
}

void displayArr(int arr[], int s) {
    for (int i = 0; i < s; i++) printf("%d ", arr[i]);
    printf("\n");
}

void insertAt(int arr[], int *s) {
    int p, v;
    printf("Enter index and value: ");
    scanf("%d %d", &p, &v);
    if(p < 0 || p > *s) return;
    for (int i = *s; i > p; i--) arr[i] = arr[i - 1];
    arr[p] = v;
    (*s)++;
}

void deleteAt(int arr[], int *s) {
    int p;
    printf("Enter index: ");
    scanf("%d", &p);
    if(p < 0 || p >= *s) return;
    for (int i = p; i < *s - 1; i++) arr[i] = arr[i + 1];
    (*s)--;
}

void linearSearch(int arr[], int s) {
    int key, found = 0;
    printf("Search key: ");
    scanf("%d", &key);
    for (int i = 0; i < s; i++) if (arr[i] == key) printf("Found at %d\n", i), found = 1;
    if (!found) printf("Not found\n");
}
