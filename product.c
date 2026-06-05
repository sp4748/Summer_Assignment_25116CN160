#include <stdio.h>

int main() {
    int num, temp;
    long long product = 1;
    printf("Enter any number: ");
    scanf("%d", &num);
    temp = num;
    if (num == 0) {
        product = 0;
    } else {
        if (num < 0) num = -num;

        while (num > 0) {
            product *= (num % 10);
            num /= 10;
        }
    }
    printf("Product of digits of %d = %lld\n", temp, product);
    return 0;
}
