#include <stdio.h>

int main() {
    int arr[] = {1, 3, 2, 1, 4, 1, 3, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    int maxFreq = 0;
    int maxElement = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 1;

        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > maxFreq) {
            maxFreq = count;
            maxElement = arr[i];
        }
    }

    printf("Maximum Frequency Element: %d\n", maxElement);
    printf("Frequency: %d\n", maxFreq);

    return 0;
}