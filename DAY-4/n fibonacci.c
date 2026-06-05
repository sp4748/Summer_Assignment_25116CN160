#include <stdio.h>

int main() {
    int n, i;
    long long first = 0, second = 1, next;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n == 0)
        printf("The 0th Fibonacci term is %lld", first);
    else if (n == 1)
        printf("The 1st Fibonacci term is %lld", second);
    else {
        for (i = 2; i <= n; i++) {
            next = first + second;
            first = second;
            second = next;
        }
        printf("The %dth Fibonacci term is %lld", n, second);
    }

    return 0;
}