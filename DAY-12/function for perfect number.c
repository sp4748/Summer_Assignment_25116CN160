#include <stdio.h>

int perfectNumber(int num) {
    int i, sum = 0;

    for(i = 1; i < num; i++) {
        if(num % i == 0) {
            sum += i;
        }
    }

    if(sum == num)
        return 1;
    else
        return 0;
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(perfectNumber(num))
        printf("%d is a Perfect Number.\n", num);
    else
        printf("%d is not a Perfect Number.\n", num);

    return 0;
}