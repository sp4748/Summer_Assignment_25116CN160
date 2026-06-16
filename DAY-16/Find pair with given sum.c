#include <stdio.h>

int main() {
    int arr[] = {1, 4, 5, 7, 3, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int found = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No pair found with sum %d\n", target);
    }

    return 0;
}