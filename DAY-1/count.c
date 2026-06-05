#include <stdio.h>

int main() {
    long long n;
    int count = 0;

    printf("Enter an integer: ");
    scanf("%lld", &n);

    // do-while loop ensures 0 is counted as 1 digit
    do {
        n /= 10;
        ++count;
    } while (n != 0);

    printf("Number of digits: %d\n", count);

    return 0;
}
