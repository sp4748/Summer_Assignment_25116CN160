#include <stdio.h>

int main() {
    long long num, largestPrimeFactor = -1;

    printf("Enter a number: ");
    scanf("%lld", &num);

    while (num % 2 == 0) {
        largestPrimeFactor = 2;
        num /= 2;
    }

    for (long long i = 3; i * i <= num; i += 2) {
        while (num % i == 0) {
            largestPrimeFactor = i;
            num /= i;
        }
    }

    if (num > 2)
        largestPrimeFactor = num;

    printf("Largest Prime Factor = %lld\n", largestPrimeFactor);

    return 0;
}