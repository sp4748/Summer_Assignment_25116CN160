#include <stdio.h>

int armstrong(int num) {
    int original = num, sum = 0, rem;

    while (num != 0) {
        rem = num % 10;
        sum = sum + (rem * rem * rem);
        num = num / 10;
    }

    if (sum == original)
        return 1;
    else
        return 0;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (armstrong(num))
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}